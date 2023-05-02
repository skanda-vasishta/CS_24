#include "Set.h"

Node* copy_set(const Node* root){
    if (root == nullptr) {
        return nullptr;
    }
    else {
    Node* copy_node = new Node;
    copy_node->data = root->data;
    copy_node->count = root->count;

    copy_node->left = copy_set(root->left);
    copy_node->right = copy_set(root->right);

    return copy_node; }

}

Set::Set() {
    mRoot = nullptr;



}


Set::Set(const Set& other){
    mRoot = copy_set(other.mRoot);
    

}


Set::Set(Set&& other) {
    //ok
    mRoot = other.mRoot;
    other.mRoot = nullptr;
}

Set::~Set(){
    //ok
    //probably call clear here, then delete
    clear();
    
    
}
size_t clear_help(Node* node){ //fix here
    if (node == nullptr){
        return 0;
    }
    size_t count = clear_help(node->left) + clear_help(node->right) + 1;
    delete node;
    return count;

    //
}

size_t Set::clear() {
    size_t tree_size = clear_help(mRoot);
    mRoot = nullptr;
    return tree_size;
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

size_t countNodes(Node* node) { //fix here
    if (node == nullptr) {
        return 0;
    } else {
        return (countNodes(node->left) + 1 + countNodes(node->right));
    }
}

size_t Set::count() const{
    //ok
    return countNodes(mRoot);
}

void debug(){
    //ok
}

size_t Set::insert(const std::string& value) {
    // If the tree is empty, create a new node and make it the root
    if (mRoot == nullptr) {
        mRoot = new Node;
        mRoot->data = value;
        mRoot->count = 1;
        return 1;
    }
    size_t count_track = 0;
    Node* currentNode = mRoot;
    while (true) {
        if (value == currentNode->data) {
            return currentNode->count;
        }
        else if (value < currentNode->data) {
            if (currentNode->left == nullptr) {
                currentNode->left = new Node;
                currentNode->left->data = value;
                currentNode->left->count =1;
                //return currentNode->count+1;
                count_track++;
            }
            currentNode = currentNode->left;
        }
        else {
            if (currentNode->right == nullptr) {
                currentNode->right = new Node;
                currentNode->right->data = value;
                currentNode->right->count++;
                //return currentNode->count+1;
                count_track++;
            }
            currentNode = currentNode->right;
        }
    }
    return count_track;
}

const std::string& Set::lookup(size_t n) const {
    if (n >= countNodes(mRoot)) {
        throw std::out_of_range("Set lookup failed: index out of range");
    }

    const Node* current = mRoot;
    size_t left_size = 0;

    while (current != nullptr) {
        left_size = (current->left != nullptr) ? current->left->count : 0;

        if (n == left_size) {
            return current->data;
        } else if (n < left_size) {
            current = current->left;
        } else {
            n -= (left_size + 1);
            current = current->right;
        }
    }

    throw std::out_of_range("Set lookup failed: index out of range");
}


void print_helper(Node* root){ 
    if (countNodes(root)==1){
        std::cout << root->data ;
        return;
    }
    if (root == nullptr) {
        std::cout << ""; 
        return;
    }
    std::cout << "("; 
    if (root->left == nullptr){
        std::cout << "-";
    }
    print_helper(root->left); 
    std::cout << " " << root->data << " "; 
    if (root->right == nullptr ){
        std::cout << "-";
    } else if (root->right == nullptr && root->left == nullptr ) {
        std::cout << "-" ;
    }
    print_helper(root->right); 
    std::cout << ")"; 
}

void Set::print() const{
    print_helper(mRoot);
    std::cout << std::endl;
}

bool remove_helper(Node*& node, const std::string& value) {
    /*if (countNodes(node) == 1){
        delete node;
        node == nullptr;
    }*/
    if (node == nullptr) {
        return false; 
    }
    if (value < node->data) {
        return remove_helper(node->left, value);
    } else if (value > node->data) {
        return remove_helper(node->right, value);
    } else { 
        if (node->left == nullptr && node->right == nullptr) { 
            delete node;
            node = nullptr;
        } else if (node->left == nullptr) { 
            Node* temp = node;
            node = node->right;
            delete temp;
        } else if (node->right == nullptr) { 
            Node* temp = node;
            node = node->left;
            delete temp;
        } else { 
            Node* current = node->left;
            while (current->right != nullptr) {
                current = current->right;
            }
            node->data = current->data;
            return remove_helper(node->left, current->data);
        }
        return true; 
    }
}

size_t Set:: remove(const std::string& value){
    size_t count = 0;
    while (remove_helper(mRoot, value)) {
        count++;
    }
    return count;
}
