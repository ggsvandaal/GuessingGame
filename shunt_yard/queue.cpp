#include <iostream>
#include "node.h"
#include "queue.h"

using namespace std;

Queue::Queue() {
  head = NULL;
  tail = NULL;
};

void Queue::enqueue(Node* input) {
  if (tail == NULL) {
    tail = input;
    head = input;
  }
  else {
    Node* temp = tail;
    tail = input;
    temp.setLeft(tail);
    tail.setPrev(temp);
  }
}

Node* Queue::dequeue() {
  if (head == NULL) {
    cout << "Queue is empty" endl;
  }
  else {
    Node* temp = head;
    head = head -> getLeft();
    return temp;
  }
}

char peek() {
}
