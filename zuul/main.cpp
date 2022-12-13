#include <iostream>
#include <cstring>
#include <vector>
#include <map>
#include "rooms.h"



int main() {
  int currentRoomId = 1;
  bool newRoom = true;
  char north[2] = "n";
  char south[2] = "s";
  char west[2] = "w";
  char east[2] = "e";
  char h[2] = "h";
  char l[2] = "l";
  char b[2] = "b";
  char o[2] = "o";
  char k[2] = "k";
  int id;
  cout << "Welcome to ___________" << endl;
  cout << "Type GO then the direction to go through the door in the corresponding direction. EX: GO NORTH. Type ITEM to pickup the item in the room. Type INVENTORY to see your inventory. Type QUIT to exit the game." << endl;
  cout << "You wake up in a hospital bed, in an unknown room." << endl;
  // Setting Rooms
  id = 1;
  Room* hospital = new Room(h, id);
  id = 2;
  Room* library = new Room(l, id);
  id = 3;
  Room* bedroom = new Room(b, id);
  id = 4;
  Room* office = new Room(o, id);
  id = 5;
  Room* kitchen = new Room(k, id);
  
  // Setting Room Exits
  hospital -> setExit(north, office);
  hospital -> setExit(west, kitchen);
  hospital -> setExit(south, library);
  hospital -> setExit(east, bedroom);

  while (true) {
    if (currentRoomId == 1 && newRoom == true) {
      cout << "Its a hospital room. The walls are completely white. It contains an ICU bed, hospital machinery, and a bedside table, which has a suspicious red stone on top of it. There is a door in every direction. On top of that, there is a riddle on the wall." << endl;
      cout << "Riddle: In an unfamiliar place, yourself, you find. Gather the colored rocks inside each room. Use them to open the doors that bind. Else face your impending doom." << endl;
      newRoom = false;
    }
  }
}
