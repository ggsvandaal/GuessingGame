#include <iostream>
#include <cstring>
#include "student.h"

using namespace std;

Student::Student(char* Name, char* Lastname, int Id, float GPA) {
  strcpy(name, Name);
  strcpy(lastname, Lastname);
  id = Id;
  gpa = GPA;
}

char* Student::getName() {
  return name;
}

char* Student::getLastname() {
  return lastname;
}

int Student::getId() {
  return id;
}

float Student::getGPA() {
  return gpa;
}

Student::~Student() {
  delete name;
  delete lastname;
}
