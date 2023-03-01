#include <iostream>
#include <fstream>
#include <cstring>

using namespace std;

void add(int* a, int b);
void print(int* a);
void remove(int* a);
void rmall(int* a);

int main() {
  int heap[101];
  char ask[20];
  int input;
  for (int i = 0; i < 102; i++) {
    heap[i] = 0;
  }
  cout << "Type INPUT, REMOVE, REMOVE ALL, PRINT" << endl;
  bool play = true;
  while (play == true) {
    cout << ": " ;
    cin.get(ask, 20);
    cin.ignore(10, '\n');
    if (strcmp(ask, "INPUT") == 0) {
      cout << "Input your number" << endl;
      cin >> input;
      cin.ignore(10, '\n');
      add(heap, input);
    }
    if (strcmp(ask, "PRINT") == 0) {
      print(heap);
    }
    if (strcmp(ask, "QUIT") == 0) {
      play = false;
    }
    if (strcmp(ask, "REMOVE") == 0) {
      remove(heap);
    }
    if (strcmp(ask, "REMOVE ALL") == 0) {
      rmall(heap);
    }
  }
}

void add(int* heap, int input) {
  int place;
  int temp;
  for (int i = 1; i < 102; i++) {
    if (heap[i] == 0) {
      heap[i] = input;
      place = i;
      break;
    }
  }
  for (int i = place; i > 1; i--) {
    if (heap[i] > heap[i/2]) {
      temp = heap[i/2];
      heap[i/2] = heap[i];
      heap[i] = temp;
    }
  }
}

void print(int* heap) {
  for (int i = 1; i < 102; i++) {
    cout << heap[i] << " ";
  }
  cout << endl;
}

void remove(int* heap) {
  int last;
  int temp;
  int current = 1;
  for (int i = 1; i < 102; i++) {
    if (heap[i+1] == 0) {
      last = heap[i];
      heap[i] = 0;
      break;
    }
  }
  heap[1] = last;
  while(heap[current*2] > heap[current] || heap[(current*2)+1] > heap[current]) {
    int left = heap[current*2];
    int right = heap[(current*2)+1];
    if (left > right) {
      temp = left;
      heap[current*2] = heap[current];
      heap[current] = temp;
      current = current*2;
    }
    else if (right > left) {
      temp = right;
      heap[(current*2)+1] = heap[current];
      heap[current] = temp;
      current = (current*2)+1;
    }
  }
}


void rmall(int* heap) {
  for (int i = 0; i < 102; i++) {
    heap[i] = 0;
  }
}
