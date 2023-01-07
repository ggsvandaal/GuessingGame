#include <iostream>
#include <cstring>
#include <vector>
#include <map>
#include "rooms.h"

using namespace std;

Room::Room(int Number) {
  number = Number;
};

int Room::getNumber() {
  return number;
}

void Room::setExit(char* direction, Room* room) {
  exits.insert(pair<char*, Room*>(direction, room));
}

Room* Room::getExit(char* direction) {
  return exits[direction];
}

bool Room::hasExit(char* direction) {
  return false;
}

void Room::addInventory(char* item) {
  inventory -> addItem(item);
}

void Room::removeInventory(char* item) {
  inventory -> removeItem(item);
}

void Room::printItems() {
  inventory -> printInventory();
}
