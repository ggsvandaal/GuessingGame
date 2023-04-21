/*
  Author: Samual van Daal
  Date: 
  Red-Black Tree
*/

#include <iostream>
#include <fstream>
#include <cstring>
#include "node.h"

using namespace std;

// Function Prototypes
void add(int a, Node* &b, Node* c); // Add function
void print(Node* a, int b); // Print Function
bool search(Node* a, int b); // Search Function (For Integers)
Node* treeSearch(Node* a, int b); // Tree Search Function (For nodes)
void del(Node* &a, int b); // Delete Function 
Node* inos(Node* a); // In Order Succesor Function
void addFile(Node* &a); // Add from file Function
void adjust(Node* a, Node* &b);
void leftRotate(Node* &a);
void rightRotate(Node* &a);

// Main Function //

int main() {

  // Variable Initialization
  Node* root = NULL;
  char input[80];
  int number;
  
  // Main Loop
  while (true) {
    
    // Commands and Entry
    cout << "Commands: ADD, ADD FILE, PRINT, SEARCH, DELETE, QUIT" << endl;
    cin.get(input, 80);
    cin.ignore(10, '\n');

    // ADD
    if (strcmp(input, "ADD") == 0) {
      cout << "Number: ";
      cin >> number;
      cin.ignore(10, '\n');
      add(number, root, root);
    }

    // ADD FILE
    if (strcmp(input, "ADD FILE") == 0) {
      addFile(root);
    }

    // PRINT
    if (strcmp(input, "PRINT") == 0) {
      print(root, 0);
    }

    // SEARCH
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

    // DELETE
    if (strcmp(input, "DELETE") == 0) {
      cout << "What number are you looking to delete?" << endl;
      cin >> number;
      cin.ignore(10, '\n');
      if (treeSearch(root, number) != NULL) {
	del(root, number);
      }
      else {
	cout << "Number is not in tree" << endl;
      }
    }

    // QUIT
    if (strcmp(input, "QUIT") == 0) {
      break;
    }
  }
}

// Add Function // 

void add(int input, Node* &root, Node* current) {

  // If Tree is empty
  if (root == NULL) {
    Node* node = new Node(input); // New node
    root = node; // Node is root
    adjust(root, root);
    return;
  }

  // Go left
  if (input < current -> getValue()) {
    // Spot is occupied
    if (current -> getLeft() != NULL) {
      add(input, root, current -> getLeft()); // Recurse
    }
    // Spot is empty
    else {
      // Set new node here
      Node* node = new Node(input);
      current -> setLeft(node);
      current -> getLeft() -> setParent(current);
      adjust(node, root);
    }
  }
  // Go right
  else {
    // Spit is occupied
    if (current -> getRight() != NULL) {
      add(input, root, current -> getRight()); // Recurse
    }
    // Spot is empty
    else {
      // Set new node here
      Node* node = new Node(input);
      current -> setRight(node);
      current -> getRight() -> setParent(current);
      adjust(node, root);
    }
  }
}

// Adjsust Function //

void adjust(Node* input, Node* &root) {
  if (input == root) {
    input -> setBlack();
  }
  if (input -> getParent() != NULL && input -> getUnc(input) != NULL) {
    if (input -> getParent() -> getColor() == 'r' && input -> getUnc(input) -> getColor() == 'r') {
      input -> getParent() -> setBlack();
      input -> getUnc(input) -> setBlack();
      input -> getGrand(input) -> setRed();
      adjust(input -> getGrand(input), root);
    }
  }
  if (input -> getParent() != NULL) {
    bool uncBlack = false;
    if (input -> getUnc(input) == NULL) {
      uncBlack = true;
    }
    else {
      if (input -> getUnc(input) -> getColor() == 'b') {
	uncBlack = true;
      }
    }
    if (input -> getParent() -> getColor() == 'r' && uncBlack == true) {
      if (input -> getGrand(input) -> getRight() == input -> getParent()) {
	if (input -> getParent() -> getLeft() == input) {
	  cout << "right rotate" << endl;
	  rightRotate(input);
	  adjust(input -> getRight(), root);
	}
	else if (input -> getParent() -> getRight() == input) {
	  bool trial = false;
	  Node* temp = input -> getGrand(input);
	  if (temp == root) {
	    trial = true;
	  }
	  Node* parent = input -> getParent();
	  leftRotate(parent);
	  input -> getParent() -> setBlack();
	  temp -> setRed();
	  if (trial == true) {
	    root = parent;
	  }
	}
      }
      else if (input -> getGrand(input) -> getLeft() == input -> getParent()) {
	if (input -> getParent() -> getRight() == input) {
	  cout << "left rotate" << endl;
	  leftRotate(input);
	  adjust(input -> getLeft(), root);
	}
	else if (input -> getParent() -> getLeft() == input) {
	  bool trial = false;
	  Node* temp = input -> getGrand(input);
	  if (temp == root) {
	    trial = true;
	  }
	  Node* parent = input -> getParent();
	  rightRotate(parent);
	  input -> getParent() -> setBlack();
	  temp -> setRed();
	  if (trial == true) {
	    root = parent;
	  }
	}
      }
    }
  }
}

