/*
Author: Samual van Daal
Date: 3/16/2023
Project: Shunting Yard Algorithm
 */

#include <iostream>
#include <cstring>
#include "node.h"
#include "stack.h"
#include "queue.h"

void alg(char* a, char* b, Stack c, Queue* d); // Algorithm Function
bool pcheck(char a, char b); // Precedence Check Function
void build(Queue* a, Stack b, Node* &c); // Binary Tree Build Function
void postf(Node* a); // Postfix Print Function
void pref(Node* a); // Prefix Print Function
void inf(Node* a); // Infix Print Function
void rtree(Node* a, Node* &b); // Reset Binary Tree Function

using namespace std;

// Main Function //

int main() {
  // Initialization
  char input[80];
  char equation[80];
  char postfix[80];
  Node* root = NULL;
  for (int i = 0; i < 80; i++) {
    postfix[i] = '\0';
  }
  equation[0] = '\0';

  // Main Loop
  while(true) {
    cout << "Do you want to INPUT, or find the PREFIX/INFIX/POSTFIX, or QUIT?" << endl;
    cin.get(input, 80);
    cin.ignore(10, '\n');

    // Input Entered
    if (strcmp(input, "INPUT") == 0) {
      Stack stack; // Initialize Stack
      Queue* queue = new Queue(); // Initialize Queue
      cout << "Input an infix equation!" << endl;
      cin.get(equation, 80);
      cin.ignore(10, '\n');
      rtree(root, root); // To Reset Tree Function
      alg(equation, postfix, stack, queue); // To Algorithm Function
      build(queue, stack, root); // To Build Tree Function
      cout << "Postfix: ";
      postf(root); // To Postfix Function
      cout << endl;
      // Reset Equation
      for (int i = 0; i < 80; i++) {
	equation[i] = '\0';
      }
    }

    // Postfix Entered
    if (strcmp(input, "POSTFIX") == 0) {
      postf(root); // To Postfix Function
      cout << endl;
    }

    // Infix Entered
    if (strcmp(input, "INFIX") == 0) {
      inf(root); // To Infix Function
      cout << endl;
    }

    // Prefix Entered
    if (strcmp(input, "PREFIX") == 0) {
      pref(root); // To Prefix Function
      cout << endl;
    }

    // Quit Entered
    if (strcmp(input, "QUIT") == 0) {
      break; // Leave Main Loop
    }

    // Reset Input
    for (int i = 0; i < 80; i++) {
      input[i] = '\0';
    }
  }
}


// Shunting Yard Algorithm Function //

void alg(char* input, char* output, Stack stack, Queue* queue) {
  int place = 0;
  // Loop Through Equation Given
  for (int i = 0; i < 80; i++) {

    char variable = input[i]; // Variable to work with
    if (variable == '\0') { // Checks for the end of the equation
      break;
    }
    
    // If an operator is the variable
    if (variable == '*' ||
	variable == '/' ||
	variable == '+' ||
	variable == '-' ||
	variable == '^') {

      // If new operator is of equal or lower precedence than previous
      if (pcheck(stack.peek(), variable) == false) {
	if (stack.peek() != '$') {
	  char temp = stack.pop(); // Removes previous operator from stack
	  Node* place = new Node(temp);
	  queue -> enqueue(place); // Places that operator in queue
	  Node* node = new Node(variable); 
	  stack.push(node); // Places new operator in stack
	}
      }

      // If the new operator is of higher precedence than previous
      else if (pcheck(stack.peek(), variable) == true) {
        Node* node = new Node(variable);
        stack.push(node); // Places new operator in stack
      }
    }

    // If a left parenthesis is the variable
    else if (variable == '(') {
      Node* node = new Node(variable);
      stack.push(node); // Place parenthesis in the stack
    }

    // If the variable is a number
    else if (isdigit(variable) == true) {
      Node* add = new Node(variable);
      queue -> enqueue(add); // Place the number in the queue
    }

    // If the variable is a right parenthesis
    else if (variable == ')') {
      bool truth = true;
      // Loop through stack
      while (truth == true) {
	char temp = stack.pop(); // Remove top of stack
	if (temp != '(') { // If top of stack was not a left parenthesis
	  Node* place = new Node(temp);
	  queue -> enqueue(place); // Place top of stack into queue
	}
	else { // If top of stack was a left parenthesis
	  truth = false; // End loop
	}
      }
    }
    // End of For loop
  }
  while(stack.peek() != '$') { // While stack isn't empty
    char temps = stack.pop(); // Remove top of stack
    Node* places = new Node(temps);
    queue -> enqueue(places); // Put top of stack into queue
  }
}


