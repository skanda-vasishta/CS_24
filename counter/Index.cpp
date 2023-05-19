#include "Index.h"
#include "DataStore.h"

// Index Member Functions
Index::Index() {
    hashTable = new Node*[size];
    statusArray = new int[size]; 
    for (int i = 0; i < size; ++i) {
        hashTable[i] = nullptr;
        statusArray[i] = 0; 
    }
}


Index::~Index() {
    for (int i = 0; i < size; ++i) {
        if (hashTable[i] != nullptr) {
            delete hashTable[i];
        }
    }
    delete[] hashTable;
    delete[] statusArray; 
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

void Index::hash_insert(const std::string& key, int value) {
    int index = hashFunction(key);
    int startIndex = index;
    int deletedIndex = -1; 
    while (hashTable[index] != nullptr && statusArray[index] != 0) {
        if (statusArray[index] != -1 && hashTable[index]->key == key) {
            hashTable[index]->value = value;
            return;
        }
        if (statusArray[index] == -1 && deletedIndex == -1) {
            deletedIndex = index; 
        }
        index = (index + 1) % size; 
        if (index == startIndex) {
            if (deletedIndex != -1) {
                index = deletedIndex; 
                break;
            }
            return;
        }
    }
    Node* newNode = new Node();
    newNode->key = key;
    newNode->value = value;
    hashTable[index] = newNode;
    statusArray[index] = 1;
}

void Index::hash_remove(const std::string& key) {
    int index = hashFunction(key);
    int startIndex = index;
    while (hashTable[index] != nullptr) {
        if (statusArray[index] != -1 && hashTable[index]->key == key) {
            delete hashTable[index];
            hashTable[index] = nullptr;
            statusArray[index] = -1;
            int nextIndex = (index + 1) % size;
            while (statusArray[nextIndex] == -1) {
                statusArray[nextIndex] = 0; 
                nextIndex = (nextIndex + 1) % size;
            }
            return;
        }
        index = (index + 1) % size; 
        if (index == startIndex) {
            return;
        }
    }
}


Node* Index::hash_lookup(const std::string& key) {
    size_t index = hashFunction(key);
    size_t startIndex = index; 

    while (hashTable[index] != nullptr) {
        if (hashTable[index]->key == key && statusArray[index] == 1) {
            return hashTable[index]; 
        }
        index = (index + 1) % size; 
        if (index == startIndex) {
            break;
        }
    }

    return nullptr; 
}

size_t Index::count() {
    size_t count = 0;
    for (int i = 0; i < size; ++i) {
        if (hashTable[i] != nullptr && statusArray[i] == 1) {
            count++;
        }
    }
    return count;
}

int Index::total() {
    int total = 0;
    for (int i = 0; i < size; ++i) {
        if (hashTable[i] != nullptr && statusArray[i] == 1) {
            total += hashTable[i]->value;
        }
    }
    return total;
}
