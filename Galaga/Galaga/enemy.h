/*
 * Author: Zhuoxin Sun
 * Assignment Title:  Galaga
 * Assignment Description: This program is a simple galaga
 * Due Date: 04/25/2018
 * Date Created: 03/24/2018
 * Date Last Modified: 04/24/2018
 */

#ifndef enemy_h
#define enemy_h
#include "display.h"
#include "Rectangle.h"

//enemy texture
extern LTexture gEnemyTexture;

//Enemy class
class Enemy
{
public:
    //The dimensions of the enemy
    static const int ENEMY_WIDTH = 20;
    static const int ENEMY_HEIGHT = 20;
    
    //Maximum axis velocity of the enemy
    static const int ENEMY_VEL = 1;
    
    /*
     * description: Initializes enemy's position/size/velocity
     * return: no return
     * precondition: attributes are valid
     * postcondition: attributes has been set
     */
    Enemy();
    
    /*
     * description: Initializes enemy's position/size/velocity
     * return: no return
     * precondition: attributes are valid
     * postcondition: attributes has been set
     */
    Enemy(double newX, double newY);
    
    //falg keeping track of enemy's life
    bool enemyLife = true;
    
    /*
     * description: Moves the enemy to the left
     * return: void
     * precondition: enemy's velocity is valid
     * postcondition: move the enemy to the left
     */
    void moveToLeft();
    
    /*
     * description: Moves the enemy to the right
     * return: void
     * precondition: enemy's velocity is valid
     * postcondition: move the enemy to the right
     */
    void moveToRight();
    
    /*
     * description: Shows the enemy on the screen
     * return: void
     * precondition: enemy texture is valid
     * postcondition: render the enemy if it's alive
     */
    void render();
    
    //use Renctangle class to store enemy's position/size
    Rectangle enemyRec;
    
private:
    //The velocity of the enemy
    int eVelX, eVelY;
    
};

#endif /* enemy_h */
