#include <iostream>
#include <cstring>
#include "music.h"

using namespace std;

Music::Music(int Type, char* Title, int Year, char* Publisher, int Duration, char* Artist):Media(Type , Title, Year) {
  strcpy(publisher, Publisher);
  strcpy(artist, Artist);
  duration = Duration;
  type = 2;
};

char* Music::getPublisher() {
  return publisher;
}

int Music::getDuration() {
  return duration;
}

char* Music::getArtist() {
  return artist;
}



