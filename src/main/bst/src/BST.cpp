//
// Created by achen on 28/09/2021.
//

#include "BST.h"

#include <utility>
#include "iostream"

struct BST::Node {
    Key key;
    Item item;
    Node* leftChild;
    Node* rightChild;

    Node(Key key, Item item) {
        this->key = key;
        this->item = std::move(item);
        leftChild = leaf();
        rightChild = leaf();
    }
};

BST::BST() {
    root = leaf();
}

BST::Item *BST::lookup(BST::Key key) {
    if (root == nullptr) {
        return nullptr;
    } else if (root->key == key) {
        return &root->item;
    }

    if (root->key < key) {
        return lookupRecursion(root->rightChild, key);
    }

    return lookupRecursion(root->leftChild, key);
}

BST::Item *BST::lookupRecursion(Node* currentNode, int key) {
    if (currentNode == nullptr) {
        return nullptr;
    } else if (currentNode->key == key) {
        return &currentNode->item;
    }

    if (currentNode->key < key) {
        Item* item = lookupRecursion(currentNode->rightChild, key);
        return item;
    }

    Item* item = lookupRecursion(currentNode->leftChild, key);
    return item;
}

void BST::insert(BST::Key key, const BST::Item& item) {
    if (!root) {
        Node* node = new Node(key, item);
        root = node;
    } else {
        insertRecursion(root, key, item);
    }
}

void BST::insertRecursion(BST::Node * node, BST::Key key, const BST::Item& item) {
    if (node->key == key) {
        node->item = item;
    } else if (node->key < key) {
        if (!isLeaf(node->rightChild)) {
            insertRecursion(node->rightChild, key, item);
        } else {
            node->rightChild = new Node(key, item);
        }
    } else {
        if (!isLeaf(node->leftChild)) {
            insertRecursion(node->leftChild, key, item);
        } else {
            node->leftChild = new Node(key, item);
        }
    }
}

void BST::display() {
    displayRecursion(root);
}

void BST::displayRecursion(BST::Node* node ) {
    if (!root) {
        return;
    }

    if (node->leftChild) {
        displayRecursion(node->leftChild);
    }

    std::cout << node->key << " " << node->item << std::endl;

    if (node->rightChild) {
        displayRecursion(node->rightChild);
    }
}

void BST::displayTree() {
    displayTreeRecursion("", root);
}

void BST::displayTreeRecursion(const std::string& prefix, Node* node) {
    if (node != nullptr) {
        std::cout << prefix;

        std::cout << node->key << " " << node->item << std::endl;

        std::string branch = prefix + "  ";

        displayTreeRecursion(branch, node->leftChild);
        displayTreeRecursion(branch, node->rightChild);
    }
}

void BST::displayTreeInverted() {
    displayTreeRecursionInverted("", root);
}

void BST::displayTreeRecursionInverted(const std::string& prefix, Node* node) {
    if (node != nullptr) {
        std::string branch = prefix + "  ";

        displayTreeRecursionInverted(branch, node->rightChild);

        std::cout << prefix;

        std::cout << node->key << " " << node->item << std::endl;

        displayTreeRecursionInverted(branch, node->leftChild);
    }
}


bool BST::remove(BST::Key key) {
    if (root == nullptr) {
        return root;
    }
    return removeRecursion(root, key);
}


BST::Node* BST::removeRecursion(BST::Node* node, Key key) {
    if (node == nullptr) {
        return node;
    }

    if (key < node->key) {
        node->leftChild = removeRecursion(node->leftChild, key);
    } else if (key > node->key) {
        node->rightChild = removeRecursion(node->rightChild, key);
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

        node->key = temp->key;
        node->item = temp->item;

        node->rightChild = removeRecursion(node->rightChild, temp->key);
    }
    return node;
}


BST::Node *BST::findSmallestNode(Node* node) {
    Node* currentNode = node;

    while(currentNode && currentNode->leftChild != nullptr) {
        currentNode = currentNode->leftChild;
    }
    return currentNode;
}

BST::Node *BST::leaf() {
    return nullptr;
}

bool BST::isLeaf(BST::Node* node) {
    return node == leaf();
}

void *BST::removeIfRecursion(Node* node, const std::function<bool(Key)>& function) {

    if (node->leftChild != nullptr) {
        removeIfRecursion(node->leftChild, function);
    }
    if (node->rightChild != nullptr) {
        removeIfRecursion(node->rightChild, function);
    }
    if (function(node->key)) {
        remove(node->key);
    }
    return nullptr;
}

void BST::removeIf(std::function<bool(Key)> function) {
    if (!root) {
        return;
    }

    removeIfRecursion(root, function);
}

BST::BST(const BST & original) {
    this->root = deepCopy(original.root);
}

BST::Node *BST::deepCopy(BST::Node * originalNode) {

    if (originalNode == nullptr) {
        return nullptr;
    }

    Node* newNode = new Node(originalNode->key, originalNode->item);
    newNode->leftChild = deepCopy(originalNode->leftChild);
    newNode->rightChild = deepCopy(originalNode->rightChild);

    return newNode;

}


// Post order traversal
BST::~BST() {
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

void BST::deepDelete(BST::Node * node) {

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

BST &BST::operator=(const BST& original) {
    this->root = deepCopy(original.root);
    return *this;
}

BST::BST(BST && original) noexcept {
    deepDelete(this->root);
    this->root = original.root;
    original.root = leaf();
}

BST &BST::operator=(BST && original) noexcept {
    deepDelete(this->root);
    this->root = original.root;
    original.root = leaf();
    return *this;
}
