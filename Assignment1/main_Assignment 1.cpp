 // Thomas Payne: CS1300 Fall 2017
// Recitation: 123 – Chelsea Chandler TA
//
// Assignment 2

#include <iostream>

using namespace std;

/**
 * Algorithm calculates the us population in one year (365) days
 * Outputs different integers based on the categories of
 * One birth every 8 seconds
 * One death every 12 seconds
 * One new immigrant ever 33 seconds
 * Returns the population in one year
 */

int howMany(int population) {
    int year = 31536000;
    int birth = year/8;
    int death = year/12;
    int immigrant = year/33;
    return population + birth - death + immigrant;

}

/**
 * Algorithm input is a number in seconds
 * Calculates the number of days and the remainder
 * Using the remainder, calculates the number of hours and the remainder
 * Using the remainder, calculates the number of minutes and the remainder
 * Using the remainder, calculates the final number of seconds
 * Output returns the time in days, hours, minutes, and seconds for a 24-hour clock
 */
void howLong(int seconds) {
    int days = 0;
    int hours = 0;
    int minutes = 0;

    if (seconds < 0){
        seconds = 0;
        cout << "Time is " << days << " days, " << hours << " hours, " << minutes << " minutes, " << "and " << seconds << " seconds."<< endl;
    }
    else
    {

    days = seconds/86400;
    seconds = seconds%86400;
    hours = seconds/3600;
    seconds = seconds%3600;
    minutes = seconds/60;
    seconds = seconds%60;

        cout << "Time is " << days << " days, " << hours << " hours, " << minutes << " minutes, " << "and " << seconds << " seconds."<< endl;
}}

/**
 * Algorithm will take an input in degrees Celsius
 * Make calculations ((input * 1.8)+32) to change input to Fahrenheit
 * Return the value as Fahrenheit
 */
int howHot(int temperature) {

    int F = temperature*(9.0/5.0) + 32;

    return F;
}


int main() {
    // Problem 1 test
    // Change value of 'pop' to change value you want to test
    int pop = 0;
    cout << "Given the initial population of " << pop;
    cin >> pop;
    cout << " your estimation finds a population of ";
    cout << howMany(pop) << endl << endl;


    // Problem 2 test
    // Change value 'sec' to change value you want to test
    int sec = 0;
    cout << "Given the seconds value of " << sec;
    cin >> sec;
    cout << " your output is: " << endl;
    howLong(sec);
    cout << endl;


    // Problem 3 test
    // Change value 'temp' to change value you want to test
    int temp = 0;
    cout << "Given temperature " << temp;
    cin >> temp;
    cout << " degrees Celsius you calculate ";
    cout << howHot(temp) << " degrees Fahrenheit" << endl;
    return 0;
}
