

// Palindrome

#include <iostream>
#include <cstring>

using namespace std;

int main() {
  char input[81];
  char check[81];
  cout << "Put in a Word, Sentence, or phrase." << endl;
  cout << "This program will tell you if it is a palindrome" << endl;
  cout << "Don't input something longer than 80 characters. If you do your line will be shortened to 80 characters" << endl;
  cin.get(input, 81);
  cin.get();
  cout << input << endl;
  int count = 0;
  for (int i = 0; i < 80; i++) {
    cout << "Ascii value of " << input[i] << " is equal to: " << int(input[i]) << endl;
    if (int(input[i]) > 64 && int(input[i]) < 91) {
      int(input[i]) += 32;
      check[count] = input[i];
      count++;
    }
    else if (int(input[i]) > 96 && int(input[i]) < 123) {
      check[count] = input[i];
      count++;
    }
  }
  // Add ending char to check
  cout << check << endl;
}
