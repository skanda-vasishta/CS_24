#include "Node.h"

//helper function for copy
Node* Node::copy_set(const Node* root){
    if (root == nullptr) {
        return nullptr;
    }
    else {
    Node* copy_node = new Node;
    copy_node->data = root->data;
    copy_node->left = copy_set(root->left);
    copy_node->right = copy_set(root->right);
    return copy_node; 
    }
}

//helper function for clear
size_t Node::clear_help(Node* node){ //fix here
    if (node == nullptr){
        return 0;
    }
    size_t count = clear_help(node->left) + clear_help(node->right) + 1;
    delete node;
    node = nullptr;
    return count;
}

//helper function for count
size_t Node::countNodes(Node* node) const { //fix here
    if (node == nullptr) {
        return 0;
    } else {
        return (countNodes(node->left) + 1 + countNodes(node->right));
    }
}

//helper function for print
void Node::print_helper(Node* root){ 
    if (countNodes(root)==1){
        std::cout << root->data ;
        return;
    }
    if (root == nullptr) {
        std::cout << "-"; 
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

//helper for remove
bool Node::remove_helper(Node*& node, const std::string& value) {
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
            return true;
        } else if (node->left == nullptr) { 
            Node* temp = node;
            node = node->right;
            delete temp;
            return true;
        } else if (node->right == nullptr) { 
            Node* temp = node;
            node = node->left;
            delete temp;
            return true;
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