#include "PlayerShip.h"
#include <iostream>
using namespace std;

const int START_X = 10;
const int START_Y = 10;



PlayerShip::PlayerShip()
{
    x = START_X;
    y = START_Y;
}

PlayerShip::PlayerShip(int startX, int startY)
{
    x = startX;
    y = startY;
}



void PlayerShip::setXPos(double newX)
{
    x = newX;
}

double PlayerShip::getXPos()
{
    return x;
}


void PlayerShip::moveShip(int direction)
{
    switch (direction)
    {
        case 80:
            y--;
            break;
        case 72:
            y++;
            break;
        case 75:
            x--;
            break;
        case 77:
            x++;
            break;
    }
}

void PlayerShip::moveShip(int dir1, int dir2)
{
    // Moves ship either up or down
    if (dir1 == 80)
    {
        moveShip(80);
    }
    else if (dir1 ==72)
    {
        moveShip(72);
    }
    
    // Moves ship left or right
    if (dir2 == 75)
    {
        moveShip(75);
    }
    else if (dir2 == 77)
    {
        moveShip(77);
    }
}
