#include <iostream>
#include <cstring>
#include "media.h"

using namespace std;

class Music : public Media {
public:
  Music(int Type, char* Title, int Year, char* Publisher, int Duration, char* Artist);
  char* getPublisher();
  int getDuration();
  char* getArtist();
protected:
  char publisher[80];
  int duration;
  char artist[80];
};



