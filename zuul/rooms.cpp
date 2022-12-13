#include <iostream>
#include <cstring>
#include <vector>
#include <map>
#include "rooms.h"

using namespace std;

Room::Room(char* Name, int Number) {
  strcpy(name, Name);
  number = Number;
};

char* Room::getName() {
  return name;
}

void Room::setExit(char* direction, Room* room) {
  exits.insert(pair<char*, Room*>(direction, room));
}

Room* Room::getExit(char* direction) {
  return exits[direction];
}

char* Room::getExitString() {
  char exitString[80];
  return exitString;
}

bool Room::hasExit(char* direction) {
  return false;
}
