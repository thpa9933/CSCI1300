#include <iostream>
#include "planet.h"
#include "solarSystem.h"
#include <math.h>
using namespace std;



    void compareRadii(solarSystem mySolarsystem, int num_of_planets)
    {
        for(int i = 0; i < num_of_planets; i++)
        {
            for(int j = i+1; j < num_of_planets; j++)
            {
                planet x = mySolarsystem.getPlanet(i);
                planet z = mySolarsystem.getPlanet(j);
                float diff;
                diff=mySolarsystem.radiusDifference(x, z);
               // cout << "Radius difference between planet " << x.getName() << " and planet " << z.getName() << " is => " <<diff<<endl;
                cout<<"Radius difference between planet " << x.getName() <<" and planet "<<z.getName() <<" is => "<<diff<<endl;
            }
        }
    }

int main()
{

    //void compareRadii(solarSystem mySolarSystem, int num_of_planets);
/*
    string newPlanet;
    int radius;
    solarSystem sol1 = solarSystem("solarSystem");
    for(int i = 0; i < 5; i++)
    {
        cout<< "Enter a planet" <<endl;
        cin >> newPlanet;
        cout << "Enter the planet radius" <<endl;
        cin >> radius;

        planet myPlanet(newPlanet, radius);
        for(int j = 0; j < i; j++)
        {

            if(sol1.getPlanet(j).getName() == newPlanet)
            {
                cout << "Enter a new name" << endl;
                cin >> newPlanet;
                sol1(j) = newPlanet;
            }
        }
    }

    int i = 0;
    int num_of_planets = sol1.getNumPlanets();
    if (num_of_planets < 5)
    {
        cout<<"Your system has less than 5 planets!"<<endl;
    }

    while(i<num_of_planets) {
        cout << "This is planet " << i << " with name: " << newPlanet.getPlanet(i).getName() <<
        " and radius: " << newPlanet.getRadius() << endl;
        i++;
    }
*/


}

