//No Global Variables
//No strings
//Include iostream, not stdio

/*
Samual van Daal
Guessing Game
9/9/2022
 */

// This project is a guessing game where you guess a number between 1 and 100.

#include <iostream>
#include <time.h>

using namespace std;

int main() {// Main Method
  // Setting up variables
  int guess;
  int answer; // Holds rand()
  int guessNumber = 0;
  bool playing = true;
  // Start of game Loop
  while (playing == true) {
    bool win = false;
    srand(time(NULL));
    answer = rand()% 100 + 1; // Random number calcultaion
    cout << "Guess the number between 1 and 100" << endl;
    // Guessing Loop
    while (win == false) {
      cin >> guess;
      if (guess == answer) { // Correct Guess
	cout << "You got right!!!" << endl;
	win = true;
	guessNumber++;
      }
      else if (guess > answer) { // Guess is to high
	cout << "The number is lower" << endl;
	guessNumber++;
      }
      else if (guess < answer) { // Guess is to low
	cout << "The number is higher" << endl;
	guessNumber++;
      }
    }
    // Number of Guesses
    cout << "It took you, " << guessNumber << " Guesses!" << endl;
    // Play again
    cout << "Do you want to keep playing? Type 1 if yes, anything else if you don't." << endl;
    cin >> guess;
    if (guess == 1) { // Yes
      playing = true;
    }
    else { // No
      playing = false;
    }
  }
}
