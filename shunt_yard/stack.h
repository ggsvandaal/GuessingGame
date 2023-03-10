// Stack Header

#include <iostream>
#include "node.h"

using namespace std;

class Stack {
public:
  Stack();
  //~Stack();
  void push(Node*);
  char pop();
  char peek();
private:
  Node* head;
};
