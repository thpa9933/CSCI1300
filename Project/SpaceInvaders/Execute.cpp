#include <iostream>
#include <fstream>
#include <vector>
#include "GameBoard.h"
#include "Destroyer.h"
#include "Invader.h"
#include "Execute.h"
using namespace std;

GameBoard SpaceInvaders;
Destroyer object;

Execute::Execute()
{
    MaxHighScore = 0;
}
Execute::~Execute()
{
    //blah
}

//Is the basis of the game, used to check inputs, in run other functions
void Execute::executeThis()
{

    cout << "Welcome! Who is playing today?" << endl;
    cin >> input4;
    cout << "Hello " << input4 << "!" << endl;

    SpaceInvaders.Instructions("INSTRUCTIONS.txt");
    for(int i = 0; i < 5; i++)
    {
        cout << SpaceInvaders.printInstructions[i] << endl;
    }

    while(SpaceInvaders.gameStatus == false)                        //While the game has not ended yet
    {
        cout << "Please enter left (l) or right (r)" << endl;
        cin >> input1;

        while(input1 != 'l' && input1 != 'r')                       //Denys invalid inputs
        {
            cout << "Please enter a valid input, (l) to move left, or (r) to more right!" << endl;
            cin >> input1;
        }

        cout << "How many space would you like to move?" << endl;
        cin >> input2;
        while(!(input2 <= '0') && !(input2 >= '39'))                //Denys invalid inputs
        {
            cout << "Please enter a valid input!" << endl;
            cout << "How many space would you like to move?" << endl;
            cin >> input2;
        }

        cout << "Would you like to fire? (y) for yes or (n) for no" << endl;
        cin >> input3;

        while(input3 != 'y' && input3 != 'n')
        {
            cout << "Please enter a valid input!" << endl;
            cout << "Would you like to fire? (y) for yes or (n) for no" << endl;
            cin >> input3;
        }
        cout << "SCORE: " << SpaceInvaders.score << endl;            //Prints score on screen
        SpaceInvaders.runGame(input1, input2, input3);               //Runs the game using the validated inputs

        if(SpaceInvaders.gameStatus == true)
        {
            cout << "Good game " << input4 << "! Your score is: " << SpaceInvaders.score << endl;
            writeHighScore("HIGHSCORE.txt");
            cout << "The HighScore is: " << MaxHighScore << endl;
        }
    }
}

int Execute::writeHighScore(string filename)       //WRITE HIGH SCORE
{
    if(SpaceInvaders.gameStatus == true)
    {
        ofstream outFile;
        outFile.open(filename,fstream::app);       //extends the string but adding characters to current value
        if(outFile.fail())
            return 0;
        else
            outFile << SpaceInvaders.score << endl; //writes score to outfile
        outFile.close();

        ifstream inFile;
        inFile.open("HIGHSCORE.txt");
        if(inFile.fail())
            return 0;
        string line;
        int count = 0;
        while(getline(inFile, line))
        {
            for(int i = 0; i < count; i++)
            {
                Scores[count] = stoi(line);        //stores line of score into array
            }
        count++;
        }

        for(int j = 0; j < count; j++)
        {
            if(MaxHighScore < Scores[j])
                MaxHighScore = Scores[j];          //searches through array and returns the largest score
        }
    }
    return MaxHighScore;
}
