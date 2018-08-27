#include <iostream>
#include "Destroyer.h"

using namespace std;

//Sets initial values to Destroyer class
Destroyer::Destroyer()
{
    MOVE = 20; //X (column) position of destroyer
    name = "";
}

Destroyer::~Destroyer()
{
    //dest
}


void Destroyer::setDestroyerName(string x)
{
    name = x;
}

string Destroyer::getDestroyerName()
{
    return name;
}

void Destroyer::setMoveRight(int y)     //Move is just an integer initialized at 20,
{                                       //Its value remains set when each turn is played
        MOVE = MOVE + y;                //The value is the value of columns on the board, where the destroyer is
}

void Destroyer::setMoveLeft(int y)
{
        MOVE = MOVE - y;
}

int Destroyer::getMoveRight()
{
    return MOVE;
}

int Destroyer::getMoveLeft()
{
    return MOVE;
}




