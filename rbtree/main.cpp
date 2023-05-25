/*
  Author: Samual van Daal
  Date: 5/24/2023
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
void adjust(Node* a, Node* &b);// Adjust Function (For Red-Black Tree) Line 138
void leftRotate(Node* &a); // Left Rotation Function
void rightRotate(Node* &a); // Right Rotation Function
char checkChild(Node* a); // Check if left or right child
int delFix(Node* a, Node* &b, int c); // Red-Black Deletion Adjustment
Node* findRoot(Node* a); // Useless Function

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
  
  // Case 1 Check
  if (input == root) { 
    input -> setBlack(); // Root is always black
  }

  // Case 3 Check
  if (input -> getParent() != NULL && input -> getUnc(input) != NULL) {
    if (input -> getParent() -> getColor(input -> getParent()) == 'r' && input -> getUnc(input) -> getColor(input -> getUnc(input)) == 'r') {
      
      // Swap Colors of Parent and Grandparent
      input -> getParent() -> setBlack();
      input -> getUnc(input) -> setBlack();
      input -> getGrand(input) -> setRed();
      // Check to see if colorswap changed anything else in the tree
      adjust(input -> getGrand(input), root);
    }
  }

  // Case 4 & 5 Check
  if (input -> getParent() != NULL) {
    bool uncBlack = false;
    // Check if Uncle is Black or NULL
    if (input -> getUnc(input) == NULL) {
      uncBlack = true;
    }
    else {
      if (input -> getUnc(input) -> getColor(input -> getUnc(input)) == 'b') {
	uncBlack = true;
      }
    }
    // Check if Parent is red and uncle is black
    if (input -> getParent() -> getColor(input -> getParent()) == 'r' && uncBlack == true) {
      // Check Right
      if (input -> getGrand(input) -> getRight() == input -> getParent()) {
	// Case 4
	if (input -> getParent() -> getLeft() == input) {
	  rightRotate(input);
	  adjust(input -> getRight(), root);
	}
	// Case 5
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
	    if (root -> getParent() != NULL) {
	      root -> setParent(NULL);
	    }
	  }
	}
      }
      // Check Left
      else if (input -> getGrand(input) -> getLeft() == input -> getParent()) {
	bool trial = false;
        Node* temp = input -> getGrand(input);
	// Case 4
	if (input -> getParent() -> getRight() == input) {
	  leftRotate(input);
	  adjust(input -> getLeft(), root);
	}
	// Case 5
	else if (input -> getParent() -> getLeft() == input) {
	  if (temp == root) {
	    trial = true;
	  }
	  Node* parent = input -> getParent();
	  rightRotate(parent);
	  input -> getParent() -> setBlack();
	  temp -> setRed();
	  if (trial == true) {
	    root = parent;
	    if (root -> getParent() != NULL) {
	      root -> setParent(NULL);
	    }
	  }
	}
      }
    }
  }
}

// Left Rotation Function //

void leftRotate(Node* &node) {
  Node* parent = node -> getParent();
  Node* grand = node -> getGrand(node);
  // Check to edit grandfather pointer
  if (grand != NULL) {
    if (grand -> getRight() == parent) {
      grand -> setRight(node);
    }
    else {
      grand -> setLeft(node);
    }
    node -> setParent(grand);
  }
  // Edit parent pointer
  parent -> setRight(node -> getLeft());
  if (node -> getLeft() != NULL) {
    node -> getLeft() -> setParent(parent);
  }
  parent -> setParent(node);
  // Edit Node
  node -> setLeft(parent);
}

// Right Rotation Function //

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
  parent -> setLeft(node -> getRight());
  if (node -> getRight() != NULL) {
    node -> getRight() -> setParent(parent);
  }
  parent -> setParent(node);
  node -> setRight(parent);
}

// Print Function //

void print(Node* current, int depth) {
  cout << "Printing: " << endl;
  if (current -> getRight() != NULL) { // Checking Right
    print(current -> getRight(), depth+1); // Recurse
  }

  for (int i = 0; i < depth; i++) { // Adding Indents
    cout << '\t';
  }
  cout << current -> getColor(current) << current -> getValue() << endl; // Printing
  
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

    // Red Deletion
    if (target -> getColor(target) == 'r') {
      // Red 0 Kids deletion
      if (numKids == 0) {
	// Check right
        if (checkChild(target) == 'r') {
	  target -> getParent() -> setRight(NULL);
	  delete target;
        }
	// Check Left
        else if (checkChild(target) == 'l') {
	  target -> getParent() -> setLeft(NULL);
	  delete target;
	}
      }
      // Red 1 kid deletion
      else if (numKids == 1) {
	// If Child is on the right
	if (target -> getRight() != NULL) {
	  if (target -> getParent() -> getRight() == target) {
	    target -> getParent() -> setRight(target -> getRight());
	  }
	  else {
	    target -> getParent() -> setLeft(target -> getRight());
	  }
	  target -> getRight() -> setParent(target -> getParent());
	}
	// If child is on the left
	else {
	  if (target -> getParent() -> getRight() == target) {
	    target -> getParent() -> setRight(target -> getLeft());
	  }
	  else {
	    target -> getParent() -> setLeft(target -> getLeft());
	  }
	  target -> getRight() -> setParent(target -> getParent());
	}
	delete target;
      }
    }
    else {
      // Universal 2 kids deletion
      if (numKids == 2) {
	Node* successor = inos(target -> getRight());
	if (successor -> getColor(successor) == 'b') {
	  target -> setValue(delFix(successor, root, 0));
	}
	if (successor -> getRight() != NULL) {
          successor -> getRight() -> setParent(successor -> getParent());
          if (checkChild(successor) == 'l') {
            successor -> getParent() -> setLeft(successor -> getRight());
          }
          else if (checkChild(successor) == 'r') {
            successor -> getParent() -> setRight(successor -> getRight());
          }
	  target -> setValue(successor -> getValue());
          delete successor;
        }
        else {
	  if (checkChild(successor) == 'l') {
	    successor -> getParent() -> setLeft(NULL);
	  }
	  else {
	    successor -> getParent() -> setRight(NULL);
	  }
	  target -> setValue(successor -> getValue());
	  delete successor;
        }
      }
      // Black one kid deletion
      else if (numKids == 1) {
	if (target -> getRight() != NULL) {
	  target -> setValue(delFix(target, root, 0));
	  target -> getRight() -> setParent(target -> getParent());
	  if (checkChild(target) == 'l') {
	    target -> getParent() -> setLeft(target -> getRight());
	  }
	  else if (checkChild(target) == 'r') {
	    target -> getParent() -> setRight(target -> getRight());
	  }
	  delete target;
	}
	else {
	  target -> setValue(delFix(target, root, 0));
	  target -> getLeft() -> setParent(target -> getParent());
          if (checkChild(target) == 'l') {
            target -> getParent() -> setLeft(target -> getLeft());
          }
          else if (checkChild(target) == 'r') {
            target -> getParent() -> setRight(target -> getLeft());
          }
          delete target;
	}
      }
      // Black 0 kids deletion
      else if (numKids == 0) {
	int value = delFix(target, root, 0);
	cout << "0 Kid Deletion" << endl;
	if (target == root) {
	  root = NULL;
	}
	else {
	  if (checkChild(target) == 'r') {
	    target -> getParent() -> setRight(NULL);
	  }
	  else {
	    target -> getParent() -> setLeft(NULL);
	  }
	  delete target;
	}
      }
    }
    root -> setParent(NULL);
  }
}

// Deletion Red-Black Adjustment //

int delFix(Node* current, Node* &root, int value) {
  // Case 1
  if (current == root) {
    return value;
  }
  // Case 2
  if (current -> getSib(current) -> getColor(current -> getSib(current)) == 'r') {
    current -> getSib(current) -> setBlack();
    current -> getParent() -> setRed();
    Node* sib = current -> getSib(current);
    if (checkChild(current) == 'r') {
      rightRotate(sib);
    }
    else {
      leftRotate(sib);
    }
    value = delFix(current, root, value);
  }
  Node* sib = current -> getSib(current);
  // Case 3 & 4
  if (sib != NULL) {
    if (sib -> getColor(sib) == 'b' && current -> getColor(current) == 'b' && sib -> getRight() -> getColor(sib -> getRight()) == 'b' && sib -> getLeft() -> getColor(sib -> getLeft()) == 'b') {
      // Case 3
      if (current -> getParent() -> getColor(current-> getParent()) == 'b') {
      current  -> getSib(current) -> setRed();
      value = delFix(current -> getParent(), root, value);
      }
      // Case 4
      else if (current -> getParent() -> getColor(current -> getParent()) == 'r') {
	current -> getParent() -> setBlack();
	sib -> setRed();
      }
    }
    // Case 5 & 6
    if (current -> getColor(current) == 'b' && sib -> getColor(sib) == 'b') {
      Node* sr = sib -> getRight();
      Node* sl = sib -> getLeft();
      // Case 5 Left
      if (checkChild(current) == 'l' && sl -> getColor(sl) == 'r' && sr -> getColor(sr) == 'b') {
	sib -> setRed();
	sl -> setBlack();
	rightRotate(sl);
      }
      // Case 5 Right
      else if (checkChild(current) == 'r' && sr -> getColor(sr) == 'r' && sl -> getColor(sl) == 'b') {
	sib -> setRed();
	sr -> setBlack();
	leftRotate(sr);
      }
      sib = current -> getSib(current);
      sl = sib -> getLeft();
      sr = sib -> getRight();
      // Case 6 Left
      if (checkChild(current) == 'l' && sr -> getColor(sr) == 'r') {
	if (current -> getParent() -> getColor(current -> getParent()) == 'r') {
	  current -> getParent() -> setBlack();
	  sib -> setRed();
	  sr -> setBlack();
	}
	else {
	  current -> getParent() -> setBlack();
	  sib -> setBlack();
	  sr -> setBlack();
	}
	if (current -> getParent() -> getParent() == NULL) {
	  root = sib;
	}
	leftRotate(sib);
      }
      // Case 6 Right
      else if (checkChild(current) == 'r' && sl -> getColor(sl) == 'r') {
	if (current -> getParent() -> getColor(current -> getParent()) == 'r') {
          current -> getParent() -> setBlack();
          sib -> setRed();
	  sl -> setBlack();
        }
        else {
          current -> getParent() -> setBlack();
          sib -> setBlack();
	  sl -> setBlack();
	}
	if (current -> getParent() -> getParent() == NULL) {
          root = sib;
        }
	rightRotate(sib);
      }
    }
  }
  return 0;
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

// Check if input is a right or left child //

char checkChild(Node* input) {
  if (input -> getParent() == NULL) {
    return ' ';
  }
  if (input -> getParent() -> getRight() == input) {
    return 'r';
  }
  return 'l';
}

// Useless function //

Node* findRoot(Node* current) {
  if (current -> getParent() == NULL) return current;
  return findRoot(current -> getParent());
}
