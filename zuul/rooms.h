#include <iostream>
#include <cstring>
#include <vector>
#include <map>
#include "inventory.h"

using namespace std;

class Room {
public:
  Room(char* Name, int Number);
  int getNumber();
  char* getName();
  void setExit(char* direction, Room* room);
  Room* getExit(char* direction);
  char* getExitString();
  bool hasExit(char* direction);
  void addInventory(char* item);
  void removeInventory(char* item);
protected:
  int number;
  char name[80];
  Inventory inventory;
  map<char*, Room*> exits;
};
