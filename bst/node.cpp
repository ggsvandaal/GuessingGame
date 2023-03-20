#include <iostream>
#include <cstring>
#include "node.h"

using namespace std;

Node::Node(int Value) {
  value = Value;
  right = NULL;
  left = NULL;
  prev = NULL;
  next = NULL;
};

void Node::setValue(int input) {
  value = input;
}
		     

int Node::getValue() {
  return value;  
}


Node* Node::getRight() {
  return right;
}

Node* Node::getLeft() {
  return left;
}

Node* Node::getPrev() {
  return prev;
}

Node* Node::getNext() {
  return next;
}

void Node::setRight(Node* Right) {
  right = Right;
}

void Node::setLeft(Node* Left) {
  left = Left;
}

void Node::setPrev(Node* Prev) {
  prev = Prev;
}

void Node::setNext(Node* Next) {
  next = Next;
}

Node::~Node() {
}
