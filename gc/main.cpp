#include <iostream>
#include <vector>
#include <cstring>

using namespace std;

void addVertex(vector<vector<int>>& matrix, vector<char>& nodeList, char label);
void printMatrix(vector<vector<int>> matrix);

int main () {
  vector<vector<int>> matrix;
  vector<char> nodeList;
  char label = 'r';
  
  // Add Vertex
  cin >> label;
  addVertex(matrix, nodeList, label);
  printMatrix(matrix);
  return 0;
}

void addVertex(vector<vector<int>>& matrix, vector<char>& nodeList, char label) {
  nodeList.push_back(label);// add new node to list
  matrix.push_back(vector<int>());// New row to matrix
  for(int r = 0; r < matrix.size() - 1; r++) {
    matrix[matrix.size()-1].push_back(0);
  }
  for(int c = 0; c < matrix.size(); c++) {
    matrix[c].push_back(0);
  }
}

void printMatrix(vector<vector<int>> matrix) {
  for (int r = 0; r < matrix.size(); r++) {
    for (int c = 0; r < matrix[0].size(); c++) {
      cout << matrix[r][c] << " ";
    }
    cout << endl;
  }
  cout << endl;
}
