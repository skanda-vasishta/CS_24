#include "Dictionary.h"


Dictionary::Dictionary(std::istream& stream) {
  std::string line;
  while (std::getline(stream, line)) {
    
    bool isValidLine = true;
    
    if (line.empty()){
        isValidLine = false;
    }
    else {
      for (char c : line) {
        if (!std::islower(c)) {
          isValidLine = false; 
          break;
        }
      }
    }
    if (isValidLine) {
      words_.insert(line);
    }
    }
  }



Dictionary* Dictionary::create(std::istream& stream){
    Dictionary* dictionary = new Dictionary(stream);
    return dictionary;
 }

std::unordered_set<std::string> Dictionary::validwords(const std::string& word){
    std::unordered_set<std::string> newWords;
    int wordlength = word.length();
    for (int i = 0; i < wordlength; i++){
        std::string mWord = word;

        for (char l = 'a'; l <= 'z'; l++){
            if (mWord[i] == l){
                continue;
            }
            mWord[i] = l;
            if (newWords.find(mWord) == newWords.end() && words_.find(mWord) == words_.end()){
                newWords.insert(mWord);
            }
        }
    }

    return newWords;
}

std::vector<std::string> Dictionary::hop(const std::string& from, const std::string& to){

    if (from.length() != to.length()) {
        throw NoChain();
        }
    if (from == to){
      std::vector<std::string> chain;
      chain.push_back(from);
      // chain.push_back(to);
      return chain;
    }

    std::queue<std::string>wordQueue;
    wordQueue.push(from);

    std::unordered_map<std::string, std::string> prevWordMap;
    prevWordMap[from] = "";

    std::unordered_map<std::string, std::unordered_set<std::string>> validWordsMap;

    while (!wordQueue.empty()) {
        std::string currentWord = wordQueue.front();
        wordQueue.pop();

        if (validWordsMap.find(currentWord) == validWordsMap.end()) {
            validWordsMap[currentWord] = validwords(currentWord);
        }
        const std::unordered_set<std::string>& validWords = validWordsMap[currentWord];

        for (const std::string& word : validWords) {
            if (word == to) {
                std::vector<std::string> wordChain;
                wordChain.push_back(to);

                std::string prevWord = currentWord;
                while (!prevWord.empty()) {
                    wordChain.push_back(prevWord);
                    prevWord = prevWordMap[prevWord];
                }

                std::reverse(wordChain.begin(), wordChain.end());
                return wordChain;
            }

            if (prevWordMap.find(word) == prevWordMap.end()) {
                wordQueue.push(word);
                prevWordMap[word] = currentWord;
            }
        }
    }

    throw NoChain();


}