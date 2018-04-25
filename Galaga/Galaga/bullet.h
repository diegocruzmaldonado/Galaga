/*
 * Author: Zhuoxin Sun
 * Assignment Title:  Galaga
 * Assignment Description: This program is a simple galaga
 * Due Date: 04/25/2018
 * Date Created: 03/24/2018
 * Date Last Modified: 04/24/2018
 */

#ifndef bullet_h
#define bullet_h

#include "player.h"
#include "enemy.h"
#include "Rectangle.h"

//player's bullet texture
extern LTexture gBulletTexture;

//enemy's bullet texture
extern LTexture gEBulletTexture;

//player's bullet class

//BulletOfEnemy class
class BulletOfEnemy
{
public:
    //The dimensions of the dot
    static const int EBULLET_WIDTH = 20;
    static const int EBULLET_HEIGHT = 20;
    
    //Maximum axis velocity of the enemyBullet
    static const int EBULLET_VEL = 10;
    
    /*
     * description: default constructor
     * return: no return
     * precondition: attributes are valid
     * postcondition: attributes has been set
     */
    BulletOfEnemy();
    
    /*
     * description: fire the bullet from the enemy
     * return: void
     * precondition: the enemy is valid
     * postcondition: bullet move from the place
     *               where enemy is
     */
    void fire(Enemy enemy);
    
    //flag keeping track if the enemyBullet live
    bool enemyBulletLife = false;
    
    /*
     * description: Moves the enemyBullet
     * return: void
     * precondition: the player is valid
     * postcondition: move bullet's position and
     *            check if it overlaps with the player
     */
    void move(Player &player);
    
    /*
     * description: Shows the enemyBullet on the screen
     * return: void
     * precondition: enemy's bullet texture is valid
     * postcondition:render the enemyBullet on the screen
     */
    void render();
    
    //store enemyBullet's position and size
    Rectangle eBullet;
    
    //The velocity of the enemyBullet
    int eBVelX, eBVelY;
    
};

//Bullet class
class Bullet
{
public:
    //The dimensions of the dot
    static const int BULLET_WIDTH = 20;
    static const int BULLET_HEIGHT = 20;
    
    //Maximum axis velocity of the bullet
    static const int BULLET_VEL = 10;
    
    /*
     * description: Initializes playerBullet's size/velocity
     * return: no return
     * precondition: attributes are valid
     * postcondition: attributes has been set
     */
    Bullet();
    
    /*
     * description: Takes key presses and adjusts
     *               the bullet's velocity/position
     * return: void
     * precondition: valid SDL_Event and player
     * postcondition: change playerBullet's starting point
     */
    void handleEvent( SDL_Event& e, Player dot);
    
    //flag checking if playerBullet alive
    bool playerBulletLife = true;
    
    /*
     * description: Moves the playerBullet
     * return: void
     * precondition: valid playeBullet's position and velocity
     * postcondition: change playerBullet's position
     */
    void move();
    
    /*
     * description: check if playerBullet collides with the enemy
     * return: void
     * precondition: valid enemy
     * postcondition: adjust playerBullet's and enemy's lifes
     *          based on the collision condition
     */
    void collideWithEnemy(Enemy &enemy);
    
    /*
     * description: Shows the playerBullet on the screen
     * return: void
     * precondition: valid playerBullet's texture
     * postcondition: render the playerBullet on the screen
     */
    void render();
    
    //Store playerBullet's position/size
    Rectangle bullet;
    
    //The velocity of the playerBullet
    int bVelX, bVelY;
    
};


#endif /* bullet_h */
