#include <iostream>
#include <cstring>
#include <vector>
#include <map>
#include "inventory.h"

using namespace std;

class Room {
public:
  Room(int Number);
  int getNumber();
  void setExit(char* direction, Room* room);
  Room* getExit(char* direction);
  char* getExitString();
  bool hasExit(char* direction);
  void addInventory(char* item);
  void removeInventory(char* item);
  void printItems();
protected:
  int number;
  Inventory* inventory;
  map<char*, Room*> exits;
};
