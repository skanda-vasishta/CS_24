#include "Heap.h"
#include <iostream>

Heap::Heap(size_t capacity){
    mData = new Entry;
    mCapacity = capacity;
}

Heap::Heap(const Heap& other){

}

Heap::Heap(Heap&& other){

}

Heap::~Heap(){

}

size_t Heap::capacity() const{
    return 1;
}

size_t Heap::count() const{
    return 1;
}

const Heap::Entry& Heap::lookup(size_t index) const{
    return *mData;
}

Heap::Entry Heap::pop(){
    return *mData;
}

Heap::Entry Heap::pushpop(const std::string& value, float score){
    return *mData;
}

void Heap::push(const std::string& value, float score){

}

const Heap::Entry& Heap::top() const{
    return *mData;
}