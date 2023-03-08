#include <iostream>
#include <cstring>
#include "node.h"
#include "stack.h"
#include "queue.h"

void alg(char* a, char* b, Stack c, Queue d);

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
	variable == '^' ||
	variable == '(') {
      Node* node = new Node(variable);
      stack.push(node);
    }
    if (isdigit(variable) == true) {
      Node* add = new Node(variable);
      queue.enqueue(add);
    }
  }
  
  cout << output << endl;
}
