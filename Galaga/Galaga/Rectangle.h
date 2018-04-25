/*
 * Author: Zhuoxin Sun
 * Assignment Title:  Galaga
 * Assignment Description: This program is a simple galaga
 * Due Date: 04/25/2018
 * Date Created: 03/24/2018
 * Date Last Modified: 04/24/2018
 */

#ifndef Rectangle_h
#define Rectangle_h

class Rectangle
{
public:
    int PosX;
    int PosY;
    
    int width;
    int height;
    
    /*
     * description: test if two rectangles collide(overlap)
     * return: bool
     * precondition: valid rectangle argument
     * postcondition: return true if two rectangles collides
     *                      otherwise return false
     */
    bool collision(Rectangle rect1);
};


#endif /* Rectangle_h */
