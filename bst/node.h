#ifndef NODE
#define NODE
#include <iostream>
#include <cstring>

using namespace std;

class Node { // Node Class
public:
  Node(int Value); // Node Constructor
  ~Node(); // Destructor
  int getValue(); // get value of node
  void setValue(int); // set value of node
  void setRight(Node*); // Set the right node
  void setLeft(Node*); // Set the left node
  void setPrev(Node*); // Set the previous node
  void setNext(Node*); // Set the next node
  Node* getRight(); // Get the right node
  Node* getLeft(); // Get the left node
  Node* getPrev(); // Get the previous node
  Node* getNext(); // Get the next node
private:
  Node* right;
  Node* left;
  Node* prev;
  Node* next;
  int value;
};

#endif
