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
  /*for (int i = 0; i < size; ++i) {
    Node* node = hashTable[i];
    while (node != nullptr) {
      Node* next = node->next;
      delete node;
      node = next;
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
        newNode->next = nullptr;
        } 
}

void Index::hash_remove(const std::string& key) {
    int index = hashFunction(key);
    Node* currentNode = hashTable[index];

    if (currentNode != nullptr && currentNode->key == key) {
        hashTable[index] = currentNode->next;
        if (currentNode->next != nullptr) {
            currentNode->next->prev = nullptr;
        }
        //delete currentNode;
        return;
    }

    while (currentNode != nullptr) {
        if (currentNode->key == key) {
            if (currentNode->prev != nullptr) {
                currentNode->prev->next = currentNode->next;
            }
            if (currentNode->next != nullptr) {
                currentNode->next->prev = currentNode->prev;
            }
            if (currentNode->next == nullptr && currentNode->prev != nullptr) {
                currentNode->prev->next = nullptr;
            }
            //delete currentNode;
            return;
        }
        currentNode = currentNode->next;
    }
}

Node* Index::hash_lookup(const std::string& key) {
    int index = hashFunction(key);
    Node* currentNode = hashTable[index];

    while (currentNode != nullptr) {
        if (currentNode->key == key) {
            return currentNode;
        }
        currentNode = currentNode->next;
    }

    return nullptr;
}
/*int Index::total()  {
  int count = 0;
  for (int i = 0; i < size; ++i) {
    Node* currentNode = hashTable[i];
    while (currentNode != nullptr) {
      count+=currentNode->value;
      currentNode = currentNode->next;
    }
  }
  return count;
}*/


