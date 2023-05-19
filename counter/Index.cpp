#include "Index.h"
#include "DataStore.h"

// Index Member Functions
Index::Index() {
    size = 100001;
    hashTable = new Node*[size];
    for (int i = 0; i < size; ++i) {
        hashTable[i] = nullptr;
    }
}

Index::~Index() {
  /*for (int i = 0; i < size; ++i) {
    Node* node = hashTable[i];
    while (node != nullptr) {
      Node* buck = node->buck;
      delete node;
      node = buck;
    }
  }*/
  delete[] hashTable;
}

size_t Index::hashFunction(const std::string& key){
    const size_t prime = 31;  
    size_t hashValue = 0;
    for (char c : key) {
        hashValue = (hashValue * prime) + c;
    }
    return hashValue % size; 
}

Node** Index::getHash(){
    return hashTable;   
}

void Index::hash_insert(const std::string& key, int value){
    size_t index = hashFunction(key);
    Node* newNode = new Node();
    newNode->key = key;
    newNode->value = value;
    if (hashTable[index] == nullptr) {
        hashTable[index] = newNode;
    } else {
        Node* currentNode = hashTable[index];
        while (currentNode->buck != nullptr) {
            currentNode = currentNode->buck;
        }
        currentNode->buck = newNode;
        newNode->prev = currentNode;
        newNode->buck = nullptr;
        } 
}

void Index::hash_remove(const std::string& key) {
    size_t index = hashFunction(key);
    Node* currentNode = hashTable[index];

    if (currentNode != nullptr && currentNode->key == key) {
        hashTable[index] = currentNode->buck;
        Node* travel = currentNode->buck;
        while(travel && hashFunction(travel->key) != index){
            travel = travel->buck;
        }
        hashTable[index] = travel;
        delete currentNode;
        currentNode = nullptr;
        return;
    }
}

Node* Index::hash_lookup(const std::string& key) {
    size_t index = hashFunction(key);
    Node* currentNode = hashTable[index];

    while (currentNode != nullptr) {
        if (currentNode->key == key) {
            return currentNode;
        }
        currentNode = currentNode->buck;
    }

    return nullptr;
}
/*int Index::total()  {
  int count = 0;
  for (int i = 0; i < size; ++i) {
    Node* currentNode = hashTable[i];
    while (currentNode != nullptr) {
      count+=currentNode->value;
      currentNode = currentNode->buck;
    }
  }
  return count;
}*/


