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
    size_t count = 0;
    Node* node = counter->returnHead();
    while (node!=nullptr){
      count++;
      node = node->next;
    }
    return count;
  }

  int    Counter::total() const{
    int size = 0;
    Node* node = counter->returnHead();
    while (node!=nullptr){
      size+=node->value;
      node = node->next;
    }
    return size;
  }

  void Counter::inc(const std::string& key, int by){
    Node* node = counter->lookup(key);
    if (node != nullptr){
      node->value +=by;
    }
    else {
      counter->push_back(key, by);
    }
  }

  void Counter::dec(const std::string& key, int by){
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
  return Iterator(counter->returnHead());
}

Counter::Iterator Counter::end() const {
  return Iterator(nullptr);
}
