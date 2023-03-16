// Queue Header

#include <iostream>
#include "node.h"

using namespace std;

class Queue { // Queue Class
public:
  Queue(); // Queue Initalization
  void enqueue(Node*); // Put a Node* into the bottom of queue
  Node* dequeue(); // Take a Node* from the top of the queue
  char peek(); // Peek at the top of the queue
private:
  Node* tail;
  Node* head;
};
