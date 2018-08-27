#ifndef GAMEBOARD_H
#define GAMEBOARD_H
#include <iostream>
using namespace std;

#include "Destroyer.h"
#include "Invader.h"

class GameBoard{
public:
    GameBoard();
    ~GameBoard();

    void Draw(); //Draws my board
    void runGame(char, int, char); //takes in all my input/ moves invaders down a space
    void gameOver();
    void Instructions(string);
    Invader invader;
    void UpdateBoard();
    bool gameStatus;
    string printInstructions[5];
    int score;
    Destroyer destroyer;

private:
    char Grid[15][40];
    char input1; //sets left or right
    int input2; // how far left or right
    char input3; //fires shot


};
#endif
