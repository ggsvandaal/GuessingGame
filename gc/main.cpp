/*
Author: Samual van Daal
Date: 5/25/2023
Project: Graph Creator
*/

#include <iostream>
#include <vector>
#include <cstring>

using namespace std;

// Function Prototypes //

void addVertex(vector<vector<int>>& matrix, vector<char*>& nodeList, char* label);
void addEdge(vector<vector<int>>& matrix, vector<char*> nodeList, char* a, char* b, int c);
void deleteEdge(vector<vector<int>>& matrix, vector<char*> nodeList, char* a, char* b);
void delVert(vector<vector<int>>& matrix, vector<char*>& nodeList, char* a);
void printMatrix(vector<vector<int>> matrix, vector<char*> nodeList);


// Main Function //

int main () {
  // Important Initalizations
  vector<vector<int>> matrix;
  vector<char*> nodeList;
  char input[80];

  // Main Loop
  while (true) {
    cout << "Commands: ADD VERTEX, ADD EDGE, DELETE VERTEX, DELETE EDGE, PRINT, FIND SHORTEST, and QUIT" << endl;
    cin.get(input, 80);
    cin.ignore(10, '\n');

    // Add Vertex Input
    if (strcmp(input, "ADD VERTEX") == 0) {
      char* label = new char[20];
      cout << "What do you want to call this vertex?" << endl;
      cin.get(label, 20);
      cin.ignore(10, '\n');
      addVertex(matrix, nodeList, label);
    }

    // Add Edge Input
    if (strcmp(input, "ADD EDGE") == 0) {
      char* a = new char[20];
      char* b = new char[20];
      int weight;
      cout << "Between Vertex 1: ";
      cin.get(a, 20);
      cin.ignore(10, '\n');
      cout << "And 2: ";
      cin.get(b, 20);
      cin.ignore(10, '\n');
      cout << "At a weight of: ";
      cin >> weight;
      cin.ignore(10, '\n');
      addEdge(matrix, nodeList, a, b, weight);
    }

    // Delete Vertex Input
    if (strcmp(input, "DELETE VERTEX") == 0) {
      char* a = new char[20];
      cout << "Which vertex do you want to delete?" << endl;
      cin.get(a, 20);
      cin.ignore(10, '\n');
      delVert(matrix, nodeList, a);
    }

    // Delete Edge Input
    if (strcmp(input, "DELETE EDGE") == 0) {
      char* a = new char[20];
      char* b = new char[20];
      int weight;
      cout << "Between Vertex 1: ";
      cin.get(a, 20);
      cin.ignore(10, '\n');
      cout << "And 2: ";
      cin.get(b, 20);
      cin.ignore(10, '\n');
      deleteEdge(matrix, nodeList, a, b);
    }

    // Print Input
    if (strcmp(input, "PRINT") == 0) {
      printMatrix(matrix, nodeList);
    }

    // Quit Input
    if (strcmp(input, "QUIT") == 0) {
      return 0;
    }
  }
  return 0;
}

// Add Vertex Function //

void addVertex(vector<vector<int>>& matrix, vector<char*>& nodeList, char* label) {
  nodeList.push_back(label);// add new node to list
  matrix.push_back(vector<int>());// New row to matrix
  for(int r = 0; r < matrix.size() - 1; r++) {
    matrix[matrix.size()-1].push_back(0);
  }
  for(int c = 0; c < matrix.size(); c++) {
    matrix[c].push_back(0);
  }
}

// Add Edge Function //

void addEdge(vector<vector<int>>& matrix, vector<char*> nodeList, char* a, char*b, int weight) {
  int av = -1;
  int bv = -1;
  for (int i = 0; i < nodeList.size(); i++) {
    if (strcmp(nodeList[i], a) == 0) {
      av = i;
    }
    if (strcmp(nodeList[i], b) == 0 ) {
      bv = i;
    }
  }
  if (av == -1 || bv == -1) {
    cout << "One of your inputed vertex's doesn't exist" << endl;
  }
  else {
    matrix[av][bv] = weight;
  }
}

// Delete Edge Function //

void deleteEdge(vector<vector<int>>& matrix, vector<char*> nodeList, char* a, char*b) {
  int av = -1;
  int bv = -1;
  for (int i = 0; i < nodeList.size()-1; i++) {
    if (strcmp(nodeList[i], a) == 0) {
      av = i;
    }
    if (strcmp(nodeList[i], b) == 0 ) {
      bv = i;
    }
  }
  if (av == -1 || bv == -1) {
    cout << "One of your inputed vertex's doesn't exist" << endl;
  }
  else {
    matrix[av][bv] = 0;
  }
}

void delVert(vector<vector<int>>& matrix, vector<char*>& nodeList, char* input) {
  cout << "Not currently working" << endl;
  /*
  vector<vector<int>>::iterator itr1;
  vector<int>::iterator itr2;
  vector<char*>::iterator itrc;
  int a = 1;
  int b = 0;
  for (itrc = nodeList.begin(); itrc != nodeList.end(); itrc++) {
    if (strcmp(*itrc, input) == 0) {
      nodeList.erase(itrc);
      break;
    }
  }
  int size = matrix.size();
  for (itr1 = matrix.begin(); itr1 != matrix.end(); itr1++) {
    cout << "Got here" << endl;
    for (itr2 = itr1->begin(); itr2 != itr1->end(); itr2++) {
      cout << *itr2 << endl;
      if (b == a) { // Problem Child
	matrix[a].erase(itr2);
	return;
      }
    }
  }
  for (itr1 = matrix.begin(); itr1 != matrix.end(); itr1++) {
    if (b == a) { // Problem Child
      matrix.erase(itr1);
      return;
    }
  }
  */
}

// Print Matrix Function //

void printMatrix(vector<vector<int>> matrix, vector<char*> nodeList) {
  cout << "  ";
  for (int i = 0; i < nodeList.size(); i++) {
    cout << nodeList[i] << " ";
  }
  cout << endl;
  for (int r = 0; r < matrix.size(); r++) {
    cout << nodeList[r] << " ";
    for (int c = 0; c < matrix[0].size(); c++) {
      cout << matrix[r][c] << " ";
    }
    cout << endl;
  }
  cout << endl;
}
