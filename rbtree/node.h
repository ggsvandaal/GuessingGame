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
  void setParent(Node*); // Set the parent node
  void setNext(Node*); // Set the next node
  Node* getRight(); // Get the right node
  Node* getLeft(); // Get the left node
  Node* getParent(); // Get the parent node
  Node* getNext(); // Get the next node
  Node* getGrand(Node*); // Get the Grand Parent node
  Node* getUnc(Node*);
  Node* getSib(Node*);
  char getColor(Node*);
  void setBlack();
  void setRed();
  
private:
  Node* right;
  Node* left;
  Node* parent;
  Node* next;
  int value;
  char color;
};

#endif
