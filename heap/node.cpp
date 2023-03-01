#include <iostream>
#include <cstring>
#include "node.h"
#include "student.h"


using namespace std;

Node::Node(Student* Student) {
  student = Student;
};

Student* Node::getStudent() {
  return student;  
}


Node* Node::getNext() {
  return next;
}

void Node::setNext(Node* Next) {
  next = Next;
}

Node::~Node() {
  delete student;
}
