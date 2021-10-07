//
// Created by achen on 28/09/2021.
//

#ifndef ADVANCED_SOFTWARE_ENGINEERING_BST_H
#define ADVANCED_SOFTWARE_ENGINEERING_BST_H


#include <string>
#include <functional>

class BST {
public:
    using Key = int;
    using Item = std::string;

    Item* lookup(Key);
    void insert(Key, const Item&);
    bool remove(Key);
    void display();
    void displayTree();
    void displayTreeInverted();
    void removeIf(std::function<bool(Key)>);

    BST();
    ~BST();

    // Copy constructor
    BST(const BST&);

    // Copy assignment operator
    BST & operator=(const BST &);

    // Move constructor
    BST(BST &&) noexcept;

    // Move assigment operator
    BST& operator=(BST&&) noexcept;

private:
    struct Node;
    Node* root;
    Item* lookupRecursion(Node *currentNode, Key key);
    void insertRecursion(Node*, Key, const Item&);
    void displayRecursion(Node*);
    void displayTreeRecursion(const std::string& prefix, Node*);
    void displayTreeRecursionInverted(const std::string& prefix, Node*);
    Node * removeRecursion(Node*, Key);
    void * removeIfRecursion(Node*, const std::function<bool(Key)>&);
    void deepDelete(Node*);
    Node* deepCopy(Node*);
    static Node* findSmallestNode(Node*);
    static Node* leaf();
    static bool isLeaf(Node*);

};


#endif //ADVANCED_SOFTWARE_ENGINEERING_BST_H
