#include "FibVec.h"

// This provides exception types:
#include <stdexcept>


FibVec* create_fibvec() {
  // Used by the autograder to make a new FibVec.
  // You shouldn't need to change this.
  return new FibVec();
}

FibVec::FibVec(){
  vec = new int[1];
  cap = 1;
  cnt = 0; 
}

FibVec::~FibVec(){
  delete [] vec;
}

//void FibVec::resize(){
  //size_t new_cap;
  //int *new_vec;


//}
// FibVec Function Implementations
size_t FibVec::capacity() const{
  return cap;
}

 size_t FibVec::count() const {
  return cnt;
 }

 void FibVec::insert(int value, size_t index){
  if (index>cnt){
    throw std::out_of_range("index is out of range");
  }
  if (cnt>cap){
    //resize vector since no room
  } else {
    vec[index] = value;
  }
 }

 int FibVec::lookup(size_t index) const {
  return 1;
 }

 int FibVec::pop(){
  return 1;
 }

void FibVec::push(int value) {

}

int FibVec::remove(size_t index){
  return 1;
}