#include <iostream>
#include <cstring>
#include "media.h"

using namespace std;

Media::Media(int Type, char* Title, int Year) {
  strcpy(title, Title);
  type = Type;
  year = Year;
  //cout << title << endl;
  //cout << type << endl;
  //cout << year << endl;
};

int Media::getType() {
  return type;
}

char* Media::getTitle() {
  return title;
}

int Media::getYear() {
  return year;
}
