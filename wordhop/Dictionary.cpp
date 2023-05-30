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
//  Dictionary::Dictionary(){

//  }

Dictionary* Dictionary::create(std::istream& stream){
    Dictionary* dictionary = new Dictionary();
    return dictionary;
 }

std::vector<std::string> Dictionary::hop(const std::string& from, const std::string& to){
    std::vector<std::string> hopvec(10);
    return hopvec;
}