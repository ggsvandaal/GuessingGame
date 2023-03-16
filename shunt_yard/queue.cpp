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
    temp -> setNext(tail);
    tail -> setPrev(temp);
  }
}

Node* Queue::dequeue() {
  if (head == NULL) {
    cout << "Queue is empty" << endl;
    return NULL;
  }
  else {
    Node* temp = head;
    head = head -> getNext();
    return temp;
  }
}

char Queue::peek() {
  if (head != NULL) {
    return head -> getValue();
  }
  else {
    return '$';
  }
}
