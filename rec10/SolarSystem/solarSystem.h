#ifndef SOLAR_SYSTEM_H
#define SOLAR_SYSTEM_H

#include <string>
#include <iostream>
#include "planet.h"
using namespace std;

class solarSystem{
	public:
	    solarSystem();
		solarSystem(string);
		~solarSystem();

		string getName();			// return the name of the solar system
		int getNumPlanets();		// return the number of planets in the system
		bool addPlanet(string, float);	//Adds a single planet to solar system
        planet getPlanet(int);  	// return an object of planet at provided index
        float radiusDifference(planet, planet);

	private:
	    int numPlanets = 0;
		int maxNumPlanets = 10;
		string systemName;
		planet systemPlanets[10]; // array of object planet, each obj is a planet

};
#endif // SOLAR_SYSTEM_H
