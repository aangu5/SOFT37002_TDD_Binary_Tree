//
// Created by achen on 05/10/2021.
//

#ifndef ADVANCED_SOFTWARE_ENGINEERING_HASHTABLE_H
#define ADVANCED_SOFTWARE_ENGINEERING_HASHTABLE_H

#include "string"

template <typename K, typename I> class HashTable {
public:

    HashTable() {

    }

    void insert(K, I) {
        return;
    }

    I* lookup(K) {
        return nullptr;
    }

    void remove(K) {
        return;
    }

    void removeIf(std::function<bool(K)> function) {
        return;
    }


private:
    // as part of the hash table, there are two steps to obtain the array index:
    //
    // 1. Hash the K to an integer hash value using some hashing algorithm.
    // 2. Apply the modulo operation to the hash value to get an array index.
    //
    // this method only carries out the first part
    unsigned int hash(K k) {
        return std::hash<K>{}(k);
    }
};


#endif //ADVANCED_SOFTWARE_ENGINEERING_HASHTABLE_H
