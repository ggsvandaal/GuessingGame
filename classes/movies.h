#include <iostream>
#include <cstring>
#include "media.h"

using namespace std;

class Movie : public Media {
public:
  Movie(int Type, char* Title, int Year, char* Director, int Duration, float Rating);
  char* getDirector();
  int getDuration();
  float getRating();
protected:
  char director[80];
  int duration;
  float rating;
};
