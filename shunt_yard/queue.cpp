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
    char equation[80];
    head = input;
  }
  else {
    Node* temp = tail;
    tail = input;
    temp -> setLeft(tail);
    tail -> setPrev(temp);
  }
}

char Queue::dequeue() {
  if (head == NULL) {
    cout << "Queue is empty" << endl;
    return ' ';
  }
  else {
    Node* temp = head;
    char v = head -> getValue();
    head = head -> getLeft();
    delete temp;
    return v;
  }
}

char Queue::peek() {
  return head -> getValue();
}
