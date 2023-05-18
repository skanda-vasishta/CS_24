#ifndef INDEX_H
#define INDEX_H
#include "DataStore.h"
#include "Counter.h"
#include "functional"

// Space to implement a separate index class, if you choose to do so.
// This can make things simpler by clearly separating functionality.
// The Index is in charge of getting pairs from the DataStore by key.
class Index {
private:
    int size = 10000;
    struct Node** hashTable;

public:
    Index();
    ~Index();
    size_t hashFunction(const std::string& key);
    struct Node** getHash();




};
#endif
