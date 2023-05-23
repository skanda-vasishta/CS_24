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
    mData = new Entry[other.mCapacity];
     for (size_t i = 0; i < other.mCount; i++){
        mData[i] = other.mData[i];
    }
    mCapacity = other.mCapacity;
    mCount = other.mCount;

}

Heap::Heap(Heap&& other){
    mData = other.mData;
    mCapacity = other.mCapacity;
    mCount = other.mCount;
    other.mData = nullptr;
    other.mCapacity = 0;
    other.mCount = 0;
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
void pop_help(size_t index, size_t count, Heap::Entry* other){
    size_t small = index;
    if (((index*2)+1) < count && other[(index*2)+1].score < other[index].score){
        small = (index*2) + 1;
    }
    if (((index*2)+2) < count && other[(index*2)+2].score < other[index].score){
        small = (index*2) + 2;
    }
    if (small != index){
        Heap::Entry temp = other[index];
        other[index] = other[small];
        other[small] = temp;
        pop_help(small, count, other);
    }
}

Heap::Entry Heap::pop(){
    if (mCount == 0){
        throw std::underflow_error("empty heap");
    } 
    Entry min = mData[0];
    mCount--;
    if (mCount == 0){
        return min;
    }
    mData[0] = mData[mCount-1];
    pop_help(0, mCount, mData);
    return min;
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
        Entry temp = mData[idx];
        mData[idx] = mData[(idx-1)/2];
        mData[(idx-1)/2] = temp;
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