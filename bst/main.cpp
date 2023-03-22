#include <iostream>
#include <cstring>
#include "node.h"

using namespace std;

void add(int a, Node* &b, Node* c);
void print(Node* a, int b);
bool search(Node* a, int b);
Node* treeSearch(Node* a, int b);
void del(Node* &a, int b);

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
      cin >> number;
      cin.ignore(10, '\n');
      if (search(root, number) == true) {
	cout << input << " was found." << endl;
      }
      else {
	cout << input << " was not found." << endl;
      }
    }
    if (strcmp(input, "DELETE") == 0) {
      cout << "What number are you looking for?" << endl;
      cin >> number;
      cin.ignore(10, '\n');
      if (treeSearch(root, number) != NULL) {
	del(root, number);
      }
      else {
	cout << "Number is not in tree" << endl;
      }
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
      current -> getLeft() -> setPrev(current);
    }
  }
  else {
    if (current -> getRight() != NULL) {
      add(input, root, current -> getRight());
    }
    else {
      Node* node = new Node(input);
      current -> setRight(node);
      current -> getRight() -> setPrev(current);
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

bool search(Node* current, int input) {
  if (current == NULL) return false;
  if (current -> getValue() == input) return true;
  return search(current -> getRight(), input) + search(current -> getLeft(), input);

  
  /*
  if (current == NULL) {
    return;
  }
  if (current -> getValue() < input) {
    count = count+1;
    search(current -> getLeft(), input, find, count);
  }
  else if (current -> getValue() > input){
    count = count+1;
    search(current -> getRight(), input, find, count);
  }
  else {
    find = true;
  }
  */
}

void del(Node* &root, int input) {
  while (treeSearch(root, input) != NULL) {
    Node* target = treeSearch(root, input);
    int numKids = (target -> getRight() != NULL) + (target -> getLeft() != NULL);
    if (root -> getValue() == input) {
      // Delete root
    }
    // 2 kids
    if (numKids == 2) {
      
    }
    // 1 Kids
    else if (numKids == 1) {
      Node* temp;
      if (target -> getRight() != NULL) {
	temp = target -> getRight();
      }
      else {
	temp = target -> getLeft();
      }
      if (target -> getPrev() -> getRight() == target) {
        target -> getPrev() -> setRight(temp);
      }
      else {
        target -> getPrev() -> setLeft(temp);
      }
      delete target;
    }
    // 0 Kids
    else {
      if (target -> getPrev() -> getRight() == target) {
	target -> getPrev() -> setRight(NULL);
      }
      else {
	target -> getPrev() -> setLeft(NULL);
      }
      delete target;
    }
  }
}

Node* treeSearch(Node* current, int input) {
  if (current == NULL) return NULL;
  if (current -> getValue() == input) return current;
  Node* right = treeSearch(current -> getRight(), input);
  Node* left = treeSearch(current -> getLeft(), input);
  if (right != NULL) return right;
  return left;
}

