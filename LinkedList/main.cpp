/*
Author: Samual van Daal
Project: Linked List Part 1
Date: 1/5/2023
 */

#include <iostream>
#include <cstring>
#include "node.h"
#include "student.h"

using namespace std;

// Node Testing
int main() {
  // Initializing values
  char firstname[80];
  char lastname[80];
  int id;
  float gpa;
  // Value input
  cin.get(firstname, 80);
  cin.ignore(10, '\n');
  cin.get(lastname, 80);
  cin.ignore(10, '\n');
  cin >> id;
  cin.ignore(10, '\n');
  cin >> gpa;
  char* fn = firstname;
  char* ln = lastname;
  Student* child = new Student(fn, ln, id, gpa); // First Student
  Node* trial = new Node(child); // First Node
  cout << trial -> getStudent() -> getId() << endl; // Testing getStudent
  Student* kid = new Student(fn, ln, 10, gpa); // Second Student
  Node* test = new Node(kid); // Second Node
  trial -> setNext(test); // Testing setNext
  cout << trial -> getNext() -> getStudent() -> getId() << endl; // Testing get Next
}
