#include "FibVec.h"

// This provides exception types:
#include <stdexcept>


FibVec* create_fibvec() {
  // Used by the autograder to make a new FibVec.
  // You shouldn't need to change this.
  return new FibVec();
}

FibVec::FibVec(){
  //default constructor 
}

FibVec::~FibVec(){
  //destructor
}

// FibVec Function Implementations
size_t FibVec::capacity() const{

}

 size_t FibVec::count() const {

 }

 void FibVec::insert(int value, int index){

 }

 int FibVec::lookup(int index) const {

 }

 int FibVec::pop(){

 }

void FibVec::push(int value) {

}

int FibVec::remove(int index){

}