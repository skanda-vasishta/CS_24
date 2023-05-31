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

    for (int i = 0; i < word.length(); i++){
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

std::vector<std::string> Dictionary::hop(const std::string& from, const std::string& to){

    if (from.length() != to.length()) {
        throw NoChain();
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



    
    
    
    // std::vector<std::string> hopvec(10);
    // return hopvec;
}