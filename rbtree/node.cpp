#include <iostream>
#include <cstring>
#include "node.h"

using namespace std;

Node::Node(int Value) {
  value = Value;
  right = NULL;
  left = NULL;
  parent = NULL;
  next = NULL;
  color = 'r';
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

Node* Node::getParent() {
  return parent;
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

void Node::setParent(Node* Prev) {
  parent = Prev;
}

void Node::setNext(Node* Next) {
  next = Next;
}

Node* Node::getGrand(Node* input) {
  return input -> getParent() -> getParent();
}

Node* Node::getUnc(Node* input) {
  if (input -> getParent() != NULL && input -> getSib(input -> getParent()) != input -> getParent()) {
    return input -> getParent() -> getSib(input -> getParent());
  }
  return input;
}

Node* Node::getSib(Node* input) {
  if (input -> getParent() != NULL) {
    if (input -> getParent() -> getRight() == input) {
      return input -> getParent() -> getLeft();
    }
    return input -> getParent() -> getRight();
  }
  return input;
}

char Node::getColor() {
  return color;
}

void Node::setBlack() {
  color = 'b';
}

void Node::setRed() {
  color = 'r';
}

Node::~Node() {
}

