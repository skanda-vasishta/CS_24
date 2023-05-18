
#include "Counter.h"
#include "DataStore.h"


// Counter::Iterator Member Functions
//lol
Counter::Iterator::Iterator( Node* node){
    this->node = node;

}
const std::string& Counter::Iterator::key() const{
    return this->node->key;

}
int Counter::Iterator::value() const{
    return this->node->value;
}

 Counter::Iterator& Counter::Iterator::operator ++ (){
    this->node = this->node->next;
    return *this;
 }
 bool      Counter::Iterator::operator == (const Iterator& other) const{
    return this->node == other.node;
 }
bool      Counter::Iterator::operator != (const Iterator& other) const{
    return this->node != other.node;
}