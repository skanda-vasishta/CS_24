#include "Set.h"
#include "Node.h"



Set::Set() {
    mRoot = nullptr;            
}


Set::Set(const Set& other){
    mRoot = nullptr;
    mRoot = mRoot->copy_set(other.mRoot);
}


Set::Set(Set&& other) {
    //ok
    mRoot = other.mRoot;
    other.mRoot = nullptr;
}



size_t Set::clear() {
    size_t tree_size = mRoot->clear_help(mRoot);
    mRoot = nullptr;
    return tree_size;
}
Set::~Set(){
    clear(); 
}



bool Set::contains(const std::string& value) const {
    Node* root = mRoot;
    while (root != nullptr) {
        if (value == root->data) {
            return true;
        } else if (value < root->data) {
            root = root->left;
        } else {
            root = root->right;
        }
    }
    return false;
}



size_t Set::count() const{
    return mRoot->countNodes(mRoot);
}

void Set::debug(){
    //ok
}

size_t Set::insert(const std::string& value) {
    if (mRoot == nullptr) {
        mRoot = new Node;
        mRoot->data = value;
        return 1;
    }
    size_t count_track = 0;
    Node* currentNode = mRoot;
    while (true) {
        if (value == currentNode->data) {
            return mRoot->countNodes(currentNode);
        }
        else if (value < currentNode->data) {
            if (currentNode->left == nullptr) {
                currentNode->left = new Node;
                currentNode->left->data = value;
                count_track++;
            }
            currentNode = currentNode->left;
        }
        else {
            if (currentNode->right == nullptr) {
                currentNode->right = new Node;
                currentNode->right->data = value;
                count_track++;
            }
            currentNode = currentNode->right;
        }
    }
    return count_track;
}

const std::string& Set::lookup(size_t n) const {
    if (n >= count()) {
        throw std::out_of_range("n is out of range");
    }

    Node* node = mRoot;
    size_t index = 0;

    while (node != nullptr) {
        size_t left_count = (node->left != nullptr) ? mRoot->countNodes(node->left) : 0;
        if (index + left_count == n) {
            return node->data;
        } else if (index + left_count < n) {
            index += left_count + 1;
            node = node->right;
        } else {
            node = node->left;
        }
    }
    throw std::out_of_range("n is out of range");
}




void Set::print() const{
    mRoot->print_helper(mRoot);
    std::cout << std::endl;
}



size_t Set:: remove(const std::string& value){
    size_t count = 0;
    while (mRoot->remove_helper(mRoot, value)) {
        count++;
    }
    return count;
}
