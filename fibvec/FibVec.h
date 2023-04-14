#ifndef FIBVEC_H
#define FIBVEC_H

// This provides the size_t type:
#include <cstddef>

class FibVec {
  // Member Variables

  // Helper Functions

public:
  // Constructor and Destructor
    FibVec(); //Constructor
    ~FibVec(); //Destructor

  // Member Functions
  size_t capacity() const;
  size_t count() const;
  void insert(int value, int index);
  int lookup(int index) const;
  int pop();
  void push(int value);
  int remove(int index);

private:
  int *vec;
  size_t cap;
  size_t cnt;
  //size_t n;

};

// Used by the autograder:
FibVec* create_fibvec();

#endif
