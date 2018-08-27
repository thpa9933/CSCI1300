#include <iostream>
#include <cstdlib>
#include <fstream>
using namespace std;

#include "Destroyer.h"
#include "GameBoard.h"

GameBoard::GameBoard()                      //default constructor, constructs basic game bored when instance is called
{
    gameStatus = false;
    score = 0;

    for(int i = 0; i < 15; i++)             //DRAWS BOARDER
    {
        Grid[1][rand()%1 + 19] = '@';
        for(int j = 0; j < 40; j++)
        {
            if(j == 0 || j == 39)
                Grid[i][j] = '|';
            else if(i == 0 || i == 14)
                Grid[i][j] = '|';
            else if(i == 12)
                Grid[i][j] = '=';
            else if(i == 13 && j == 20)
                Grid[i][j] = 'X';
            else
                Grid[i][j] = ' ';
        }
    }
    for(int i = 0; i < 15; i++)
    {
        for(int j = 0; j < 40; j++)
        {
            cout << "\x1B[32m" << Grid[i][j] << "\x1B[0m";
        }
        cout << endl;
    }
}

GameBoard::~GameBoard()
{

}

//Checks the inputs
//determines what move function needs to be called
//checks to see if the player fired, if so, call the update board function
void GameBoard::runGame(char input1, int input2, char input3)
{
    if(input1 == 'l')
    {
        destroyer.setMoveLeft(input2);
    }
    if(input1 == 'r')
    {
        destroyer.setMoveRight(input2);
    }

    bool check = invader.Fire(input3);
    if(check == true)
        UpdateBoard();
    Draw();

}

//Draws basic game board
//includes the user movement input
//this function is for if the user wants to move, but not fire
void GameBoard::Draw()
{

    for(int i = 0; i < 15; i++)
        {
            for(int j = 0; j < 40; j++)
            {
                    if(j == 0 || j == 39)
                        Grid[i][j] = '|';
                    else if(i == 0 || i == 14)
                        Grid[i][j] = '|';
                    else if(i == 12)
                        Grid[i][j] = '=';
                    else if(i == 13 && j == destroyer.MOVE)
                        Grid[i][j] = 'X';
                    else if(Grid[i][j] == '@')
                    {
                        //nothing
                    }
                    else
                        Grid[i][j] = ' ';
            }
        }

        for(int i = 0; i < 15; i++)
        {
            for(int j = 0; j < 40; j++)
            {
                cout << "\x1B[32m" << Grid[i][j] << "\x1B[0m";
            }
            cout << endl;
        }
}

//This function is for when the player moves and fires
//Draws the board with after the variables have been considered
//Overwrites the OG board
//Checks the game status to see if the game needs to be ended or not
void GameBoard::UpdateBoard()
{
    int col = destroyer.MOVE;
    for(int i = 0; i < 15; i++)
    {
        if(Grid[i][col] == '@')         //CLEARS COLUMN
        {                               //COUNTS HOW MANY INVADERS WERE HIT
            Grid[i][col] = ' ';
            score++;
        }
    }

    for(int i = 14; i >= 0; i--)
    {
        for(int j = 0; j < 40; j++)
        {

            if(Grid[i][j] == '@')       //BUMPS INVADERS DOWN
            {
                Grid[i+1][j] = '@';
                Grid[i][j] = ' ';
            }

        }
    }

    for(int i = 0; i < 15; i++)         //GENERATES NEW ROW/ MORE INVADERS WITH EVERY FIRE
    {
        int numInvaders = invader.GetCountFire(); //Increases the amount of invaders with each turn
        Grid[1][rand()% numInvaders + 10] = '@';
    }

    for(int k = 0; k < 40; k++)         //ENDS GAME
    {
        if(Grid[11][k] == '@')          //if invaders reach the last valid row, call the end game function
            gameOver();
    }
}

//Determines if the game is over based on Update board
//Only gets called when the game is over
void GameBoard::gameOver()
{
    gameStatus = true;
}

//Read in the instructions from a file
//Store lines into an array
//Print array in my execute function
void GameBoard::Instructions(string filename)
{
    for(int i = 0; i < 5; i++)
    {
        printInstructions[i] = "";      //EMPTIES ARRAY
    }

    ifstream dataFile1;
    dataFile1.open(filename);
    if(dataFile1.is_open())
    {
        int count = 0;
        string str;
        while(getline(dataFile1, str))
        {
            printInstructions[count] = str;
            count++;
        }
    dataFile1.close();
    }
}

