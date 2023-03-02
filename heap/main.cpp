/*
  Heap
  Author: Samual van Daal
  Date: 3/1/2023
*/

#include <iostream>
#include <fstream>
#include <cstring>

using namespace std;

// Function Prototypes
void add(int* a, int b); // Add
void print(int* a, int b, int c); // Print
void remove(int* a); // Remove Root
void rmall(int* a); // Remove All

// Main
int main() {
  
  int heap[101]; // Heap Initialize

  // Setup //
  
  char ask[20];
  int input;
  for (int i = 0; i < 102; i++) {
    heap[i] = 0;
  }
  heap[0] = -1;
  cout << "Type INPUT, REMOVE, REMOVE ALL, PRINT" << endl;
  bool play = true;

  // Main Loop //
  
  while (play == true) {
    cout << ": " ;
    cin.get(ask, 20);
    cin.ignore(10, '\n');
    
    // Typed INPUT
    if (strcmp(ask, "INPUT") == 0) {
      cout << "Input your number" << endl;
      cin >> input;
      cin.ignore(10, '\n');
      add(heap, input); // Add Function
    }
    
    // Typed PRINT
    if (strcmp(ask, "PRINT") == 0) {
      int temp[101];
      for (int i = 0; i < 102; i++) {
	temp[i] = heap[i];
      }
      print(temp, 0, 1); // Print Function
    }
    
    // Typed QUIT
    if (strcmp(ask, "QUIT") == 0) {
      play = false; // End Loop
    }
    
    // Typed REMOVE
    if (strcmp(ask, "REMOVE") == 0) {
      remove(heap); // Remove Root Function
    }
    
    // Typed REMOVE ALL
    if (strcmp(ask, "REMOVE ALL") == 0) {
      rmall(heap); // Remove all function
    }
    
  }
}

// Add Function //

void add(int* heap, int input) {
  int place;
  int temp;

  // Add to Heap
  for (int i = 1; i < 102; i++) { // Loop through heap array
    if (heap[i] == 0) { // Finds closest available spot in the heap
      heap[i] = input; // Add input to heap
      place = i;
      break;
    }
  }

  // Sort
  for (int i = place; i > 1; i--) { // Loop from index of input -> index of root
    if (heap[i] > heap[i/2]) { // If child > parent, Swap their places
      temp = heap[i/2];
      heap[i/2] = heap[i];
      heap[i] = temp;
    }
  }
}

// Print Function //

void print(int* heap, int depth, int current) {

  // Debug Print
  /*
  for (int i = 1; i < 102; i++) {
    cout << heap[i] << " ";
    }
  cout << endl;
  */

  // Tree Print
  
  if (heap[current] == 0 && current != 0) {
    print(heap, depth-1, current/2);
  }

  if (heap[(current*2)+1] != 0) {
    current = (current*2)+1;
    print(heap, depth+1, current);
  }
  
  for (int i = 0; i < depth; i++) {
    cout << '\t';
  }
  cout << heap[current] << endl;
  heap[current] = 0;
  
  if (heap[current*2] != 0) {
    current = current*2;
    print(heap, depth+1, current);
  }

  if (heap[(current*2)+1] == 0 && heap[current*2] == 0) {
    heap[current] = 0;
    current = current/2;
    
    if (heap[1] != 0) {
      print(heap, depth-1, current);
    }
  }
}

// Remove Root Function //

void remove(int* heap) {
  int last;
  int temp;
  int current = 1;

  // Root and Last Swap
  for (int i = 1; i < 102; i++) { // Loop through heap
    if (heap[i+1] == 0) { // Find last filled child
      last = heap[i];
      heap[i] = 0; // Delete last
      break;
    }
  }
  heap[1] = last; // Root = Last

  // Loop until value of last is lower than both of its children
  while(heap[current*2] > heap[current] || heap[(current*2)+1] > heap[current]) {
    int left = heap[current*2];
    int right = heap[(current*2)+1];

    // Left > Right
    if (left > right) { // Swaps Parent with left
      temp = left;
      heap[current*2] = heap[current];
      heap[current] = temp;
      current = current*2;
    }

    // Right > Left
    else if (right > left) { // Swaps Parent with Right
      temp = right;
      heap[(current*2)+1] = heap[current];
      heap[current] = temp;
      current = (current*2)+1;
    }
  }
}

// Remove All Function //

void rmall(int* heap) {
  for (int i = 0; i < 102; i++) { // Loop Through Heap
    heap[i] = 0; // Remove Every value
  }
}
