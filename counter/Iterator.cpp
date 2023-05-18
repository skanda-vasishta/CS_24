
#include "Counter.h"
#include "DataStore.h"


// Counter::Iterator Member Functions
//lol
Counter::Iterator::Iterator( Node* node){
    this->node = node;

}
const std::string& Counter::Iterator::key() const{
    if (this->node != nullptr) {
        return this->node->key;
    } else {
        return nullptr;
    }

}
int Counter::Iterator::value() const{
    if (this->node != nullptr) {
        return this->node->value;
    } else {
        return 0;
    }

}

 Counter::Iterator& Counter::Iterator::operator ++ (){
    if (this->node != nullptr) {
        this->node = this->node->next;
    }
    return *this;
 }
 bool      Counter::Iterator::operator == (const Iterator& other) const{
    return this->node == other.node;
 }
bool      Counter::Iterator::operator != (const Iterator& other) const{
    return this->node != other.node;
}