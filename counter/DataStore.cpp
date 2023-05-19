
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
    delete table;
    //count = 0;
}

void DataStore::push_back(const std::string& key, int value){
    table->hash_insert(key, value);
    if(head == NULL){
        head = table->hash_lookup(key);
        tail = head;
    }
    else{
        tail->next = table->hash_lookup(key);
        table->hash_lookup(key)->prev = tail;
        tail = tail->next;
        tail->next = NULL;
    }
}
void DataStore::remove(const std::string& key) {
    Node* nodeToRemove = table->hash_lookup(key);

    if (nodeToRemove == head && nodeToRemove == tail){
        head = nullptr;
        tail = nullptr;
    }
    else if (nodeToRemove == head) {
        head = nodeToRemove->next;
    }

    else if (nodeToRemove == tail) {
        tail = nodeToRemove->prev;
    }
    else {
        nodeToRemove->prev->next = nodeToRemove->next;
        nodeToRemove->next->prev = nodeToRemove->prev;
    }

    table->hash_remove(key);
}

 Node* DataStore::lookup(const std::string& key) const{
    return table->hash_lookup(key);

 }

 Node* DataStore::returnHead() const{
    return this->head;
 }
 Node* DataStore::returnTail() const{
    return this->tail;
 }

 size_t DataStore::count() const {
    Node* start = head;
    size_t answer = 0;
    while(start != NULL){
        answer++;
        start = start->next;
    }
    return answer;
}

/*int DataStore::total() const {
  return table->total();
}*/
