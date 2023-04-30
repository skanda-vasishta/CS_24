#include "Set.h"
Set::Set() {
    mRoot = nullptr;
}

Set::Set(const Set& other){
    //ok
}

Set::Set(Set&& other) {
    //ok
}

Set::~Set(){
    //ok
}

size_t Set::clear() {
    //ok
}

bool Set::contains(const std::string& value) const {
    //ok
}

size_t Set::count() const{
    //ok
}

void debug(){
    //ok
}

size_t Set::insert(const std::string& value){
    //set
}

const std::string& Set::lookup(size_t n) const{
    //set
}

void Set::print() const{
    //ok
}

size_t Set:: remove(const std::string& value){
    //ok
}