#include <iostream>
#include <cstring>

using namespace std;

class Node { // Node Class
public:
  Node(int number); // Node Constructor
  ~Node(); // Destructor
  int getNumber(); // get student*
  void setNext(Node*); // Set the next node
  Node* getNext(); // Get the next node
private:
  Node* next;
  int number;
};

