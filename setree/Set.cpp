#include "Set.h"

Node* copy_set(const Node* root){
    if (root == nullptr){
        return nullptr;
    }
    Node* copy_node = new Node;
    copy_node->data = root->data;
    copy_node->count = root->count;
    copy_node->size = root->size;

    if (copy_node -> left != nullptr){
        copy_node->left = copy_set(root->left);
    }
    copy_node -> data = root -> data;
    if (copy_node -> right != nullptr){
        copy_node->right = copy_set(root->right);
    }
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
    clear();
    if (mRoot != nullptr) {
        delete mRoot;
    }
    
}
void clear_help(Node*& node){
    if (node != nullptr){
        clear_help(node->left);
        clear_help(node->right);
        delete node;
    }
    //
}

size_t Set::clear() {
    size_t tree_size = count();
    clear_help(mRoot);
    mRoot = nullptr;
    return tree_size;
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


size_t insert_help(const std::string& value, Node*& node){
    if (node == nullptr){
        node = new Node;
        node ->data = value;
        node->count=1;
        return node->count;
    }
    if (node-> data == value){
        return 0;
    } 
    if (value < node->data){
        node->count++;
        return insert_help(value, node->left);
    }
    if (value > node->data){
        node->count++;
        return insert_help(value, node->right);
    }
    return node->count;

}
size_t Set::insert(const std::string& value){
    if (mRoot == nullptr){
        mRoot = new Node;
        mRoot ->data = value;
        mRoot->count = 1;
        return 1;
    } else {
        return insert_help(value, mRoot);
    }

    
}

const std::string& Set::lookup(size_t n) const{
    //set
    static std::string s("");
    return s;
}

void inOrder(Node* root){
    if (root != nullptr) {
        if (root->count == 1){
            inOrder(root->left);
            std::cout  << root->data ;
            inOrder(root->right);
            std::cout << std::endl;
        } else if (root->count == 0){
            //
        } else {

        }
    } else {
        //std::cout<<"-";
    }
}
void Set::print() const{
    inOrder(mRoot);
}

size_t Set:: remove(const std::string& value){
    //ok
    return 1;
}

