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
    std::hash<std::string> hasher;
    return hasher(key); 
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
        while (currentNode->next != nullptr) {
            currentNode = currentNode->next;
        }
        currentNode->next = newNode;
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
                hashTable[index] = currentNode->next;
            } else {
                prevNode->next = currentNode->next;
            }
            if (currentNode->next != nullptr) {
                currentNode->next->prev = prevNode;
            }
            delete currentNode;
            return;
        }
        prevNode = currentNode;
        currentNode = currentNode->next;
    }
}

/*Node* Index::hash_lookup(const std::string& key) {
    int index = hashFunction(key);
    Node* currentNode = hashTable[index];

    while (currentNode != nullptr) {
        if (currentNode->key == key) {
            return currentNode;
        }
        currentNode = currentNode->next;
    }

    return nullptr;
}*/
