//
// Created by achen on 28/09/2021.
//

#ifndef ADVANCED_SOFTWARE_ENGINEERING_BST_H
#define ADVANCED_SOFTWARE_ENGINEERING_BST_H


#include <string>
#include <functional>
#include <iostream>

template <typename K, typename I> class BST {
public:

    I* lookup(K k) {
        if (root == nullptr) {
            return nullptr;
        } else if (root->k == k) {
            return &root->i;
        }

        if (root->k < k) {
            return lookupRecursion(root->rightChild, k);
        }

        return lookupRecursion(root->leftChild, k);
    }

    void insert(K k, I i) {
        if (!root) {
            Node* node = new Node(k, i);
            root = node;
        } else {
            insertRecursion(root, k, i);
        }
    }
    bool remove(K k) {
        if (root == nullptr) {
            return root;
        }
        return removeRecursion(root, k);
    }
    void displayLTR() {
        displayRecursionLTR(root);
    }
    void displayRTL() {
        displayRecursionRTL(root);
    }
    void displayTree() {
        displayTreeRecursion("", root, false);
    }
    void removeIf(std::function<bool(K)> function) {
        if (!root) {
            return;
        }

        removeIfRecursion(root, function);
    }

    BST() {
        root = leaf();
    }
    ~BST() {
        if (!root) {
            return;
        }

        if (root->rightChild) {
            deepDelete(root->rightChild);
        }

        if (root->leftChild) {
            deepDelete(root->leftChild);
        }

        delete(root);
    }

    // Copy constructor
    BST(const BST& original) {
        this->root = deepCopy(original.root);
    }

    // Copy assignment operator
    BST & operator=(const BST & original) {
        this->root = deepCopy(original.root);
        return *this;
    }

    // Move constructor
    BST(BST && original) noexcept {
        deepDelete(this->root);
        this->root = original.root;
        original.root = leaf();
    }

    // Move assigment operator
    BST& operator=(BST&& original) noexcept {
        deepDelete(this->root);
        this->root = original.root;
        original.root = leaf();
        return *this;
    }

private:
    struct Node {
        K k;
        I i;
        Node* leftChild;
        Node* rightChild;

        Node(K k, I i) {
            this->k = k;
            this->i = i;
            leftChild = leaf();
            rightChild = leaf();
        }
    };

    Node* root;
    I* lookupRecursion(Node *currentNode, K k) {
        if (currentNode == nullptr) {
            return nullptr;
        } else if (currentNode->k == k) {
            return &currentNode->i;
        }

        if (currentNode->k < k) {
            I* i = lookupRecursion(currentNode->rightChild, k);
            return i;
        }

        I* i = lookupRecursion(currentNode->leftChild, k);
        return i;
    }
    void insertRecursion(Node* node, K k, I i) {
        if (node->k == k) {
            node->i = i;
        } else if (node->k < k) {
            if (!isLeaf(node->rightChild)) {
                insertRecursion(node->rightChild, k, i);
            } else {
                node->rightChild = new Node(k, i);
            }
        } else {
            if (!isLeaf(node->leftChild)) {
                insertRecursion(node->leftChild, k, i);
            } else {
                node->leftChild = new Node(k, i);
            }
        }
    }
    void displayRecursionLTR(Node* node) {
        if (!root) {
            return;
        }

        if (node->leftChild) {
            displayRecursionLTR(node->leftChild);
        }

        std::cout << node->k << ":" << node->i << std::endl;

        if (node->rightChild) {
            displayRecursionLTR(node->rightChild);
        }
    }
    void displayRecursionRTL(Node* node) {
        if (!root) {
            return;
        }

        if (node->rightChild) {
            displayRecursionRTL(node->rightChild);
        }

        std::cout << node->K << ":" << node->I << std::endl;

        if (node->leftChild) {
            displayRecursionRTL(node->leftChild);
        }
    }
    void displayTreeRecursion(std::string prefix, Node* node, bool isLeft) {
        if (node != nullptr) {
            std::cout << prefix;

            std::cout << (isLeft ? "├─" : "└─" );

            std::cout << node->k << ": " << node->i << std::endl;

            std::string branch = prefix + (isLeft ? "│ " : "  ");

            displayTreeRecursion(branch, node->leftChild, true);
            displayTreeRecursion(branch, node->rightChild, false);
        }
    }
    Node * removeRecursion(Node* node, K k) {
        if (node == nullptr) {
            return node;
        }

        if (k < node->k) {
            node->leftChild = removeRecursion(node->leftChild, k);
        } else if (k > node->k) {
            node->rightChild = removeRecursion(node->rightChild, k);
        } else {
            if (node->leftChild == nullptr && node->rightChild == nullptr) {
                return nullptr;
            } else if (node->leftChild == nullptr) {
                Node* temp = node->rightChild;
                delete(node);
                return temp;
            } else if (node->rightChild == nullptr) {
                Node* temp = node->leftChild;
                delete(node);
                return temp;
            }

            Node* temp = findSmallestNode(node->rightChild);

            node->k = temp->k;
            node->i = temp->i;

            node->rightChild = removeRecursion(node->rightChild, temp->k);
        }
        return node;
    }
    void * removeIfRecursion(Node* node, std::function<bool(K)> function) {
        if (node->leftChild != nullptr) {
            removeIfRecursion(node->leftChild, function);
        }
        if (node->rightChild != nullptr) {
            removeIfRecursion(node->rightChild, function);
        }
        if (function(node->k)) {
            remove(node->k);
        }
        return nullptr;
    }
    void deepDelete(Node* node) {
        if (node == nullptr) {
            return;
        }

        if (node->rightChild) {
            deepDelete(node->rightChild);
        }

        if (node->leftChild) {
            deepDelete(node->leftChild);
        }

        delete(node);
    }
    Node* deepCopy(Node* originalNode) {
        if (originalNode == nullptr) {
            return nullptr;
        }

        Node* newNode = new Node(originalNode->k, originalNode->i);
        newNode->leftChild = deepCopy(originalNode->leftChild);
        newNode->rightChild = deepCopy(originalNode->rightChild);

        return newNode;
    }
    static Node* findSmallestNode(Node* node) {
        Node* currentNode = node;

        while(currentNode && currentNode->leftChild != nullptr) {
            currentNode = currentNode->leftChild;
        }
        return currentNode;
    }
    static Node* leaf() {
        return nullptr;
    }
    static bool isLeaf(Node* node) {
        return node == leaf();
    }


};


#endif //ADVANCED_SOFTWARE_ENGINEERING_BST_H
