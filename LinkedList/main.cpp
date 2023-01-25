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

void addStudent(char* a, char* b, int c, float d, Node* &e, Node* f);
void printList(Node* a);
void deleteStudent(Node* a);

// Node Testing
int main() {
  Node* head = NULL;
  Node* currentNode = head;
  // Initializing values
  char firstname[80];
  char lastname[80];
  int id;
  float gpa;
  char input[80];
  bool a = true;
  while (a == true) {
    cout << "Do you want to ADD, PRINT, DELETE, AVERAGE, or QUIT?" << endl;
    cin.get(input, 80);
    cin.ignore(10, '\n');
    if (strcmp(input, "ADD") == 0) {
      // Value input
      cout << "First Name? ";
      cin.get(firstname, 80);
      cin.ignore(10, '\n');
      cout << "Last Name? ";
      cin.get(lastname, 80);
      cin.ignore(10, '\n');
      cout << "ID Number? ";
      cin >> id;
      cin.ignore(10, '\n');
      cout << "GPA? ";
      cin >> gpa;
      cin.ignore(10, '\n');
      char* fn = firstname;
      char* ln = lastname;
      addStudent(fn, ln, id, gpa, head, currentNode);
    }
    if (strcmp(input, "PRINT") == 0) {
      cout << "--------------------" << endl;
      printList(head);
      cout << "--------------------" << endl;
    }
    if (strcmp(input, "DELETE") == 0) {
    }
    if (strcmp(input, "AVERAGE") == 0) {
    }
    if (strcmp(input, "QUIT") == 0) {
      a = false;
    }
  }
  //Student* child = new Student(fn, ln, id, gpa); // First Student
  //Node* trial = new Node(child); // First Node
  //cout << trial -> getStudent() -> getId() << endl; // Testing getStudent
  //Student* kid = new Student(fn, ln, 10, gpa); // Second Student
  //Node* test = new Node(kid); // Second Node
  //trial -> setNext(test); // Testing setNext
  //cout << trial -> getNext() -> getStudent() -> getId() << endl; // Testing get Next
}

void addStudent(char* fname, char* lname, int id, float gpa, Node* &head, Node* currentNode) {
  Student* student = new Student(fname, lname, id, gpa);
  Node* node = new Node(student);
  currentNode = head;
  if (head == NULL) {
    head = node;
  }
  else if (currentNode -> getNext() == NULL) {
    currentNode -> setNext(node);
  }
  else if ((node -> getStudent()) -> getId() < ((head -> getNext()) -> getStudent()) -> getId()) {
    Node* firstNode = currentNode;
    head = node;
    head -> setNext(firstNode);
  }
  else if ((node -> getStudent()) -> getId() < ((currentNode -> getNext()) -> getStudent()) -> getId()) {
    currentNode -> setNext(node);
  }
  else {
    addStudent(fname, lname, id, gpa, head, currentNode -> getNext());
  }
}

void printList(Node* head) {
  if (head != NULL) {
    cout << (head -> getStudent()) -> getName() << " " << (head -> getStudent())-> getLastname() << ", " << (head -> getStudent()) -> getId() << ", " << (head -> getStudent()) -> getGPA() << endl;
    if (head -> getNext() != NULL) {
      printList(head -> getNext());
    }
  }
}
