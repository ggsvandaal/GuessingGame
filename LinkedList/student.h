#include <iostream>
#include <cstring>

using namespace std;

class Student {
public:
  Student(char* Name, char* Lastname, int Id, float GPA);
  ~Student();
  char* getName();
  char* getLastname();
  int getId();
  float getGPA();
private:
  char name[80];
  char lastname[80];
  int id;
  float gpa;
};
