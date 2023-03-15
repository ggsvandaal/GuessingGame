// Queue Header

#include <iostream>
#include "node.h"

using namespace std;

class Queue {
public:
  Queue();
  //~Queue();
  void enqueue(Node*);
  Node* dequeue();
  char peek();
private:
  Node* tail;
  Node* head;
};
