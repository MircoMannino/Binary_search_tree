#include "node.h"
using namespace std;

class BTree {
private:
    Node* root;

    /* private Methods */
    void addNode(Node* current, const int& value);
    bool search(Node* current, const int& value);
    void printPreOrder(Node* current);
    void printPostOrder(Node* current);
    void destroy_tree(Node* current);

public:
    /* Constructor */
    BTree() {
        root = NULL;
    }
    ~BTree() {
        destroy_tree(root);
    }

    /* Adding a node */
    void addNode(const int& value) {
        if(root != NULL) {
            addNode(root, value);
        } else {
            root = new Node(value);
        }
    }

    /* Search */
    bool search(const int& value) {
        return search(root, value);
    }

    /* Print pre ordered */
    void printPreOrder() {
        printPreOrder(root);
    }

    /* Print post ordered */
    void printPostOrder() {
        printPostOrder(root);
    }

};

void BTree::addNode(Node* current, const int& value) {
    if(value < current->getValue()) {
        if(current->getLeftNode() != NULL) {
             addNode(current->getLeftNode(), value);
        } else {
            current->setLeftNode(new Node(value));
        }
    } else if(value > current->getValue()) {
        if(current->getRigthNode() != NULL) {
             addNode(current->getRigthNode(), value);
        } else {
            current->setRightNode(new Node(value));
        }
    }
}

bool BTree::search(Node* current, const int& value) {
    if(current != NULL) {
        if(value == current->getValue()) {
            return true;
        }
        if(value < current->getValue()) {
            return search(current->getLeftNode(), value);
        }
        if(value > current->getValue()) {
            return search(current->getRigthNode(), value);
        }
    }
    return false;
}

void BTree::printPreOrder(Node* current) {
    if(current != NULL) {
        printPreOrder(current->getLeftNode());
        cout << current->getValue() << " ";
        printPreOrder(current->getRigthNode());
    }
}

void BTree::printPostOrder(Node* current) {
    if(current != NULL) {
        printPostOrder(current->getRigthNode());
        cout << current->getValue() << " ";
        printPostOrder(current->getLeftNode());

    }
}

void BTree::destroy_tree(Node* current) {
    if(current != NULL) {
        destroy_tree(current->getLeftNode());
        destroy_tree(current->getRigthNode());
        delete current;
    }
}
