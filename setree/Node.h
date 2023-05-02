#ifndef NODE_H
#define NODE_H
#include <string>
#include <iostream>

// Use this file to declare your Node type.
// Implement Node member functions and helper functions in Node.cpp.

class Node {
    public:
    std::string data;
    size_t count;
    size_t size;
    Node* left;
    Node* right;
    
    //Node();
    //Node* copy_set(const Node* root);

};
#endif
