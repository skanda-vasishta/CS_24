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

size_t FibVec::fib(size_t num) {
  if (num<=1){
    return num;
  }
  return fib(num-1) + fib(num-2);
}

void FibVec::resize(){
  size_t new_cap;
  int *new_vec;
  new_cap = fib(cap+1);
  new_vec = new int[new_cap];

  for (size_t i = 0; i<cnt; i++){
    new_vec[i] = vec[i];
  }
  delete[] vec;
  vec = new_vec;
  cap = new_cap;

}

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
  if (cnt==cap){
    resize();
  } 
  for (size_t i = cnt; i > index; --i){
    vec[i] = vec[i-1];
  }
  vec[index] = value;
  cnt++;
 }

 int FibVec::lookup(size_t index) const {
  return 1;
 }

 int FibVec::pop(){
  return 1;
 }

void FibVec::push(int value) {
  vec[cap] = value;
}

int FibVec::remove(size_t index){
  return 1;
}