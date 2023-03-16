// Stack Header

#include <iostream>
#include "node.h"

using namespace std;

class Stack { // Stack Class
public:
  Stack(); // Initialize Stack
  void push(Node*); // Push Node* to stack
  char pop(); // Pop the top of stack off (char)
  Node* treePop(); // Pop the top of stack off (Node*)
  char peek(); // Peek at the top of the stack
private:
  Node* head;
};
