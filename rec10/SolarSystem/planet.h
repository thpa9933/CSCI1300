#ifndef PLANET_H
#define PLANET_H
#include <string>
#include <iostream>
using namespace std;

class planet{
public:
    string planetName;
    float planetRadius;
    planet();
    planet(string, float);
    ~planet();

    void setName(string);
    string getName();
    void setRadius(float);
    float getRadius();

private:
    string name;
    float radius;

};
#endif
