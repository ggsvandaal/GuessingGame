#include <iostream>
#include <cstring>
#include <vector>
#include <map>
#include "rooms.h"
#include "inventory.h"

using namespace std;
int main() {
  vector<Room*> game;
  Inventory inventory;
  // Setting up Variables
  int currentRoomId = 1;
  bool newRoom = true;
  char north[2] = "n";
  char south[2] = "s";
  char west[2] = "w";
  char east[2] = "e";
  char purpleStone[13] = "Purple Stone";
  char redStone[10] = "Red Stone";
  char greenStone[12] = "Green Stone";
  char pinkStone[11] = "Pink Stone";
  char yellowStone[13] = "Yellow Stone";
  char blueStone[11] = "Blue Stone";
  char orangeStone[13] = "Orange Stone";
  char blackStone[12] = "Black Stone";
  char whiteStone[12] = "White Stone";
  
  cout << "Welcome to ___________" << endl;
  cout << "Type GO then the direction to go through the door in the corresponding direction. EX: GO NORTH. Type INVENTORY to see your inventory. Type QUIT to exit the game." << endl;
  cout << "You wake up in a hospital bed, in an unknown room." << endl;
  
  /*
  Setting Rooms
  */
  
  Room* hospital = new Room(1);
  game.push_back(hospital);
  Room* library = new Room(2);
  game.push_back(library);
  Room* bedroom = new Room(3);
  game.push_back(bedroom);
  Room* office = new Room(4);
  game.push_back(office);
  Room* kitchen = new Room(5);
  game.push_back(kitchen);
  Room* diningRoom = new Room(6);
  game.push_back(diningRoom);
  Room* bathroom = new Room(7);
  game.push_back(bathroom);
  Room* livingRoom = new Room(8);
  game.push_back(livingRoom);
  Room* entranceHall = new Room(9);
  game.push_back(entranceHall);
  Room* strangeHallway = new Room(10);
  game.push_back(strangeHallway);
  Room* dungeon = new Room(11);
  game.push_back(dungeon);
  Room* deepChasm = new Room(12);
  game.push_back(deepChasm);
  Room* executionRoom = new Room(13);
  game.push_back(executionRoom);
  Room* longStairway = new Room(14);
  game.push_back(longStairway);
  Room* reception = new Room(15);
  game.push_back(reception);

  /*
  Setting Room Exits
  */
  
  // Hospital Exits
  hospital -> setExit(north, office);
  hospital -> setExit(west, kitchen);
  hospital -> setExit(south, library);
  hospital -> setExit(east, bedroom);
  // Office Exits
  office -> setExit(south, hospital);
  office -> setExit(west, bathroom);
  office -> setExit(east, livingRoom);
  // Kitchen Exits
  kitchen -> setExit(east, hospital);
  kitchen -> setExit(north, bathroom);
  kitchen -> setExit(south, diningRoom);
  // Library Exits
  library -> setExit(north, hospital);
  library -> setExit(west, diningRoom);
  library -> setExit(east, entranceHall);
  // Bedroom Exits
  bedroom -> setExit(west, hospital);
  bedroom -> setExit(north, livingRoom);
  bedroom -> setExit(south, entranceHall);
  // Dining Room Exits
  diningRoom -> setExit(north, kitchen);
  diningRoom -> setExit(east, library);
  // Bathroom Exits
  bathroom -> setExit(south, kitchen);
  bathroom -> setExit(east, office);
  // Living Room Exits
  livingRoom -> setExit(south, bedroom);
  livingRoom -> setExit(west, office);
  // Entrance Hall Exits
  entranceHall -> setExit(north, bedroom);
  entranceHall -> setExit(west, library);
  // Strange Hallway Exits
  strangeHallway -> setExit(west, entranceHall);
  strangeHallway -> setExit(east, dungeon);
  // Deep Chasm Exit
  deepChasm -> setExit(south, dungeon);
  // Execution Room Exit
  executionRoom -> setExit(west, dungeon);
  // Long Stairway Exits
  longStairway -> setExit(south, executionRoom);
  longStairway -> setExit(north, reception);
  // Reception Exit
  reception -> setExit(south, longStairway);

  /*
  Setting Room Items
  */

  // For some reason, this resulted in a core dump. Don't know why. Halted all progress.
  
  //hospital -> addInventory(redStone);
  //library -> addInventory(purpleStone);
  //bedroom -> addInventory(greenStone);
  //office -> addInventory(pinkStone);
  //kitchen -> addInventory(yellowStone);
  //diningRoom -> addInventory(blueStone);
  //bathroom -> addInventory(orangeStone);
  //livingRoom -> addInventory(blackStone);
  //entranceHall -> addInventory(whiteStone);

  
  /*
  Main Loop  
  */

  bool playing = true;
  while (playing == true) {
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
      vector<Room*>::iterator itr;
      cout << "Bro, ";
      for (itr = game.begin(); itr != game.end(); itr++) {
	cout << (*itr) -> getNumber() << " " << currentRoomId << endl;
	if ((*itr) -> getNumber() == currentRoomId) {
	  Room* tempRoom = (*itr) -> getExit(north);
	  cout << tempRoom -> getNumber() << endl;
	  if (tempRoom -> getNumber() > 0 && tempRoom -> getNumber() < 16) {
	    currentRoomId = tempRoom -> getNumber();
	    cout << currentRoomId << endl;
	    newRoom = true;
	    break;
	  }
	  else {
	    break;
	  }
	}
      }
    }
    else if (strcmp(input, "GO SOUTH") == 0) {
      // if there is an exit
      vector<Room*>::iterator itr;
      for (itr = game.begin(); itr != game.end(); itr++) {
        if ((*itr) -> getNumber() == currentRoomId) {
          Room* tempRoom = (*itr) -> getExit(south);
          currentRoomId = tempRoom -> getNumber();
          cout << currentRoomId << endl;
	  newRoom = true;
	  break;
        }
      }
    }
    else if (strcmp(input, "GO WEST") == 0) {
      // if there is an exit
      vector<Room*>::iterator itr;
      for (itr = game.begin(); itr != game.end(); itr++) {
        if ((*itr) -> getNumber() == currentRoomId) {
          Room* tempRoom = (*itr) -> getExit(west);
          currentRoomId = tempRoom -> getNumber();
          cout << currentRoomId << endl;
          newRoom = true;
          break;
        }
      }
    }
    else if (strcmp(input, "GO EAST") == 0) {
      // if there is an exit
      vector<Room*>::iterator itr;
      for (itr = game.begin(); itr != game.end(); itr++) {
        if ((*itr) -> getNumber() == currentRoomId) {
          Room* tempRoom = (*itr) -> getExit(east);
          currentRoomId = tempRoom -> getNumber();
          cout << currentRoomId << endl;
          newRoom = true;
          break;
        }
      }
    }
    if (strcmp(input, "INVENTORY") == 0) {
      cout << "ROOM INVENTORY -- YOUR INVENTORY" << endl;
      cin.ignore(10, '\n');
      if (strcmp(input, "ROOM INVENTORY")) {
	vector<Room*>::iterator itr;
	for (itr = game.begin(); itr != game.end(); itr++) {
	  if ((*itr) -> getNumber() == currentRoomId) {
	    (*itr) -> printItems();
	  }
	}
      }
      if (strcmp(input, "YOUR INVENTORY")) {
	
      }
    }
    else if (strcmp(input, "QUIT") == 0) {
      playing = false;
    }
  }
}
