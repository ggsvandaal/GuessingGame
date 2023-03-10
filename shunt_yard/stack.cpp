#include <iostream>
#include "node.h"
#include "stack.h"

using namespace std;

Stack::Stack() {
  head = NULL;
};

void Stack::push(Node* input) {
  if (head == NULL) {
    head = input;
  }
  else {
    Node* temp = head;
    head = input;
    head -> setLeft(temp);
  }
}

char Stack::pop() {
  if (head == NULL) {
    cout << "Stack is empty" << endl;
    return ' ';
  }
  else {
    if (head -> getLeft() != NULL) {
      char temp = head -> getValue();
      Node* temps = head;
      head = head -> getLeft();
      delete temps;
      return temp;
    }
    else {
      head = NULL;
      return ' ';
    }
  }
}

char Stack::peek() {
  if (head != NULL) {
    return head -> getValue();
  }
  else {
    return '$';
  }
}

