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

char Stack::pop(Node* input) {
  if (head == NULL) {
    cout << "Stack is empty" << endl;
    return ' ';
  }
  else {
    char temp = head -> getValue();
    Node* temps = head;
    head = head -> getLeft();
    delete temps;
    return temp;
  }
}

char Stack::peek() {
  return head -> getValue();
}

