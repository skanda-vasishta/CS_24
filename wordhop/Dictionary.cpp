#include "Dictionary.h"

Dictionary::Dictionary(std::istream& stream) {
  std::string line;
  while (std::getline(stream, line)) {
    if (!line.empty() && std::all_of(line.begin(), line.end(), ::islower)) {
      words_.insert(new std::string(line));
    }
  }
}

Dictionary* Dictionary::create(std::istream& stream) {
  Dictionary* dictionary = new Dictionary(stream);
  return dictionary;
}

std::unordered_set<const std::string*> Dictionary::validwords(const std::string* word) {
  std::unordered_set<const std::string*> newWords;
  int wordLength = word->length();

  for (int i = 0; i < wordLength; i++) {
    std::string mWord = *word;

    for (char l = 'a'; l <= 'z'; l++) {
      if (mWord[i] != l) {
        mWord[i] = l;
        newWords.insert(&(*words_.insert(new std::string(mWord)).first));
      }
    }
  }

  return newWords;
}

std::vector<std::string> Dictionary::hop(const std::string* from, const std::string* to) {
  if (from->length() != to->length()) {
    throw NoChain();
  }
  if (*from == *to) {
    return std::vector<std::string>{*from};
  }

  std::queue<const std::string*> wordQueueFrom;
  std::queue<const std::string*> wordQueueTo;
  std::unordered_map<const std::string*, const std::string*> prevWordMapFrom;
  std::unordered_map<const std::string*, const std::string*> prevWordMapTo;

  wordQueueFrom.push(from);
  wordQueueTo.push(to);
  prevWordMapFrom[from] = nullptr;
  prevWordMapTo[to] = nullptr;

  while (!wordQueueFrom.empty() && !wordQueueTo.empty()) {
    const std::string* currentWordFrom = wordQueueFrom.front();
    wordQueueFrom.pop();

    const std::string* currentWordTo = wordQueueTo.front();
    wordQueueTo.pop();

    const std::unordered_set<const std::string*>& validWordsFrom = validwords(currentWordFrom);
    const std::unordered_set<const std::string*>& validWordsTo = validwords(currentWordTo);

    for (const std::string* word : validWordsFrom) {
      if (validWordsTo.find(word) != validWordsTo.end()) {
        std::vector<std::string> wordChainFrom;
        std::vector<std::string> wordChainTo;

        std::string chainWord = *word;

        while (prevWordMapFrom[chainWord] != nullptr) {
          wordChainFrom.push_back(chainWord);
          chainWord = *prevWordMapFrom[chainWord];
        }

        wordChainFrom.push_back(chainWord);
        std::reverse(wordChainFrom.begin(), wordChainFrom.end());

        chainWord = *word;

        while (prevWordMapTo[chainWord] != nullptr) {
          chainWord = *prevWordMapTo[chainWord];
          wordChainTo.push_back(chainWord);
        }

        wordChainFrom.insert(wordChainFrom.end(), wordChainTo.begin(), wordChainTo.end());
        return wordChainFrom;
      }

      if (prevWordMapFrom.find(word) == prevWordMapFrom.end()) {
        wordQueueFrom.push(word);
        prevWordMapFrom[word] = currentWordFrom;
      }
    }

    for (const std::string* word : validWordsTo) {
      if (prevWordMapTo.find(word) == prevWordMapTo.end()) {
        wordQueueTo.push(word);
        prevWordMapTo[word] = currentWordTo;
      }
    }
  }

  throw NoChain();
}

Dictionary::~Dictionary() {
  for (const std::string* word : words_) {
    delete word;
  }
  words_.clear();
}