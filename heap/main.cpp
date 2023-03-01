#include <iostream>
#include <fstream>
#include <cstring>

using namespace std;

void add(int* a, int b);

int main() {
  int heap[101];
  char ask[20];
  int input;
  for (int i = 0; i < 102; i++) {
    heap[i] = NULL;
  }
  cout << "Type INPUT, REMOVE, REMOVE ALL, PRINT" << endl;
  bool play = true;
  while (play == true) { 
    cin.get(ask, 20);
    if (strcmp(ask, "INPUT") == 0) {
      cout << "Input your number" << endl;
      cin >> input;
      add(heap, input);
    }
  }
}

void add(int* heap, int input) {
  int place;
  int* temp;
  for (int i = 1; i < 102; i++) {
    if (heap[i] == NULL) {
      heap[i] = input;
      break;
    }
    else {
      cout << "HEAP IS FULL" << endl;
    }
  }
  
}
