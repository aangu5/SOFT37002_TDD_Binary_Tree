//
// Created by achen on 05/10/2021.
//

#include "HashTable.h"

using Key = std::string;
using Item = std::string;

unsigned int hash(Key key) {
    return std::hash<Key>{}(key);
}