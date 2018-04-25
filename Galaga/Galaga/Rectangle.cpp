/*
 * Author: Zhuoxin Sun
 * Assignment Title:  Galaga
 * Assignment Description: This program is a simple galaga
 * Due Date: 04/25/2018
 * Date Created: 03/24/2018
 * Date Last Modified: 04/24/2018
 */

#include <stdio.h>
#include "Rectangle.h"

//Rectangle class implement
bool Rectangle::collision(Rectangle rect1)
{
    bool overlap = false;
    bool xOverlap = false;
    bool yOverlap = false;
    //check for x axis overlap
    if(PosX < rect1.PosX)
    {
        if ((PosX + width) >= rect1.PosX)
        { xOverlap = true;}
    }
    else if (PosX == rect1.PosX)
    { xOverlap = true; }
    else
    {
        if ((rect1.PosX + rect1.width) >= PosX)
        { xOverlap = true; }
    }
    
    //check for y axis overlap
    if(PosY < rect1.PosY)
    {
        if ((rect1.PosY - height) <= PosY)
        { yOverlap = true;}
    }
    else if (PosY == rect1.PosY)
    { yOverlap = true; }
    else
    {
        if ((PosY - height) <= rect1.PosY)
        { yOverlap = true; }
    }
    
    if(xOverlap && yOverlap)
        overlap = true;
    
    return overlap;
}
