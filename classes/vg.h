#include <iostream>
#include <cstring>
#include "media.h"

using namespace std;

class VG : public Media {
public:
  VG(int Type, char* Title, int Year, char* Publisher, float Rating);
  char* getPublisher();
  float getRating();
protected:
  char publisher[80];
  float rating;
};
