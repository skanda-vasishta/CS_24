
#include "DataStore.h"
#include "Index.h"


// DataStore Member Functions
 // function for inserting at end of linked list

DataStore::DataStore(){
    head = nullptr;
    tail = nullptr;
    table = new Index();

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
    /*struct Node* pushNode = new Node;
    pushNode->key = key;
    pushNode->value = value;

    struct Node* temp = head;
    if (head == nullptr){
        pushNode->prev = nullptr;
        head = pushNode;
        return;
    }

    while (temp->next != nullptr){
        temp = temp->next;
    }
    temp->next = pushNode;
    pushNode->prev = temp;*/
    table->hash_insert(key, value);
}
void DataStore::remove(const std::string& key){
    struct Node* current = lookup(key);
    if (current != nullptr) {
        if (current->prev != nullptr) {
            current->prev->next = current->next;
        } else {
            head = current->next;
            if (head != nullptr) {
                head->prev = nullptr;
            }
        }

        if (current->next != nullptr) {
            current->next->prev = current->prev;
        }

        delete current;
    }
    table->hash_remove(key);

}
 Node* DataStore::lookup(const std::string& key) const{
    /*struct Node* look = head;
    while (look!=nullptr){
        if (look->key == key){
            return look;
        }
        look = look->next;
    }

    return nullptr;*/
    return table->hash_lookup(key);

 }

 Node* DataStore::returnHead() const{
    return this->head;
 }

 size_t DataStore::count() const {
  return table->count();
}

int DataStore::total() const {
  return table->count();
}
