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
    return '$';
  }
  else {
    char temp = head -> getValue();
    Node* temps = head;
    if (head -> getLeft() != NULL) {
      //cout << head -> getLeft() -> getValue() << endl;
      head = head -> getLeft();
      delete temps;
      return temp;
    }
    else {
      head = NULL;
      return temp;
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

