#include "Set.h"
Set::Set() {
    mRoot = nullptr;
}

Set::Set(const Set& other){
    if (other.mRoot == nullptr){
        mRoot = nullptr;
    }
    
}


Set::Set(Set&& other) {
    //ok
}

Set::~Set(){
    //ok
}

size_t Set::clear() {
    //ok
    return 1;
}

bool Set::contains(const std::string& value) const {
    //ok
    return true;
}

size_t Set::count() const{
    //ok
    return 1;
}

void debug(){
    //ok
}

size_t Set::insert(const std::string& value){
    //set
    return 1;
}

/*const std::string& Set::lookup(size_t n) const{
    //set
    return "ok";
}*/

void Set::print() const{
    //ok
}

size_t Set:: remove(const std::string& value){
    //ok
    return 1;
}