#include <iostream>
#include <cstring>
#include "movies.h"

using namespace std;

Movie::Movie(int Type, char* Title, int Year, char* Director, int Duration, float Rating):Media(Type , Title, Year) {
  strcpy(director, Director);
  duration = Duration;
  rating = Rating;
  type = 3;
};

char* Movie::getDirector() {
  return director;
}

int Movie::getDuration() {
  return duration;
}

float Movie::getRating() {
  return rating;
}



