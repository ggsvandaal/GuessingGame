#include <iostream>
#include <cstring>
#include <vector>
#include <map>
#include "rooms.h"
#include "inventory.h"

using namespace std;
vector<Room*> game;
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
  game.push_back(hospital);
  id = 2;
  Room* library = new Room(l, id);
  game.push_back(library);
  id = 3;
  Room* bedroom = new Room(b, id);
  game.push_back(bedroom);
  id = 4;
  Room* office = new Room(o, id);
  game.push_back(office);
  id = 5;
  Room* kitchen = new Room(k, id);
  game.push_back(kitchen);
  
  // Setting Room Exits
  hospital -> setExit(north, office);
  hospital -> setExit(west, kitchen);
  hospital -> setExit(south, library);
  hospital -> setExit(east, bedroom);

  while (true) {
    char input[80];
    if (currentRoomId == 1 && newRoom == true) {
      cout << "Its a hospital room. The walls are completely white. It contains an ICU bed, hospital machinery, and a bedside table, which has a suspicious red stone on top of it. There is a door in every direction. On top of that, there is a riddle on the wall." << endl;
      cout << "Riddle: In an unfamiliar place, yourself, you find. Gather the colored rocks inside each room. Use them to open the doors that bind. Else face your impending doom." << endl;
      newRoom = false;
      cout << "What do you want to do?" << endl;
    }
    cin.get(input, 80);
    cin.ignore(10, '\n');
    if (strcmp(input, "GO NORTH") == 0) {
      // if there is an exit
      cout << "in" << endl;
      vector<Room*>::iterator itr;
      for (itr = game.begin(); itr != game.end(); itr++) {
	if ((*itr) -> getNumber() == currentRoomId) {
	  Room* tempRoom = (*itr) -> getExit(north);
	  currentRoomId = tempRoom -> getNumber();
	  cout << currentRoomId << endl;
	}
      }
    }
    if (strcmp(input, "ITEM") == 0) {
    }
  }
}
