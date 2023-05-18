

#include "DataStore.h"

// DataStore Member Functions
 // function for inserting at end of linked list

DataStore::DataStore(){
    head = nullptr;
    tail = nullptr;
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
    Node* newNode = new Node;
    newNode->key = key;
    newNode->value = value;

    if (head == nullptr) {
        head = newNode;
        tail = newNode;
    } else {
        newNode->prev = tail;
        tail->next = newNode;
        tail = newNode;
    }

    index.insert(key, newNode);

}
void DataStore::remove(const std::string& key){
    Node* node = index.lookup(key);
    if (node != nullptr) {
        if (node->prev != nullptr) {
            node->prev->next = node->next;
        } else {
            head = node->next;
            if (head != nullptr) {
                head->prev = nullptr;
            }
        }

        if (node->next != nullptr) {
            node->next->prev = node->prev;
        }

        index.remove(key);
        delete node;
    } 

}
 Node* DataStore::lookup(const std::string& key) const{
    return index.lookup(key);

 }

 Node* DataStore::returnHead() const{
    return this->head;
 }