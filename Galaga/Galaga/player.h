/*
 * Author: Zhuoxin Sun
 * Assignment Title:  Galaga
 * Assignment Description: This program is a simple galaga
 * Due Date: 04/25/2018
 * Date Created: 03/24/2018
 * Date Last Modified: 04/24/2018
 */

#ifndef player_h
#define player_h
#include <stdio.h>
#include "Rectangle.h"
#include "display.h"

//player textures
extern LTexture gPlayerTexture;

//Player class
class Player
{
public:
    //The dimensions of the player
    static const int PLAYER_WIDTH = 20;
    static const int PLAYER_HEIGHT = 20;   
    
    //Maximum axis velocity of the player
    static const int PLAYER_VEL = 10;
    
    /*
     * description: Initializes player's position/size/velocity
     * return: no return
     * precondition: attributes are valid
     * postcondition: attributes has been set
     */
    Player();
    
    /*
     * description: Takes key presses and adjusts the
     *               player's velocity
     * return: void
     * precondition: valid SDL_Event
     * postcondition: change player's velocity with
     *               the corresponding key pressed
     */
    void handleEvent( SDL_Event& e );
    
    /*
     * description: Moves the player
     * return: void
     * precondition: player's position and velocity are valid
     * postcondition: change player's position
     */
    void move();
    
    //keep track of the playerBullet's life
    bool playerLife = true;
    
    /*
     * description: Shows the player on the screen
     * return: void
     * precondition: valid player texture
     * postcondition: player is rendered on the screen
     */
    void render();
    
    //use Rectangle calss to store player's position/size
    Rectangle playerRect;
    
private:
    //The velocity of the player
    int pVelX, pVelY;
};

#endif /* player_h */
