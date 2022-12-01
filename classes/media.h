#include <iostream>
#include <cstring>
#ifndef media
#define media

using namespace std;

class Media {
public:
  Media(int Type, char* Title, int Year);
  int getType();
  char* getTitle();
  int getYear();
protected:
  int type;
  char title[80];
  int year;
};

#endif
