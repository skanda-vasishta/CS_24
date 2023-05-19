#include "Counter.h"
#include "DataStore.h"



// Counter Member Functions

 Counter::Counter(){
   counter = new DataStore();
   count_= 0;
 }

  Counter::~Counter(){
    delete counter;
  }

  size_t Counter::count() const{
     return counter->count();
  }

  int    Counter::total() const{
    return count_;
  }

  void Counter::inc(const std::string& key, int by){
    Node* node = counter->lookup(key);
    if (node != nullptr){
      node->value +=by;
    }
    else {
      counter->push_back(key, by);
    }
    count_ +=by;

  }

  void Counter::dec(const std::string& key, int by){
    Node* node = counter->lookup(key);
    if (node != nullptr){
      node->value -=by;
    }
    else {
      counter->push_back(key, -by);
    }
    count_ -=by;
  }

  void Counter::del(const std::string& key){
    Node* node = counter->lookup(key);
    if (node != nullptr){
      counter->remove(key);
      count_ -= node->value;
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
    if (node){
      node->value = 0;
      node->value +=count;
    } else {
      counter->push_back(key, count);
    }
    count_ +=count;
  }

Counter::Iterator Counter::begin() const {
  return Iterator(counter->returnHead());
}

Counter::Iterator Counter::end() const {
  return Iterator(nullptr);
}