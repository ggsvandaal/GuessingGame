#ifndef NODE
#define NODE
#include <iostream>
#include <cstring>

using namespace std;

class Node { // Node Class
public:
  Node(char Value); // Node Constructor
  ~Node(); // Destructor
  char getValue(); // get value of node
  void setValue(char); // set value of node
  void setRight(Node*); // Set the right node
  void setLeft(Node*); // Set the left node
  void setPrev(Node*); // Set the previous node
  void setNext(Node*);
  Node* getRight(); // Get the right node
  Node* getLeft(); // Get the left node
  Node* getPrev(); // Get the previous node
  Node* getNext();
private:
  Node* right;
  Node* left;
  Node* prev;
  Node* next;
  char value;
};

#endif
