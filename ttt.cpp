/*
Author: Samual van Daal
Project: C++ TicTacToe
Date: 10/7/2022
 */

#include <iostream>

using namespace std;
// Setup Functions
void printBoard(char board[3][3], int rows, int columns);
bool checkWin(char player, char board[3][3]);
bool checkTie(char blank, char board[3][3]);

int main () {
  // Initialize variables
  bool stillPlaying = true;
  bool winCheck = false;
  int win = 0;
  const int PLAY = 0;
  const int X_WIN = 1;
  const int O_WIN = 2;
  char board[3][3];
  const char BLANK = ' ';
  const char X_MOVE = 'X';
  const char O_MOVE = 'O';             
  bool xTurn = true;
  bool oTurn = false;
  int xWins = 0;        cin.clear();

  int oWins = 0;

  // Start game loop
  while (stillPlaying == true) {
    // Clear board
    for (int i = 0; i < 3; i++) {
      for (int j = 0; j < 3; j++) {
	board[i][j] = BLANK;
      }
    }
    cout << "TicTacToe!" << endl;
    cout << "enter either a, b, or c then either 1, 2, or 3 to interact with the board" << endl;
    cout << "X will start" << endl;

    win = PLAY;
    // Main game loop
    while (win == PLAY) {
      // input move
      char input[3];
      cin.get(input, 3);
      cin.ignore(10, '\n');
      // Check if input is valid
      if ((input[0] == 'a' || input[0] == 'b' || input[0] == 'c') &&
	  (input[1] == '1' || input[1] == '2' || input[1] == '3')) { // Is valid
	// Set the rows and columns
	int rows = input[0] - 'a';
	int columns = input[1] - '1';
	// Check if space is occupied
	if (board[rows][columns] != BLANK) { // Occupied
	  cout << "This space is occupied, choose a different one" << endl;
	}
	else { // Not Occupied
	  // If its x's turn
	  if (xTurn == true) {
	    // Switch next turn
	    xTurn = false;
	    oTurn = true;
	    board[rows][columns] = X_MOVE; // Set space as X on the board
	    // Check if X wins
	    if (checkWin(X_MOVE, board) == true) {
	      win = X_WIN;
	      xWins++;
	      cout << "X WINS!!!" << endl;
	    }
	  }
	  // If its o's turn
	  else if (oTurn == true) {
	    // Switch next turn
	    xTurn = true;
	    oTurn = false;
	    board[rows][columns] = O_MOVE; // Set space as O on the board
	    // Check if O wins
	    if (checkWin(O_MOVE, board) == true) {
	      win = O_WIN;
	      oWins++;
	      cout << "O WINS!!!" << endl;
	    }
	  }
	  printBoard(board, rows, columns); // print board
	  // Check for a tie
	  if (checkTie(BLANK, board) == true && win == PLAY) {
	    cout << "It's a tie!!" << endl;
	    win = 3;
	  }
	  // Check if someone has won
	  if (win != PLAY) {
	    // Play Again?
	    cout << "Do you want to play again? Answer y or n" << endl;
	    char in[2];
	    cin.get(in, 2);
	    cin.ignore(10, '\n');
	    // Check for yes
	    if (in[0] == 'y') {
	      cout << "X Wins = " << xWins;
	      cout << "      O Wins = " << oWins << endl;
	      xTurn = true;
	      oTurn = false;
	    }
	    // Check for no
	    else if (in[0] == 'n') {
	      stillPlaying = false;
	    }
	  }
	}
      }
      else { // Not valid input
	cin.clear();
	cin.ignore(10, '\n');
	cout << "Input a valid move" << endl;
      }
    }
  }
}

// Function for printing board
void printBoard(char board[3][3], int rows, int columns) {
  cout << " \t1\t2\t3" << endl;
  cout << "a\t" << board[0][0] << "\t" << board[0][1] << "\t" << board[0][2] << endl << endl;
  cout << "b\t" << board[1][0] << "\t" << board[1][1] << "\t" << board[1][2] << endl << endl;
  cout << "c\t" << board[2][0] << "\t" << board[2][1] << "\t" << board[2][2] << endl;
}

// Function for checking win
bool checkWin(char player, char board[3][3]) {
  if (board[0][0] == player && board[0][1] == player && board[0][2] == player) {
    return true;
  }
  if (board[1][0] == player && board[1][1] == player && board[1][2] == player) {
    return true;
  }
  if (board[2][0] == player && board[2][1] == player && board[2][2] == player) {
    return true;
  }
  if (board[0][0] == player && board[1][0] == player && board[2][0] == player) {
    return true;
  }
  if (board[0][1] == player && board[1][1] == player && board[2][1] == player) {
    return true;
  }
  if (board[0][2] == player && board[1][2] == player && board[2][2] == player) {
    return true;
  }
  if (board[0][0] == player && board[1][1] == player && board[2][2] == player) {
    return true;
  }
  if (board[0][2] == player && board[1][1] == player && board[2][0] == player) {
    return true;
  }
  return false;
}

// Function for checking tie
bool checkTie(char blank, char board[3][3]) {
  for (int i = 0; i < 3; i++) {
    for (int j = 0; j < 3; j++) {
      if (board[i][j] == blank) {
	return false;
      }
    }
  }
  return true;
}
