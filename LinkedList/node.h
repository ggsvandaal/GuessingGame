#include <iostream>
#include <cstring>

using namespace std;

class Node {
public:
  Node(int Value);
  ~Node();
  int getValue();
  void setNext(Node*);
  Node* getNext();
private:
  int value;
  Node* next;
};
