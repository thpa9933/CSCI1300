#ifndef INVADER_H
#define INVADER_H
#include <iostream>
using namespace std;
//#include "GameBoard.h"

class Invader{
public:
  Invader(); //initialize random postion in grid
  ~Invader();

  bool Fire(char);
  int countFire; //increase number of invaders appear on each new line
  int GetCountFire();
};
#endif

