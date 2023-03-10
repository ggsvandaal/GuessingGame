#include <iostream>
#include <cstring>
#include "node.h"
#include "stack.h"
#include "queue.h"

void alg(char* a, char* b, Stack c, Queue d);
bool pcheck(char a, char b);

using namespace std;

int main() {
  Stack stack;
  Queue queue;
  char input[80];
  char equation[80];
  char postfix[80];
  cout << "Do you want to INPUT, or find the PREFIX/INFIX/POSTFIX?" << endl;
  cin.get(input, 80);
  cin.ignore(10, '\n');
  if (strcmp(input, "INPUT") == 00) {
    cout << "Input an infix equation!" << endl;
    cin.get(equation, 80);
    cin.ignore(10, '\n');
    alg(equation, postfix, stack, queue);
  } 
}

void alg(char* input, char* output, Stack stack, Queue queue) {
  int place = 0;
  for (int i = 0; i < 81; i++) {
    char variable = input[i];
    if (variable == '*' ||
	variable == '/' ||
	variable == '+' ||
	variable == '-' ||
	variable == '^') {
      if (pcheck(stack.peek(), variable) == false) {
	if (stack.peek() != '$') {
	  char temp = stack.pop();
	  Node* place = new Node(temp);
	  queue.enqueue(place);
	  Node* node = new Node(variable);
	  stack.push(node);
	  cout << "pcheck false" << endl;
	}
      }
      else if (pcheck(stack.peek(), variable) == true) {
        Node* node = new Node(variable);
        stack.push(node);
	cout << "pcheck true" << endl;
      }
    }
    if (variable == '(') {
      Node* node = new Node(variable);
      stack.push(node);
    }
    
    if (isdigit(variable) == true) {
      Node* add = new Node(variable);
      queue.enqueue(add);
      cout << "isdigit" 
<< endl;
    }
    if (variable == ')') {
      bool truth = true;
      while (truth == true) {
	char temp = stack.pop();

	if (temp != '(') {
	  Node* place = new Node(temp);
	  queue.enqueue(place);
	  cout << ") check" << endl;
	}
	else {
	  truth = false;
	}
      }
      char l = stack.pop();
    }
    cout << "for" << endl;
  }
  while(stack.peek() != '$') {
    cout << "placing stack" << endl;
    char temps = stack.pop();
    Node* places = new Node(temps);
    queue.enqueue(places);
  }
  int i = 0;
  while(queue.peek() != '$') {
    cout << "print" << endl;
    int out = queue.dequeue();
    output[i] = out;
    i++;
  }
  for (int j = 0; j <= i; j++) {
    cout << output[j] << " ";
  }
  cout << endl;
}

bool pcheck(char head, char add) {
  int headp;
  int addp;
  if (head == '+' || head == '-') {
    int headp = 1;
  }
  else if (head == '*' || head == '/') {
    int headp = 2;
  }
  else if (head == '^') {
    int headp = 3;
  }
  else if (head == '$') {
    int headp = 0;
  }
  if (add == '+' || add == '-') {
    int addp = 1;
  }
  else if (add == '*' || add == '/') {
    int addp = 2;
  }
  else if (add == '^') {
    int addp = 3;
  }
  else if (add == '$') {
    int addp = 0;
  }

  if (addp >= headp) {
    return true;
  }
  else if (addp < headp) {
    return false;
  }
  return true;
}
