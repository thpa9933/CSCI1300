#include <iostream>
using namespace std;
#include "GameBoard.h"
#include "Invader.h"

Invader::Invader()
{
    countFire = 0;
}

Invader::~Invader()
{
    //dest
}

bool Invader::Fire(char x)              //Countfire counts the turns
{                                       //Countfire is used to increase the amount of invaders with each turn
    if(x == 'y')
    {
        countFire++;
        //cout << "Fire yes" << endl;
        return true;
    }
    else
        //cout << "Fire no" << endl;
        return false;
}

int Invader::GetCountFire()
{
    return countFire;
}
