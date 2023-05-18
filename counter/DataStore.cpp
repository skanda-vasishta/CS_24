
#include "DataStore.h"

// DataStore Member Functions
 // function for inserting at end of linked list

DataStore::DataStore(){
    head = nullptr;
    tail = nullptr;
    tableSize = 10000;
    hashTable = new Node*[tableSize];
    for (int i = 0; i < tableSize; i++) {
        hashTable[i] = nullptr;
    }
    //count = 0;
}

DataStore::~DataStore() {
    Node* current = head;
    while (current != nullptr) {
        Node* next = current->next;
        delete current;
        current = next;
    }
    head = nullptr;
    tail = nullptr;
    //count = 0;
}

void DataStore::push_back(const std::string& key, int value){
    struct Node* pushNode = new Node;
    pushNode->key = key;
    pushNode->value = value;

    int index = hashFunction(key);

    if (hashTable[index] == nullptr) {
        hashTable[index] = pushNode;
    } else {
        struct Node* temp = hashTable[index];
        while (temp->next != nullptr) {
            temp = temp->next;
        }
        temp->next = pushNode;
        pushNode->prev = temp;
    }

    if (head == nullptr) {
        head = pushNode;
    }

    tail = pushNode;

}
void DataStore::remove(const std::string& key){
    int index = hashFunction(key);
    struct Node* current = hashTable[index];

    while (current != nullptr) {
        if (current->key == key) {
            if (current->prev != nullptr) {
                current->prev->next = current->next;
            } else {
                hashTable[index] = current->next;
            }

            if (current->next != nullptr) {
                current->next->prev = current->prev;
            }

            delete current;
            break;
        }

        current = current->next;
    }

}
 Node* DataStore::lookup(const std::string& key) const{
    int index = hashFunction(key);
    struct Node* current = hashTable[index];

    while (current != nullptr) {
        if (current->key == key) {
            return current;
        }

        current = current->next;
    }

    return nullptr;

 }

 Node* DataStore::returnHead() const{
    return this->head;
 }

 int DataStore::hashFunction(const std::string& key) const {
    int sum = 0;
    for (char c : key) {
        sum += static_cast<int>(c);
    }
    return sum % tableSize;
}