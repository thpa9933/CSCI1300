#ifndef DESTROYER_H
#define DESTROYER_H
#include <iostream>
using namespace std;

class Destroyer{
public:

  Destroyer(); //default
  ~Destroyer();

  void setDestroyerName(string); //sets players name
  string getDestroyerName(); //gets players name
  void setMoveLeft(int);
  void setMoveRight(int);
  int getMoveLeft();
  int getMoveRight();
  int MOVE;
  string name;

};
#endif



