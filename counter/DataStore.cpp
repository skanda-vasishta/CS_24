
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
}
void DataStore::remove(const std::string& key){
    table->hash_remove(key);

}
 Node* DataStore::lookup(const std::string& key) const{
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
