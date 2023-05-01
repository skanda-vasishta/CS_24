#include "Set.h"

Node* copy_set(const Node* root){
    Node* copy_node = new Node;
    copy_node->left = copy_set(root->left);
    copy_node -> data = root -> data;
    copy_node->right = copy_set(root->right);
    return copy_node;

}

Set::Set() {
    mRoot = nullptr;
}

Set::Set(const Set& other){
    if (other.mRoot == nullptr){
        mRoot =  nullptr;
    } else {
    //mRoot = copy_set(other.mRoot);
    mRoot = copy_set(other.mRoot);
    }

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
    return false;
}

size_t Set::count() const{
    //ok
    return 1;
}

void debug(){
    //ok
}

size_t Set::insert(const std::string& value){
    if (mRoot == nullptr){
        mRoot = new Node;
        mRoot ->data = value;
    } 
    if (value < mRoot->data){
        if (mRoot -> left == nullptr){
            mRoot->left = new Node();
            mRoot->left->data = value;
        } else {
            insert(mRoot->left->data);
        }
    }
    if (value > mRoot->data){
        if (mRoot -> right == nullptr){
            mRoot->right = new Node();
            mRoot->right->data = value;
        } else {
            insert(mRoot->right->data);
        }
    }
    mRoot->count ++;

    return mRoot->count;
}

const std::string& Set::lookup(size_t n) const{
    //set
    static std::string s("");
    return s;
}

void inOrder(Node* root){
    if (root != NULL) {
        inOrder(root->left);
        std::cout << root->data;
        inOrder(root->right);
    } else {
        std::cout<<"-";
    }
}
void Set::print() const{
    inOrder(mRoot);
    std::cout << std::endl;
}

size_t Set:: remove(const std::string& value){
    //ok
    return 1;
}

