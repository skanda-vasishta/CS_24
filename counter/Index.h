#ifndef INDEX_H
#define INDEX_H

#include <string>

struct Node ;

class Index {
private:
    int size = 100001;
    Node** hashTable;
    int* statusArray;

public:
    Index();
    ~Index();
    size_t hashFunction(const std::string& key);
    Node** getHash();
    void hash_insert(const std::string& key, int value);
    void hash_remove(const std::string& key);
    Node* hash_lookup(const std::string& key);
    size_t count();
    int total();
};

#endif
