// Palindrome
// Author: Samual van Daal
// Date: 9/21/2022

// This program allows you to input a phrase or sentence and it will tell you if it is a palindrome or not

#include <iostream>
#include <cstring>

using namespace std;

int main() {
  // Initial variable initalization
  char input[81];
  char check[81];
  char compare[81];
  bool pdrome = true;
  // Rules and Information
  cout << "Put in a Word, Sentence, or phrase." << endl;
  cout << "This program will tell you if it is a palindrome" << endl;
  cout << "Don't input something longer than 80 characters. If you do your line will be shortened to 80 characters" << endl;
  cout << "Numbers arent valid characters, and if no valid characters are inputed, it will be a palindrome by default" << endl;
  // User Input
  cin.get(input, 81);
  cin.get();
  int count = 0;
  // Remove Spaces & Special Characters and puts chars into the same case
  for (int i = 0; i < 80; i++) {
    if (input[i] != '\0') {
      int ascii = int(input[i]);
      if (ascii > 64 && ascii < 91) { // Uppercase Characters
	ascii += 32;
	check[count] = char(ascii);
	count++;
      }
      else if (ascii > 96 && ascii < 123) { // Lowercase Characters
	check[count] = input[i];
	count++;
      }
    }
    else {
      i = 80;
    }
  }
  // New variable initalization
  int countOld = count;
  int countNew = count - 1;
  // Dupliclates and flips input 
  for (int i = 0; i < countOld; i++) {
    if (check[i] != '\0') { // If its not the end of the input
      compare[countNew] = check[i];
      countNew--;
    }
    else { // End of the input
      count++;
      compare[count] = '\0';
      i = countOld;
    }
  }
  // Palindrome Check
  for (int i = 0; i < count-1; i++) {
    int chAscii = int(check[i]);
    int coAscii = int(compare[i]);
    if (chAscii != coAscii) { // Not a palindrome check
      cout << "Not a Palindrome" << endl;
      pdrome = false;
      i = 81;
    }
  }
  if (pdrome == true) { // Palindrome Check
    cout << "Palindrome!" << endl;
  }
}
