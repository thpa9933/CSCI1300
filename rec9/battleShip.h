#ifndef BATTLESHIP_H
#define BATTLESHIP_H

#include <iostream>
using namespace std;

class battleShip{
	public:
	    battleShip();
		battleShip(string);
		~battleShip();

		void setShipName(string);
		string getShipName();

		void setSize(int);
		int getSize();

		void recordHit();
		bool isSunk();

	private:
		string name;
		int size;
		int hits;
};
#endif // BATTLESHIP_H
