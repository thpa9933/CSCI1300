#include "battleShip.h"
#include <iostream>
using namespace std;

battleShip::battleShip()
{

}

battleShip::battleShip(string x)
{
    name = x;
    int size = 0;
    int hits = 0;
}

battleShip::~battleShip()
{

}

void battleShip::setShipName(string ship)
{
	name = ship;
}

string battleShip::getShipName()
{
	return name;
}

void battleShip::setSize(int shipSize)
{
	size = shipSize;
}

int battleShip::getSize()
{
	return size;
}

void battleShip::recordHit()
{
	hits++;
}

bool battleShip::isSunk()
{
	if(hits == size)
		return true;
	else
		return false;
}
