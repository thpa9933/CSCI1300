#include "planet.h"

planet::planet(){
    name = "";
    radius = 0.0;
}

planet::planet(string planetName, float planetRadius){
	name = planetName;
	radius = planetRadius;
}

planet::~planet(){

}

void planet::setName(string planetName){
	name = planetName;
}

string planet::getName(){
	return name;
}

void planet::setRadius(float planetRadius){
	radius = planetRadius;
}

float planet::getRadius(){
	return radius;
}

