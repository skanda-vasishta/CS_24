#ifndef INDEX_H
#define INDEX_H
#include "DataStore.h"
#include "Counter.h"
#include "functional"

// Space to implement a separate index class, if you choose to do so.
// This can make things simpler by clearly separating functionality.
// The Index is in charge of getting pairs from the DataStore by key.


class Index {
public:
    Index();
    ~Index();

    void insert(const std::string& key, Node* node);
    void remove(const std::string& key);
    Node* lookup(const std::string& key) const;
    Node** getHash();

private:
    int size = 1000;  // Adjust the table size as needed
    Node** hashTable;

    size_t hashFunction(const std::string& key) const;
};


#endif
