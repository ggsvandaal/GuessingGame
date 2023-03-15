#include <iostream>
#include <cstring>
#include "node.h"
#include "stack.h"
#include "queue.h"

void alg(char* a, char* b, Stack c, Queue* d);
bool pcheck(char a, char b);
void build(Queue* a, Stack b, Node* c);
void postf(Node* a);
void pref(Node* a);

using namespace std;

int main() {
  Stack stack;
  Queue* queue = new Queue();
  char input[80];
  char equation[80];
  char postfix[80];
  Node* root = NULL;
  for (int i = 0; i < 80; i++) {
    postfix[i] = '\0';
  }
  equation[0] = '\0';
  while(true) {
    cout << "Do you want to INPUT, or find the PREFIX/INFIX/POSTFIX, or QUIT?" << endl;
    cin.get(input, 80);
    cin.ignore(10, '\n');
    if (strcmp(input, "INPUT") == 0) {
      cout << "Input an infix equation!" << endl;
      cin.get(equation, 80);
      cin.ignore(10, '\n');
      alg(equation, postfix, stack, queue);
      build(queue, stack, root);
    }

    if (strcmp(input, "POSTFIX") == 0) {
    }
    
    if (strcmp(input, "INFIX") == 0) {
      if (equation[0] != '\0') {
	for (int i = 0; i < 81; i++) {
	  if (equation[i] != '\0') {
	    cout << equation[i];
	  }
	  else {
	    break;
	  }
	}
	cout << endl;
      }
      else {
	cout << "No equation entered" << endl;
      }
    }

    if (strcmp(input, "PREFIX") == 0) {
    }
    
    if (strcmp(input, "QUIT") == 0) {
      break;
    }
  }
}

void alg(char* input, char* output, Stack stack, Queue* queue) {
  int place = 0;
  for (int i = 0; i < 80; i++) {
    char variable = input[i];
    if (variable == '\0') {
      break;
    }
    if (variable == '*' ||
	variable == '/' ||
	variable == '+' ||
	variable == '-' ||
	variable == '^') {
      if (pcheck(stack.peek(), variable) == false) {
	if (stack.peek() != '$') {
	  char temp = stack.pop();
	  Node* place = new Node(temp);
	  queue -> enqueue(place);
	  Node* node = new Node(variable);
	  stack.push(node);
	  //cout << "pcheck false" << endl;
	}
      }
      else if (pcheck(stack.peek(), variable) == true) {
        Node* node = new Node(variable);
        stack.push(node);
	//cout << "pcheck true" << endl;
      }
    }
    else if (variable == '(') {
      Node* node = new Node(variable);
      stack.push(node);
    }
    
    else if (isdigit(variable) == true) {
      Node* add = new Node(variable);
      queue -> enqueue(add);
      //cout << "isdigit" << endl;
    }
    else if (variable == ')') {
      bool truth = true;
      while (truth == true) {
	char temp = stack.pop();
	if (temp != '(') {
	  //cout << temp << endl;
	  Node* place = new Node(temp);
	  queue -> enqueue(place);
	  //cout << ") check" << endl;
	}
	else {
	  truth = false;
	}
      }
    }
    //cout << stack.peek() << endl;
    //cout << "for" << endl;
  }
  int i = 0;
  while(stack.peek() != '$') {
    //cout << "placing stack" << endl;
    char temps = stack.pop();
    //cout << int(temps) << endl;
    Node* places = new Node(temps);
    queue -> enqueue(places);
  }
  cout << queue -> peek() << endl;
  
  /*while(queue.peek() != '$') {
    //cout << "print" << endl;
    int out = queue.dequeue();
    //cout << char(out) << endl;
    output[i] = out;
    i++;
  }
  for (int j = 0; j <= i; j++) {
  cout << output[j] << " ";
  Node* node = new Node(output[j]);
  queue.enqueue(node);
  }
  cout << endl;*/
}

bool pcheck(char head, char add) {
  int headp = 0;
  int addp = 0;
  if (head == '+' || head == '-') {
    headp = 1;
  }
  else if (head == '*' || head == '/') {
    headp = 2;
  }
  else if (head == '^') {
    headp = 3;
  }
  else {
    headp = 0;
  }
  if (add == '+' || add == '-') {
    addp = 1;
  }
  else if (add == '*' || add == '/') {
    addp = 2;
  }
  else if (add == '^') {
    addp = 3;
  }
  else if (add == '$') {
    addp = 0;
  }
  //cout << head << " " << add << endl;
  //cout << headp << " " << addp << endl;
  if (addp > headp || add == '^') {
    return true;
  }
  else if (addp <= headp) {
    return false;
  }
  return true;
}

void build(Queue* queue, Stack stack, Node* root) {
  cout << queue -> peek() << endl;
  while (true) {
    //cout << "no" << endl;
    char temp = queue -> peek();
    if (int(temp) >= 48 && int(temp) <= 57) {
      stack.push(queue -> dequeue());
      cout << "Digit" << endl;
    }
    else if (queue -> peek() == '+' ||
	     queue -> peek() == '-' ||
	     queue -> peek() == '*' ||
	     queue -> peek() == '/' ||
	     queue -> peek() == '^') {
      Node* temp = queue -> dequeue();
      if (queue -> peek() == '$') {
	root = temp;
	Node* r = new Node(stack.pop());
	root -> setRight(r);
	r -> setPrev(root);
	Node* l = new Node(stack.pop());
	root -> setLeft(l);
	l -> setPrev(root);
	cout << "root" << endl;
	break;
      }
      else {
	Node* r = new Node(stack.pop());
	temp -> setRight(r);
	r -> setPrev(temp);
	Node* l = new Node(stack.pop());
	temp -> setLeft(l);
	l -> setPrev(temp);
	stack.push(temp);
	cout << "branch" << endl;
      }
    }
    else {
      //cout << "loop" << endl;
      //Node* a = queue.dequeue();
      //delete a;
    }
  }
}

void postf (Node* current) {
  // Similar to heap print ** HINT: USE RECURSION **
}

void pref (Node* current) {
}
