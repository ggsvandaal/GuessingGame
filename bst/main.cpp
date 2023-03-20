#include <iostream>
#include <cstring>
#include "node.h"

using namespace std;

void add(int a, Node* &b, Node* c);
void print(Node* a, int b);
void search(Node* a, int b, bool &c);

int main() {
  Node* root = NULL;
  char input[80];
  int number;
  while (true) {
    cout << "Commands: ADD, PRINT, SEARCH, DELETE, QUIT" << endl;
    cin.get(input, 80);
    cin.ignore(10, '\n');
    if (strcmp(input, "ADD") == 0) {
      cout << "Number: ";
      cin >> number;
      cin.ignore(10, '\n');
      add(number, root, root);
    }
    if (strcmp(input, "PRINT") == 0) {
      print(root, 0);
    }
    if (strcmp(input, "SEARCH") == 0) {
      cout << "What number are you looking for?" << endl;
      bool find;
      search(root, number, find);
    }
    if (strcmp(input, "QUIT") == 0) {
      break;
    }
  }
}

void add(int input, Node* &root, Node* current) {
  if (root == NULL) {
    Node* node = new Node(input);
    root = node;
    return;
  }
  if (input < current -> getValue()) {
    if (current -> getLeft() != NULL) {
      add(input, root, current -> getLeft());
    }
    else {
      Node* node = new Node(input);
      current -> setLeft(node);
    }
  }
  else {
    if (current -> getRight() != NULL) {
      add(input, root, current -> getRight());
    }
    else {
      Node* node = new Node(input);
      current -> setRight(node);
    }
  }
}

void print(Node* current, int depth) {
  if (current -> getRight() != NULL) { // Checking Right
    print(current -> getRight(), depth+1);
  }

  for (int i = 0; i < depth; i++) { // Adding Indents
    cout << '\t';
  }
  cout << current -> getValue() << endl; // Printing

  if (current -> getLeft() != NULL) { //Checking Left
    print(current -> getLeft(), depth+1);
  }
}

void search(Node* current, int input, bool &find) {
  
}
