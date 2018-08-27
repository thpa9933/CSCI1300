#include <iostream>
#include <math.h>
using namespace std;

// Author: <Thomas Payne>
// Recitation: <#102 Chelsea Chandler>
//
// Assignment 3
// Problem <2>





/*
This function receives two inputs from main.
It then calculates the wind chill (long calculation) using pow() functions defined in the <math.h> library.
Function returns the the result into the cout of the main function.
*/

//Part a

float windChillCalculator(float Temp, float Wspeed)
{
    float wind_chill = 35.74 + (0.6215 * Temp) - (35.75 * (pow(Wspeed,0.16))) + ((0.4275 * Temp) * (pow(Wspeed,0.16)));
    return wind_chill;
}


//Part b
/*
The while loop receives the inputs, then determines if the low wind speed is less than the high. If it is, the loop runs.
The loop then outputs a print statement, in which it calls the windChillCalculator, to determine the new value for wind chill given the new parameters.
the low wind speed is assigned the new, updated value, and the loop restarts again.
*/

void printWindChill(float T, float low_wind_speed, float high_wind_speed, float wind_speed_step)
{

    while ( low_wind_speed <= high_wind_speed)
    {
        cout << "The wind chill is " << windChillCalculator(T, low_wind_speed) << " degrees F for an airtemperature of " << T << " degrees F" << " and a wind speed of " << low_wind_speed << " mph." << endl;
        low_wind_speed = low_wind_speed + wind_speed_step;
    }
}



/*
Main calls on four variables
User inputs four variables.
The printWindChill function is called receiving the four user input variables.
*/
int main()
{
    float x;
    float y;
    float z;
    float a;

    cout << "Enter Temperature: ";
    cin >> x;
    cout << endl;

    cout << "Enter Low wind speed: ";
    cin >> y;
    cout << endl;

    cout << "Enter high wind speed: ";
    cin >> z;
    cout << endl;

    cout << "Enter wind speed step: ";
    cin >> a;

    printWindChill(x,y,z,a);
}



















