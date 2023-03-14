#include <iostream>
#include <cstring>
#include "node.h"

using namespace std;

Node::Node(char Value) {
  value = Value;
  right = NULL;
  left = NULL;
  prev = NULL;
};

void Node::setValue(char input) {
  value = input;
}
		     

char Node::getValue() {
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

void Node::setRight(Node* Right) {
  right = Right;
}

void Node::setLeft(Node* Left) {
  left = Left;
}

void Node::setPrev(Node* Prev) {
  prev = Prev;
}

Node::~Node() {
}
