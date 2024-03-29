
#ifndef DATASTORE_H
#define DATASTORE_H
using namespace std;
#include <string>

// Space to implement a separate datastore class, if you choose to do so.
// This can make things simpler by clearly separating functionality.
// The DataStore is in charge of storing pairs in insertion order.
class Index;

struct Node {
    std::string key;
    int value = 0;
    struct Node* next = nullptr;
    struct Node* prev = nullptr;
    struct Node* buck = nullptr;
};

class DataStore{
    private:
    Node* head;
    Node* tail;
    //int count;
    Index* table;

    public:
    DataStore();
    ~DataStore();

    void push_back(const std::string& key, int value);
    void remove(const std::string& key);
    Node* lookup(const std::string& key) const;
    Node* returnHead() const;
    Node* returnTail() const;
    size_t count() const;
    //int total() const;
};

#endif