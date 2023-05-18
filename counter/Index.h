#ifndef INDEX_H
#define INDEX_H
#include "DataStore.h"
#include "Counter.h"
#include "functional"

// Space to implement a separate index class, if you choose to do so.
// This can make things simpler by clearly separating functionality.
// The Index is in charge of getting pairs from the DataStore by key.

struct Node;

class Index {
private:
    int size = 1000;
     Node** hashTable;

public:
    Index();
    ~Index();
    size_t hashFunction(const std::string& key);
    Node** getHash();
    void hash_insert(const std::string& key, int value);
    void hash_remove(const std::string& key);
    Node* hash_lookup(const std::string& key) ;





};

#endif
