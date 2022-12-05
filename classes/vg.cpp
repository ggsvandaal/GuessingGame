#include <iostream>
#include <cstring>
#include "vg.h"

using namespace std;

VG::VG(int Type, char* Title, int Year, char* Publisher, float Rating):Media(Type, Title, Year) {
  strcpy(publisher, Publisher);
  rating = Rating;
  type = 1;
};

char* VG::getPublisher() {
  return publisher;
}

float VG::getRating() {
  return rating;
}
