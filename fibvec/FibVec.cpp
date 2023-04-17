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

size_t fib(size_t num) {
    size_t a = 1;
    size_t b = 1;
    for (size_t i = 3; i <= n; i++) {
        size_t c = a + b;
        a = b;
        b = c;
    }
    return b;
}

void FibVec::resize(size_t new_cap){
  int *new_vec = new int[new_cap];
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
  if (cnt>=cap){
    resize(fib(cap+1));
  } 
  for (size_t i = cnt; i > index; i--){
      vec[i] = vec[i-1];
  }
  vec[index] = value;
  cnt++;
 }

 int FibVec::lookup(size_t index) const {
  if (index>cnt){
    throw std::out_of_range("index is out of range");
  }
  return vec[index];
 }

 int FibVec::pop(){
  int pop_val = vec[cnt];
  cnt--;
  if (cnt < fib(cap-2)){
    resize(cap-1);
  }
  return pop_val ;
 }

void FibVec::push(int value) {
  if (cnt == cap){
    resize(fib(cap+1));
  }
  vec[cnt] = value;
  cnt++;
}

int FibVec::remove(size_t index){
  return 1;
}