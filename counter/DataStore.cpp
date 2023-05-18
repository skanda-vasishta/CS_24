#include "DataStore.h"

// DataStore Member Functions
 // function for inserting at end of linked list

DataStore::DataStore(){
    head = nullptr;
    tail = nullptr;
    idx = new Index();
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
    pushNode->next = nullptr;

    size_t index = idx->hashFunction(key);
    struct Node* headNode = idx->getHash()[index];

    if (headNode == nullptr) {
        pushNode->prev = nullptr;
        idx->getHash()[index] = pushNode;
    } else {
        struct Node* temp = headNode;
        while (temp->next != nullptr) {
            temp = temp->next;
        }
        temp->next = pushNode;
        pushNode->prev = temp;
    }

}

void DataStore::remove(const std::string& key){
    size_t index = idx->hashFunction(key);
    struct Node* current = idx->getHash()[index];

    if (current != nullptr && current->key == key) {
        idx->getHash()[index] = current->next;
        if (current->next != nullptr) {
            current->next->prev = nullptr;
        }
        delete current;
        return;
    }

    while (current != nullptr) {
        if (current->key == key) {
            if (current->prev != nullptr) {
                current->prev->next = current->next;
            }
            if (current->next != nullptr) {
                current->next->prev = current->prev;
            }
            delete current;
            return;
        }
        current = current->next;
    }
}

 Node* DataStore::lookup(const std::string& key) const{
    size_t index = idx->hashFunction(key);
    struct Node* look = idx->getHash()[index];
    while (look!=nullptr){
        if (look->key == key){
            return look;
        }
        look = look->next;
    }

    return nullptr;

 }

 Node* DataStore::returnHead() const{
    return this->head;
 }
 