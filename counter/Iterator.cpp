
#include "Counter.h"
#include "DataStore.h"


// Counter::Iterator Member Functions
//lol
Counter::Iterator::Iterator( Node* node){
    currentNode = node;

}
const std::string& Counter::Iterator::key() const{
    return currentNode->key;

}
int Counter::Iterator::value() const{
    return currentNode->value;
}

 Counter::Iterator& Counter::Iterator::operator ++ (){
    if (currentNode) {
        currentNode = currentNode->next;
    }
    //currentNode = currentNode->next;
    return *this;
 }
 bool      Counter::Iterator::operator == (const Iterator& other) const{
    return currentNode == other.currentNode;
 }
bool      Counter::Iterator::operator != (const Iterator& other) const{
    return currentNode != other.currentNode;
}