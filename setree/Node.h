#ifndef NODE_H
#define NODE_H
#include <string>
#include <iostream>

// Use this file to declare your Node type.
// Implement Node member functions and helper functions in Node.cpp.

class Node {
    public:
    std::string data;
    //size_t count;
    Node* left;
    Node* right;
    
    //Node();
    //Node* copy_set(const Node* root);
    /*Node* copy_set(const Node* root);
    size_t clear_help(Node* node);
    size_t countNodes(Node* node);
    void print_helper(Node* root);
    bool remove_helper(Node*& node, const std::string& value);*/

};
#endif
