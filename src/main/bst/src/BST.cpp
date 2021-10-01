//
// Created by achen on 28/09/2021.
//

#include "BST.h"
#include "iostream"

struct BST::Node {
    Key key;
    Item item;
    Node* leftChild;
    Node* rightChild;

    Node(Key key, Item item) {
        this->key = key;
        this->item = item;
        leftChild = leaf();
        rightChild = leaf();
    }
//
//    ~Node() {
//        delete(key);
//        delete(item);
//        delete(rightChild);
//        delete(leftChild);
//    }
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

void BST::insert(BST::Key key, BST::Item item) {
    if (!root) {
        Node* node = new Node(key, item);
        root = node;
    } else {
        insertRecursion(root, key, item);
    }
}

void BST::insertRecursion(BST::Node * node, BST::Key key, BST::Item item) {
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

void BST::displayLTR() {
    displayRecursionLTR(root);
}

void BST::displayRecursionLTR(BST::Node * node) {
    if (!root) {
        return;
    }

    if (node->leftChild) {
        displayRecursionLTR(node->leftChild);
    }

    std::cout << node->key << ":" << node->item << std::endl;

    if (node->rightChild) {
        displayRecursionLTR(node->rightChild);
    }
}

void BST::displayRTL() {
    displayRecursionRTL(root);
}

void BST::displayRecursionRTL(BST::Node * node) {
    if (!root) {
        return;
    }

    if (node->rightChild) {
        displayRecursionRTL(node->rightChild);
    }

    std::cout << node->key << ":" << node->item << std::endl;

    if (node->leftChild) {
        displayRecursionRTL(node->leftChild);
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

void BST::displayTree() {
    displayTreeRecursion("", root, false);
}

void BST::displayTreeRecursion(std::string prefix, Node* node, bool isLeft) {
    if( node != nullptr )
    {
        // prefix allows each layer to be indented correctly
        std::cout << prefix;

        // isLeft determines whether this node is a left or right node
        std::cout << (isLeft ? "├──" : "└──" );

        // print the value of the node
        std::cout << node->key << ": " << node->item << std::endl;

        // enter the next tree level - left and right branch
        displayTreeRecursion(prefix + (isLeft ? "│   " : "    "), node->leftChild, true);
        displayTreeRecursion(prefix + (isLeft ? "│   " : "    "), node->rightChild, false);
    }
}

void *BST::removeIfRecursion(Node* node, std::function<bool(Key)> function) {

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
