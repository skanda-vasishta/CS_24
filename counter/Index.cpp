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
    Node* node = hashTable[i];
    while (node != nullptr) {
      Node* next = node->next;
      delete node;
      node = next;
    }
  }
  delete[] hashTable;
}

size_t Index::hashFunction(const std::string& key){
    std::hash<std::string> hasher;
    return hasher(key); 
}

 Node** Index::getHash(){
    return hashTable;
}