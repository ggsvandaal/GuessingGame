/*
* Author: Allam Syahriza
* Date: 1/13/23
* This establishes the node class, which are the components
* of a linked list.

*/

#ifndef NODE_H
#define NODE_H

#include <iostream>
#include <cstring>
#include "student.h"
using namespace std;

class Node {
  public:
  // Creates node
  Node();
  // Creates node with a student value
  Node(Student* studentP);
  // Destructor

  ~Node();
  // Sets student i.e. value of this node
  void setValue(Student* studentP);
  // Returns student
  Student* getStudent();
  // Sets next node
  void setNext(Node* nextP);
  // Returns next node
  Node* getNext();

  protected: 
  Student* student;
  Node* next;
};

#endif