// Precedence Check Function //

bool pcheck(char head, char add) {
  int headp = 0; // Head precence
  int addp = 0; // Add Precedence
  
  if (head == '+' || head == '-') { // Head Precedence 1
    headp = 1;
  }
  else if (head == '*' || head == '/') { // Head Precedence 2
    headp = 2;
  }
  else if (head == '^') { // Head Precedence 3
    headp = 3;
  }
  else { // Head Precedence 0
    headp = 0;
  }
  if (add == '+' || add == '-') { // Add Precedence 1
    addp = 1;
  }
  else if (add == '*' || add == '/') { // Add Precedence 2
    addp = 2;
  }
  else if (add == '^') { // Add Precedence 3
    addp = 3;
  }
  else if (add == '$') { // Add Precedence 0
    addp = 0;
  }
  // Add is greater than head or add is '^'
  if (addp > headp || add == '^') {
    return true;
  }
  // Add is less than or equal to head
  else if (addp <= headp) {
    return false;
  }
  return true;
}


// Build Binary Expression Tree Function //

void build(Queue* queue, Stack stack, Node* &root) {
  // Loop through Queue
  while (true) {
    char temp = queue -> peek();
    
    // If the top of queue is a number 
    if (int(temp) >= 48 && int(temp) <= 57) {
      Node* n = queue -> dequeue();
      stack.push(n); // Put it in stack
    }
    // If the top of queue is an operator 
    else if (queue -> peek() == '+' ||
	     queue -> peek() == '-' ||
	     queue -> peek() == '*' ||
	     queue -> peek() == '/' ||
	     queue -> peek() == '^') {
      Node* temp = queue -> dequeue(); // Put the top of queue into a temp
      if (queue -> peek() == '$') { // If queue is empty
	root = temp; // Root is equal to temp
	Node* r = stack.treePop(); // Make a right node from top of stack
	root -> setRight(r); // Root right is the right node
	r -> setPrev(root); // Right node parent is root
	Node* l = stack.treePop(); // Make a left node from top of stack
	root -> setLeft(l); // Root left is the left nodee
	l -> setPrev(root); // Left node paerent is root
	break; // Tree is complete
      }
      else { // If queue isn't empty
	Node* r = stack.treePop(); // Make a right node from top of stack
	temp -> setRight(r); // Temp right is the right node
	r -> setPrev(temp); // Right node parent is temp
	Node* l = stack.treePop(); // Make a left node from top of stack
	temp -> setLeft(l); // Temp left is the left node
	l -> setPrev(temp); // Left node parent is temp
	stack.push(temp); // Put temp back into the stack
      }
    }
  }
}


// Postfix Print Function //

void postf (Node* current) { // Recursive
  if (current == NULL) return; // If current is NULL go back
  postf(current -> getLeft()); // Go to current left
  postf(current -> getRight()); // Go to current right
  cout << current -> getValue(); // Print current value
}


// Prefix Print Function // 

void pref (Node* current) { // Recursive
  if (current == NULL) return; // If current is NULL go back
  cout << current -> getValue(); // Print current value
  pref(current -> getLeft()); // Go to current left
  pref(current -> getRight()); // Go to current right
}


// Infix Print Function //

void inf (Node* current) { // Recursive
  if (current == NULL) return; // If current is NULL go back
  cout << "("; // Print (
  inf(current -> getLeft()); // Go to current left
  cout << current -> getValue(); // Print current value
  inf(current -> getRight()); // Go to current right
  cout << ")"; // Print )
}


// Reset Tree Function //

void rtree(Node* current, Node* &root) { // Recursive
  // If current is already NULL
  if (current == NULL) {
    return; // Go back
  }
  // If current left and right are already NULL
  if (current -> getRight() == NULL && current -> getLeft() == NULL) {
    current = NULL; // Set current to NULL
    return; // Go back
  }
  rtree(current -> getRight(), root); // Go to right 
  rtree(current -> getLeft(), root); // Go to left
}
