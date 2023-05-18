#include "Index.h"
#include "DataStore.h"

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
    int index = hashFunction(key);
    Node* newNode = new Node();
    newNode->key = key;
    newNode->value = value;
    if (hashTable[index] == nullptr) {
        hashTable[index] = newNode;
    } else {
        Node* currentNode = hashTable[index];
        while (currentNode->next_hash != nullptr) {
            currentNode = currentNode->next_hash;
        }
        currentNode->next_hash = newNode;
        newNode->prev = currentNode;
        } 
}

void Index::hash_remove(const std::string& key) {
    int index = hashFunction(key);
    Node* currentNode = hashTable[index];
    Node* prevNode = nullptr;

    while (currentNode != nullptr) {
        if (currentNode->key == key) {
            if (prevNode == nullptr) {
                hashTable[index] = currentNode->next_hash;
            } else {
                prevNode->next_hash = currentNode->next_hash;
            }
            if (currentNode->next_hash != nullptr) {
                currentNode->next_hash->prev = prevNode;
            }
            delete currentNode;
            return;
        }
        prevNode = currentNode; 
        currentNode = currentNode->next_hash;
    }
}

Node* Index::hash_lookup(const std::string& key) {
    int index = hashFunction(key);
    Node* currentNode = hashTable[index];

    while (currentNode != nullptr) {
        if (currentNode->key == key) {
            return currentNode;
        }
        currentNode = currentNode->next_hash;
    }

    return nullptr;
}
size_t Index::count() const {
  size_t count = 0;
  for (int i = 0; i < size; ++i) {
    Node* currentNode = hashTable[i];
    while (currentNode != nullptr) {
      count++;
      currentNode = currentNode->next_hash;
    }
  }
  return count;
}

int Index::total() const {
  int total = 0;
  for (int i = 0; i < size; ++i) {
    Node* currentNode = hashTable[i];
    while (currentNode != nullptr) {
      total += currentNode->value;
      currentNode = currentNode->next_hash;
    }
  }
  return total;
}
