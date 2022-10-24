/*
Author: Samual van Daal
Project: Student List
Date: 10/24/2022
 */

#include <iostream>
#include <vector>
#include <cstring>

using namespace std;

// Struct Setup for Student
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

// Initialize Fuctions
void add(vector<Student*> &list);
void print(vector<Student*> &list);
void del(vector<Student*> &list);

// Main function
int main() {
  bool thing = true;
  // Setup a vector of Students called list
  vector <Student*> list;
  // Instructions
  cout << "This is Student List" << endl;
  cout << "To Add a student, enter ADD." << endl
       << "To print the list, enter PRINT." << endl
       << "To delete a student, enter DELETE." << endl
       << "To exit this program, enter QUIT." << endl;
  // Main loop
  while(thing == true) {
    char input[8];
    cin.get(input, 8);
    cin.ignore(10, '\n');
    // If input is ADD
    if (strcmp(input, "ADD") == 0) {
      add(list);
    }
    // If input is PRINT
    if (strcmp(input, "PRINT") == 0) {
      print(list);
    }
    // If input is DELETE
    if (strcmp(input, "DELETE") == 0) {
      del(list);
    }
    // If input is QUIT
    if (strcmp(input, "QUIT") == 0) {
      thing = false;
    }
  }
}

// ADD function
void add(vector<Student*> &list) {
  //cout << "add" << endl;
  // variable initalization
  char firstName[50];
  char lastName[50];
  int id;
  float gpa;
  // inputing values
  cout << "Student's first name" << endl;
  cin.get(firstName, 50);
  cin.ignore(50, '\n');
  cout << "Student's last name" << endl;
  cin.get(lastName, 50);
  cin.ignore(50, '\n');
  cout << "Student's id number" << endl;
  cin >> id;
  cout << "Student's gpa" << endl;
  cin >> gpa;
  cin.ignore(10, '\n');
  // Setting a new student equal to previous values
  Student* s = new Student(firstName, lastName, id, gpa);
  list.push_back(s);
}

// PRINT function
void print(vector<Student*> &list) {
  //cout << "print" << endl;
  // Iterator Setup
  vector<Student*>::iterator itr;
  //Iterator loop prints every student in the vector
  for (itr = list.begin(); itr < list.end(); itr++) {
    cout << "Name: " << (*itr) -> firstName << " " << (*itr) -> lastName << "   Student ID Number: " << (*itr) -> id << "   GPA: " << (*itr) -> gpa << endl;
  }
}

// DELETE function
void del(vector<Student*> &list) {
  // input value of deletion target
  int target;
  cout << "Enter the student's id you'd like to delete" << endl;
  cin >> target;
  cin.ignore(10, '\n');
  // Iterator setup
  vector<Student*>::iterator itr;
  // Iterator loop checks which students id value matches target, then deletes that student
  for (itr = list.begin(); itr < list.end(); itr++) {
    if (target == (*itr) -> id) {
      list.erase(itr);
      cout << "Student " << target << " was deleted" << endl; 
      break;
    }
  }
}
