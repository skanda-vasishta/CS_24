#include "Index.h"

// Index Member Functions
Index::Index() {
    hashTable = new Node*[size];
    for (int i = 0; i < size; ++i) {
        hashTable[i] = nullptr;
    }
}

Index::~Index() {
    for (int i = 0; i < size; ++i) {
        if (hashTable[i] != nullptr) {
            delete hashTable[i];
        }
    }
}

void Index::insert(const std::string& key, Node* node) {
    int index = hashFunction(key);
    hashTable[index] = node;
}

void Index::remove(const std::string& key) {
    int index = hashFunction(key);
    hashTable[index] = nullptr;
}

Node* Index::lookup(const std::string& key) const {
    int index = hashFunction(key);
    return hashTable[index];
}

size_t Index::hashFunction(const std::string& key) const{
    std::hash<std::string> hasher;
    int sum = 0;
    for (char c : key) {
        sum += c;
    }
    return sum % size; 
}

 Node** Index::getHash(){
    return hashTable;
}