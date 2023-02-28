#include <iostream>
#include <cstring>
#include "node.h"
#include "student.h"

using namespace std;

void add(char* a, char* b, int c, float d, Node** e, int& f);
void print(Node** a, int b);
void deletef(Node** a, int b, int c);
int hashf(int a, int b);

int main() {
  int tableSize = 100;
  Node** ht;
  ht = new Node*[tableSize];
  for (int i = 0; i < tableSize; i++) {
    ht[i] = NULL;
  }
  char* name = new char[80];
  char* lastName = new char[80];
  int id;
  float gpa;
  char* input = new char[80];
  bool a = true;
  while (a == true) {
    cout << "You can ADD, ADDR (add random student), PRINT, DELETE, QUIT" << endl;
    cin.get(input, 10);
    cin.ignore(10, '\n');
    if (strcmp(input, "ADD") == 0) {
      cout << "First Name: ";
      cin.get(name, 80);
      cin.ignore(5, '\n');
      cout << "Last Name: ";
      cin.get(lastName, 80);
      cin.ignore(5, '\n');
      cout << "ID: ";
      cin >> id;
      cin.ignore(5, '\n');
      cout << "GPA: ";
      cin >> gpa;
      cin.ignore(5, '\n');
      add(name, lastName, id, gpa, ht, tableSize);
    }
    if (strcmp(input, "PRINT") ==0) {
      print(ht, tableSize);
    }
    if (strcmp(input, "DELETE") == 0) {
      cout << "Which Student do you want to delete? (ID): ";
      cin >> id;
      cin.ignore(5, '\n');
      deletef(ht, tableSize, id);
    }
    if (strcmp(input, "QUIT") == 0) {
      a = false;
    }
  }
}

void add(char* name, char* lastName, int id, float gpa, Node** ht, int& tableSize) {
  Student* student = new Student(name, lastName, id, gpa);
  Node* node = new Node(student);
  int index = hashf(id, tableSize);
  if (ht[index] == NULL) {
    ht[index] = node;
    ht[index] -> setNext(NULL);
  }
  else if (ht[index] != NULL) {
    Node* temp = ht[index];
    node -> setNext(temp);
    ht[index] = node;
  }
  else if (ht[index] -> getNext() != NULL) {
    if (ht[index] -> getNext() -> getNext() != NULL) {
      if (ht[index] -> getNext() -> getNext() -> getNext() != NULL) {
	if (ht[index] -> getNext() -> getNext() -> getNext() -> getNext() != NULL) {
	   
	}
      }
    }
  }
}

void print(Node** ht, int tableSize) {
  Node* temp;
  cout << " - - - - - - - - - - - - - - - - - - " << endl;
  for (int i = 0; i < tableSize; i++) {
    if (ht[i] != NULL) {
      cout << ht[i] -> getStudent() -> getName() << " "
	   << ht[i] -> getStudent() -> getLastname() << " , ID: "
	   << ht[i] -> getStudent() -> getId() << " , GPA: "
	   << ht[i] -> getStudent() -> getGPA() << endl;
      temp = ht[i];
      for (int j = 0; j < 3; j++) {
	if (temp -> getNext() != NULL) {
	  temp = temp -> getNext();
	  cout << temp  -> getStudent() -> getName() << " "
           << temp -> getStudent() -> getLastname() << " , ID: "
           << temp -> getStudent() -> getId() << " , GPA: "
           << temp -> getStudent() -> getGPA() << endl;
	}
	else {
	  j = 3;
	}
      }
    }
  }
  cout << " - - - - - - - - - - - - - - - - - - " << endl;
}

void deletef(Node** ht, int tableSize, int id) {
  int index = hashf(id, tableSize);
  Node* temp = ht[index];
  if (temp -> getNext() != NULL) {
    if (ht[index] -> getStudent() -> getId() == id) {
      ht[index] = ht[index] -> getNext();
    }
    else {
      for(int i = 0; i < 3; i++) {
	Node* a = temp;
	temp = temp -> getNext();
	if (temp -> getStudent() -> getId() == id) {
	  a -> setNext(temp -> getNext());
	}
      }
    }
  }
  else {
    cout << ht[index] << endl;
    if (ht[index] -> getStudent() -> getId() == id) {
      delete ht[index];
      ht[index] = NULL;
    }
  }
}

int hashf(int id, int tableSize) {
  int index = id % tableSize;
  return index;
}

