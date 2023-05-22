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

}

Heap::Heap(Heap&& other){

}

Heap::~Heap(){
    delete[] mData;   
}

size_t Heap::capacity() const{
    return mCapacity;
}

size_t Heap::count() const{
    return mCount;
}

const Heap::Entry& Heap::lookup(size_t index) const{
    if (index>=mCount){
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
    if (mCount == mCapacity){
        throw std::overflow_error("No space for pushing item");
    }
    mCount++;
    size_t idx = mCount-1;
    mData[idx].value = value;
    mData[idx].score = score;

    while (mData[idx].score != 0 && mData[(idx-1)/2].score > mData[idx].score){
        size_t temp = mData[idx].score;
        mData[idx].score = mData[(idx-1)/2].score;
        mData[(idx-1)/2].score = temp;
        idx = (idx-1)/2;
    }
}

const Heap::Entry& Heap::top() const{
    if (mCount == 0){
        throw std::underflow_error("empty heap");
    } else {
        return mData[0];
    }
}