void leftRotate(Node* &node) {
  Node* parent = node -> getParent();
  Node* grand = node -> getGrand(node);
  if (grand != NULL) {
    if (grand -> getRight() == parent) {
      grand -> setRight(node);
    }
    else {
      grand -> setLeft(node);
    }
    node -> setParent(grand);
  }
  parent -> setRight(node -> getLeft());
  //if (parent -> getRight() != NULL) {
    // parent -> getRight() -> setParent(parent);
    //}
  parent -> setParent(node);
  node -> setLeft(parent);
}

void rightRotate(Node* &node) {
  Node* parent = node -> getParent();
  Node* grand = node -> getGrand(node);
  if (grand != NULL) {
    if (grand -> getRight() == parent) {
      grand -> setRight(node);
    }
    else {
      grand -> setLeft(node);
    }
    node -> setParent(grand);
  }
  parent -> setLeft(node -> getLeft());
  if (parent -> getLeft() != NULL) {
    parent -> getLeft() -> setParent(parent);
  }
  parent -> setParent(node);
  node -> setRight(parent);
}

// Print Function //

void print(Node* current, int depth) {
  if (current -> getRight() != NULL) { // Checking Right
    print(current -> getRight(), depth+1); // Recurse
  }

  for (int i = 0; i < depth; i++) { // Adding Indents
    cout << '\t';
  }
  cout << current -> getColor() <<current -> getValue() << endl; // Printing

  if (current -> getLeft() != NULL) { //Checking Left
    print(current -> getLeft(), depth+1); // Recurse
  }
}

// Search Function //

bool search(Node* current, int input) {
  if (current == NULL) return false; // Reached end without finding input
  if (current -> getValue() == input) return true; // Found input
  return search(current -> getRight(), input) + search(current -> getLeft(), input); // Recurse

  
  
}

// Delete Function //

void del(Node* &root, int input) {
  // While target is still in the tree
  while (treeSearch(root, input) != NULL) {
    Node* target = treeSearch(root, input); // Seach tree for target
    int numKids = (target -> getRight() != NULL) + (target -> getLeft() != NULL); // Count the number of children

    // 2 children 
    if (numKids == 2) {
      Node* temp = inos(target -> getRight()); // Find in order succesor
      //cout << "In order successor: " << temp -> getValue() << endl;
      target -> setValue(temp -> getValue()); // Set target value to in order succesor
      temp -> getParent() -> setRight(temp -> getRight()); // Remove in order succesor from tree
      delete temp; // Delete in order succesor
    }
    
    // 1 child
    else if (numKids == 1) {
      Node* temp;
      if (target -> getRight() != NULL) { // If child is right
	temp = target -> getRight(); // Set child
      }
      else { // If child is left
	temp = target -> getLeft(); // Set child
      }
      if (target == root) { // If deleting root
        target = temp; // Set root to child
      }
      else {
	if (target -> getParent() -> getRight() == target) { // If child is right
	  target -> getParent() -> setRight(temp); // Remove target from tree
	}
	else { // If child is left
	  target -> getParent() -> setLeft(temp); // Remove target from tree
	}
	delete target; // Delete target
      }
    }
    
    // 0 Children
    else {
      if (target == root) { // If target is root
	target == NULL; // Set to NULL
      }
      else {
	if (target -> getParent() -> getRight() == target) { // If target is a right child
	  target -> getParent() -> setRight(NULL); // NULL right of previous
	}
	else { // If target is a left child
	  target -> getParent() -> setLeft(NULL); // NULL left of previous
	}
	delete target; // Delete target
      }
    }
  }
}

// Tree Search Function //

Node* treeSearch(Node* current, int input) {
  if (current == NULL) return NULL; // Input was not in tree 
  if (current -> getValue() == input) return current; // Input was in tree
  Node* right = treeSearch(current -> getRight(), input); 
  Node* left = treeSearch(current -> getLeft(), input);
  if (right != NULL) return right; // Go right
  return left; // Go left
}

// In Order Succesor Function //

Node* inos(Node* current) {
  if (current -> getLeft() == NULL) { // Go as far left as possible
    return current; // Return in order succesor
  }
  return inos(current -> getLeft()); // Recurse
}

// Add File Function //

void addFile(Node* &root) {
  // Initalize
  char fileName[80];
  int place;
  int num;
  
  // Ask for file
  cout << "What file do you want to add? : ";
  cin.get(fileName, 80);
  cin.ignore(10, '\n');
  ifstream File (fileName); // Find file
  if(File.is_open()) {
    while (File >> num) { // Running numbers from file
      add(num, root, root); // Add to tree
    }
  }
}

