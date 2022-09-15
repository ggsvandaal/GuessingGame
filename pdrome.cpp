

// Palindrome

#include <iostream>
#include <cstring>

using namespace std;

int main() {
  char input[81];
  char check[81];
  char compare[81];
  cout << "Put in a Word, Sentence, or phrase." << endl;
  cout << "This program will tell you if it is a palindrome" << endl;
  cout << "Don't input something longer than 80 characters. If you do your line will be shortened to 80 characters" << endl;
  cin.get(input, 81);
  cin.get();
  int count = 0;
  for (int i = 0; i < 80; i++) {
    if (input[i] != '\0') {
      int ascii = int(input[i]);
      if (ascii > 64 && ascii < 91) {
	ascii += 32;
	//cout << "Ascii value is " << ascii << endl;
	check[count] = char(ascii);
	count++;
      }
      else if (ascii > 96 && ascii < 123) {
	//cout << "Ascii value is " << ascii < endl;
	check[count] = input[i];
	count++;
      }
    }
    else {
      i = 80;
    }
  }
  cout << check << endl;
  count << count << endl;
  for (int i = 0; i < count; i++) {
    if (check[i] != '\0') {
      compare[count] = check[i];
      count--;
    }
    else {
      i = 80;
    }
  }
  cout << compare << endl;
}
