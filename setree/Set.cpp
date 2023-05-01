#include "Set.h"

Node* copy_set(const Node* other){
    if (other == nullptr){
        return nullptr;
    }
    Node* copy_node = new Node;
    copy_node -> data = other -> data;
    copy_node->left = copy_set(other->left);
    copy_node->right = copy_set(other->right);
    return copy_node;
}

Set::Set() {
    mRoot = nullptr;
}

Set::Set(const Set& other){
    mRoot = copy_set(other.mRoot);

}


Set::Set(Set&& other) {
    //ok
}

Set::~Set(){
    //ok
    //probably call clear here, then delete
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

const std::string& Set::lookup(size_t n) const{
    //set
    static std::string s("");
    return s;
}

void Set::print() const{
    //ok
}

size_t Set:: remove(const std::string& value){
    //ok
    return 1;
}

