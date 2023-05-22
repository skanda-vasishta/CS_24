#include "Heap.h"
#include <iostream>

Heap::Heap(size_t capacity){
    mCapacity = capacity;
    mCount = 0;
    mData = new Entry[capacity];

}

//  Heap::Entry* copy_helper(const Heap& other){

//  }
Heap::Heap(const Heap& other){ 
    mData = other.mData; 
}

Heap::Heap(Heap&& other){

}

Heap::~Heap(){
    delete[] mData;   
}

size_t Heap::capacity() const{
    return mCapacity;
    \
}

size_t Heap::count() const{
    return mCount;
}

const Heap::Entry& Heap::lookup(size_t index) const{
    if (index>mCapacity){
        throw std::out_of_range("index is out of range");
    } else {
        return mData[index];
    }
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