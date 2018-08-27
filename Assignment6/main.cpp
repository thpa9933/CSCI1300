//Thomas Payne
//Chelsea Chandler
//Assignment 6

#include <iostream>
#include <fstream>
#include <string>
#include <cstdlib>
#include <sstream>
#include "Assignment6.cpp"
using namespace std;

int main()
{
/*
//Part 1
    cout << avgCharsPerLine("part1.txt") << endl;
*/

//Part 2
    float array1[3][5];
    fillArray("part2.txt", array1);
    for(int i = 0; i < 3; i++)
    {
        for(int j = 0; j < 5; j++)
        {
        cout<<array1[i][j]<<" ";
        }
        cout<<endl;
    }

/*
//Part 3
    float numbers[5][5];
    cout << arrayStats("part3.txt", numbers) <<endl;

*/
//Part 4
/*
    string users[100];
    int ratings[50][50];
    addBookRatings("part4.txt", users, ratings);

    for(int i = 0; i < 50; i++)
    {
        for( int j = 0 ; j < 50; j++)
        {
            cout << ratings[i][j] << " ";
        }
        cout << endl;
    }
*/
}
