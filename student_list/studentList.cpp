#include <iostream>
#include <vector>

using namespace std;

struct Student {
  char name[50];
  char lName[50];
  int id;
  float gpa;
  Student (char firstName[50], char lName, int idNum, float gpaVal) {
    
  }
};

void add(vector <Student> list);

int main() {
  
  vector <Student> list;
  cout << "This is Student List" << endl;
  cout << "To Add a student, enter ADD." << endl
       << "To print the list, enter PRINT." << endl
       << "To delete a student, enter DELETE." << endl
       << "To exit this program, enter QUIT." << endl;
  while(true) {
    char input[8];
    cin.get(input, 8);
    cin.ignore(10, '\n');
    if (input[0] == 'A' &&
	input[1] == 'D' &&
	input[2] == 'D' &&
	input[3] == '\0') {
      cout << "add" << endl;
      add(list);
    }
    else if (input[0] == 'P' &&
	     input[1] == 'R' &&
	     input[2] == 'I' &&
	     input[3] == 'N' &&
	     input[4] == 'T' &&
	     input[5] == '\0') {
      cout << "print" << endl;
    }
  }
}

void add(vector <Student> list) {
  char firstName[50];
  char lastName[50];
  int id;
  float gpa;
  cout << "Student's first name" << endl;
  cin >> firstName >> endl;
  cout << "Student's last name" << endl;
  cin >> lastName >> endl;
  cout << "Student's id number" << endl;
  cin >> id >> endl;
  cout << "Student's gpa" << endl;
  cin >> gpa >> endl;
  
}
