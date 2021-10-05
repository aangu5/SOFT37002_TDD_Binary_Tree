//
// Created by achen on 05/10/2021.
//

#ifndef ADVANCED_SOFTWARE_ENGINEERING_HASHTABLE_H
#define ADVANCED_SOFTWARE_ENGINEERING_HASHTABLE_H

#include "string"

class HashTable {
public:
    using Key = std::string;
    using Item = std::string;

    HashTable();

    void insert(Key, Item);
    Item* lookup(Key);
    void remove(Key);

private:
    // as part of the hash table, there are two steps to obtain the array index:
    //
    // 1. Hash the key to an integer hash value using some hashing algorithm.
    // 2. Apply the modulo operation to the hash value to get an array index.
    //
    // this method only carries out the first part
    unsigned int hash(Key);
};


#endif //ADVANCED_SOFTWARE_ENGINEERING_HASHTABLE_H
