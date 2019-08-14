#ifndef __NODE_H__
#define __NODE_H__

using namespace std;

class Node {
private:
    int value;
    Node* right_node;
    Node* left_node;
public:
    /* Constructor */
    Node(const int& value_, Node* right_node_, Node* left_node_) {
        value = value_;
        right_node = right_node_;
        left_node = left_node_;
    }
    Node(const int& value_) {
        value = value_;
        right_node = NULL;
        left_node = NULL;
    }

    /* Getter */
    int getValue() const { return value; }
    Node* getRigthNode() const { return right_node; }
    Node* getLeftNode() const { return left_node; }

    /* Setters */
    void setValue(const int& value_) { value = value_; }
    void setRightNode(Node* right_node_) { right_node = right_node_; }
    void setLeftNode(Node* left_node_) { left_node = left_node_; }
};



#endif
