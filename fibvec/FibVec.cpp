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
  cap = 2;
  cnt = 0; 
  actual_size = fib(cap);
}

FibVec::~FibVec(){
  delete [] vec;
}

size_t FibVec::fib(size_t num) {
  if (num == 0){
    return 0;
  }
    if (num<=2){
    return 1;
  }
  return fib(num-1) + fib(num-2);
}


void FibVec::resize(size_t new_cap){
  size_t new_size = fib(new_cap);
  int *new_vec = new int[new_size];
  for (size_t i = 0; i<cnt; i++){
    new_vec[i] = vec[i];
  }
  delete[] vec;
  vec = new_vec;
  cap = new_cap;
  actual_size = new_size;


}

// FibVec Function Implementations
size_t FibVec::capacity() const{
  return actual_size;
}

 size_t FibVec::count() const {
  return cnt;
 }

 void FibVec::insert(int value, size_t index){
  if (index>cnt){
    throw std::out_of_range("index is out of range");
  }
  if (cnt==fib(cap)){
    resize(cap+1);
  } 
  for (size_t i = cnt; i > index; i--){
      vec[i] = vec[i-1];
  }
  vec[index] = value;
  cnt++;
 }

 int FibVec::lookup(size_t index) const {
  if (index>=cnt){
    throw std::out_of_range("index is out of range");
  }
  return vec[index];
 }

 int FibVec::pop(){
  if (cnt == 0) {
    throw std::underflow_error("vector is empty");
  }
  int pop_val = vec[cnt-1];
  vec[cnt-1] = 0;
  cnt--;
  if (cnt < fib(cap-2)){
    resize(cap-1);
  }
  return pop_val ;
 }

void FibVec::push(int value) {
  if (cnt == fib(cap)){
    resize(cap+1);
  }
  vec[cnt] = value;
  cnt++;
}

int FibVec::remove(size_t index){
  if (index>=cnt){
    throw std::out_of_range("index is out of range");
  }
  int remove_val = vec[index];
  for (size_t i = index; i <cnt -1; i++){
      vec[i] = vec[i+1];
  }
  vec[cnt-1] = 0;
  cnt--;
  if (cnt < fib(cap-2)){
    resize(cap-1);
  }

  return remove_val;


}