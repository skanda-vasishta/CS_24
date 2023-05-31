#include "Dictionary.h"
 //yoo ok sick this actually works

 //light the beam 

//  Initialize an empty set to keep track of visited words in the chain.
// Start with the source word and add it to the visited set.
// Generate all possible valid next words by changing one letter in the current word.
// For each valid next word:
// If the next word is the destination word, you have found a valid chain. Stop and return the chain.
// If the next word has already been visited, skip it to avoid loops.
// Otherwise, add the next word to the visited set and recursively continue the chain-building process from the next word.
// If no valid chain is found after exploring all possible next words, throw a NoChain exception.


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
            if (newWords.find(mWord) == newWords.end()){
                newWords.insert(mWord);
            }
        }
    }

    return newWords;
}


std::vector<std::string> Dictionary::hop(
  const std::string& from, const std::string& to) {
    if (from.length() != to.length()) {
        throw NoChain();
    }
    if (from == to) {
        std::vector<std::string> chain;
        chain.push_back(from);
        return chain;
    }

    std::unordered_set<std::string> visitedFrom; // Visited set for forward search
    std::unordered_set<std::string> visitedTo; // Visited set for backward search
    std::unordered_map<std::string, std::string> prevFrom; // Previous word map for forward search
    std::unordered_map<std::string, std::string> prevTo; // Previous word map for backward search

    std::queue<std::string> queueFrom; // Queue for forward search
    std::queue<std::string> queueTo; // Queue for backward search

    queueFrom.push(from);
    queueTo.push(to);

    visitedFrom.insert(from);
    visitedTo.insert(to);

    std::string meetingWord = "";

    while (!queueFrom.empty() && !queueTo.empty()) {
        // Forward search
        std::string currentWordFrom = queueFrom.front();
        queueFrom.pop();

        const std::unordered_set<std::string>& validWordsFrom = validwords(currentWordFrom);

        for (const std::string& word : validWordsFrom) {
            if (visitedTo.find(word) != visitedTo.end()) {
                meetingWord = word;
                prevFrom[word] = currentWordFrom;
                break;
            }

            if (visitedFrom.find(word) == visitedFrom.end()) {
                queueFrom.push(word);
                visitedFrom.insert(word);
                prevFrom[word] = currentWordFrom;
            }
        }

        if (!meetingWord.empty()) {
            break;
        }

        // Backward search
        std::string currentWordTo = queueTo.front();
        queueTo.pop();

        const std::unordered_set<std::string>& validWordsTo = validwords(currentWordTo);

        for (const std::string& word : validWordsTo) {
            if (visitedFrom.find(word) != visitedFrom.end()) {
                meetingWord = word;
                prevTo[word] = currentWordTo;
                break;
            }

            if (visitedTo.find(word) == visitedTo.end()) {
                queueTo.push(word);
                visitedTo.insert(word);
                prevTo[word] = currentWordTo;
            }
        }

        if (!meetingWord.empty()) {
            break;
        }
    }

    if (!meetingWord.empty()) {
        std::vector<std::string> wordChainFrom;
        std::string word = meetingWord;

        while (!word.empty()) {
            wordChainFrom.push_back(word);
            word = prevFrom[word];
        }

        std::reverse(wordChainFrom.begin(), wordChainFrom.end());

        std::vector<std::string> wordChainTo;
        word = meetingWord;

        while (prevTo[word] != to) {
            word = prevTo[word];
            wordChainTo.push_back(word);
        }

        std::reverse(wordChainTo.begin(), wordChainTo.end());

        wordChainFrom.insert(wordChainFrom.end(), wordChainTo.begin(), wordChainTo.end());
        return wordChainFrom;
    }

    throw NoChain();
}
