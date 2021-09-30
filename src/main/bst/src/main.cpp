//
// Created by achen on 29/09/2021.
//

#include "BST.h"
#include "iostream"

int main()  {
    BST b;

    b.insert(22, "Jane");
    b.insert(22, "Mary");
    b.insert(0, "Harold");
    b.insert(9, "Edward");
    b.insert(37, "Victoria");
    b.insert(4, "Matilda");
    b.insert(26, "Oliver");
    b.insert(42, "Elizabeth");
    b.insert(19, "Henry");
    b.insert(4, "Stephen");
    b.insert(24, "James");
    b.insert(-1, "Edward");
    b.insert(31, "Anne");
    b.insert(23, "Elizabeth");
    b.insert(1, "William");
    b.insert(26, "Charles");

    std::cout << "Printing left to right" << std::endl;

    b.displayLTR();

    std::cout << "Printing right to left" << std::endl;

    b.displayTree();

}