#include <iostream>
#include <vector>
#include <cstring>

using namespace std;

struct Student {
  char firstName[50];
  char lastName[50];
  int id;
  float gpa;
  Student (char *name, char *lName, int idNum, float gpaVal) {
    strcpy(firstName, name);
    strcpy(lastName, lName);
    id = idNum;
    gpa = gpaVal;
  }
};

void add(vector<Student*> &list);
void print(vector<Student*> &list);

int main() {
  bool thing = true;
  vector <Student*> list;
  cout << "This is Student List" << endl;
  cout << "To Add a student, enter ADD." << endl
       << "To print the list, enter PRINT." << endl
       << "To delete a student, enter DELETE." << endl
       << "To exit this program, enter QUIT." << endl;
  while(thing == true) {
    char input[8];
    cin.get(input, 8);
    cin.ignore(10, '\n');
    if (input[0] == 'A' &&
	input[1] == 'D' &&
	input[2] == 'D' &&
	input[3] == '\0') {
      add(list);
      thing = true;
    }
    if (input[0] == 'P' &&
	input[1] == 'R' &&
	input[2] == 'I' &&
	input[3] == 'N' &&
	input[4] == 'T' &&
	input[5] == '\0') {
      print(list);
    }
    if (strcmp(input, "DELETE") {
      
    }
  }
}

void add(vector<Student*> &list) {
  cout << "add" << endl;
  char firstName[50];
  char lastName[50];
  int id;
  float gpa;
  cout << "Student's first name" << endl;
  cin >> firstName;
  cout << "Student's last name" << endl;
  cin >> lastName;
  cout << "Student's id number" << endl;
  cin >> id;
  cout << "Student's gpa" << endl;
  cin >> gpa;
  cin.ignore(10, '\n');
  Student* s = new Student(firstName, lastName, id, gpa);
  list.push_back(s);
}

void print(vector<Student*> &list) {
  cout << "print" << endl;
  vector<Student*>::iterator itr;
  for (itr = list.begin(); itr < list.end(); itr++) {
    cout << "Name: " << (*itr) -> firstName << " " << (*itr) -> lastName << "   Student ID Number: " << (*itr) -> id << "   GPA: " << (*itr) -> gpa << endl;
  }
}
