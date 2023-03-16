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
    head -> setNext(temp);
  }
}

char Stack::pop() {
  if (head == NULL) {
    cout << "Stack is empty" << endl;
    return '$';
  }
  else {
    char temp = head -> getValue();
    if (head -> getNext() != NULL) {
      Node* temps = head;
      //cout << head -> getLeft() -> getValue() << endl;
      head = head -> getNext();
      delete temps;
      return temp;
    }
    else {
      head = NULL;
      return temp;
    }
  }
}

Node* Stack::treePop() {
  if (head == NULL) {
    cout << "Stack is empty" << endl;
    return NULL;
  }
  else {
    Node* temp = head;
    head = head -> getNext();
    return temp;
  }

}

char Stack::peek() {
  if (head != NULL) {
    return head -> getValue();
  }
  return '$';
}

