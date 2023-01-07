#include <iostream>
#include <cstring>
#include <vector>
#include "inventory.h"

using namespace std;

Inventory::Inventory() {};

void Inventory::addItem(char* item) {
  char* addedItem = new char[strlen(item)];
  strcpy(addedItem, item);
  items.push_back(addedItem);
}

void Inventory::removeItem(char* item) {
  for(vector<char*>::iterator itr = items.begin(); itr != items.end(); itr++) {
    if (strcmp(*itr, item) == 0) {
      delete[] *itr;
      items.erase(itr);
      break;
    }
  }
}

void Inventory::printInventory() {
  for(vector<char*>::iterator itr = items.begin(); itr != items.end(); itr++) {
    cout << " | " << (*itr) << endl;
  }
}
