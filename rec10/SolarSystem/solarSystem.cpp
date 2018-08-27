#include "solarSystem.h"
#include "planet.h"
#include <math.h>

solarSystem::solarSystem(string name)
{
    systemName = name;
    int numPlanets = 0;
    int maxNumPlanets = 10;
}

solarSystem::~solarSystem()
{

}

string solarSystem::getName()
{
    return systemName;
}

int solarSystem::getNumPlanets()
{
    return numPlanets;
}

bool solarSystem::addPlanet(string planetName, float planetRadius)
{
    planet myPlanet(planetName, planetRadius);
    if(numPlanets < maxNumPlanets)
    {
        systemPlanets[numPlanets] = myPlanet;
        numPlanets++;
        return true;
    }
    else
    {
        return false;
    }
}

planet solarSystem::getPlanet(int p)
{
    return systemPlanets[p];
}

float solarSystem::radiusDifference(planet planet1, planet planet2)
{
    float r1 = planet1.getRadius();
    float r2 = planet2.getRadius();
    float diff = fabs(r2 - r1);
    return diff;
}
