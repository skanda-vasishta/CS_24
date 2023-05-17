#include "Counter.h"
#include "DataStore.h"

// Counter Member Functions

 Counter::Counter(){
   counter = new DataStore();
 }

  Counter::~Counter(){
    delete counter;
  }

  size_t Counter::count() const{

  }
  int    Counter::total() const{

  }

  void Counter::inc(const std::string& key, int by = 1){
    Node* node = counter->lookup(key);
    if (node != nullptr){
      node->value +=by;
    }
    else {
      counter->push_back(key, by);
    }
  }

  void Counter::dec(const std::string& key, int by = 1){
    Node* node = counter->lookup(key);
    if (node != nullptr){
      node->value -=by;
    }
    else {
      counter->push_back(key, -by);
    }
  }

  void Counter::del(const std::string& key){
    Node* node = counter->lookup(key);
    if (node != nullptr){
      counter->remove(key);
    }
  }

  int  Counter::get(const std::string& key) const{
    Node* node = counter->lookup(key);
    if (node!=nullptr){
      return node->value;
    } else {
      return 0;
    }
  }
  void Counter::set(const std::string& key, int count){
    Node* node = counter->lookup(key);
    if (node!=nullptr){
      node->value = count;
    } else {
      counter->push_back(key, count);
    }

  }

Counter::Iterator Counter::begin() const {

}

Counter::Iterator Counter::end() const {

}