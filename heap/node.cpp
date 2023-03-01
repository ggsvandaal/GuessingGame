#include <iostream>
#include <cstring>
#include "node.h"

using namespace std;

Node::Node(int Number) {
  number = Number;
};

int Node::getNumber() {
  return number;  
}


Node* Node::getNext() {
  return next;
}

void Node::setNext(Node* Next) {
  next = Next;
}

Node::~Node() {
}
