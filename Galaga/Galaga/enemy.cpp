/*
 * Author: Zhuoxin Sun
 * Assignment Title:  Galaga
 * Assignment Description: This program is a simple galaga
 * Due Date: 04/25/2018
 * Date Created: 03/24/2018
 * Date Last Modified: 04/24/2018
 */

#include <stdio.h>
#include "enemy.h"

//implement Enemy class 
Enemy::Enemy()
{
    //Initialize the offsets
    enemyRec.PosX = SCREEN_WIDTH / 4;
    enemyRec.PosY = SCREEN_HEIGHT / 4;
    
    //set its height and width as texture's
    enemyRec.width = gEnemyTexture.getWidth();
    enemyRec.height = gEnemyTexture.getHeight();
    
    //Initialize the velocity
    eVelX = 0;
    eVelY = 0;
}

Enemy::Enemy(double newX, double newY)
{
    //Initialize the offsets
    enemyRec.PosX = newX;
    enemyRec.PosY = newY;
    
    //set its height and width as texture's
    enemyRec.width = gEnemyTexture.getWidth();
    enemyRec.height = gEnemyTexture.getHeight();
    
    //Initialize the velocity
    eVelX = 0;
    eVelY = 0;
}

void Enemy::moveToLeft()
{
    //Move the right enemy to the left
    enemyRec.PosX -= ENEMY_VEL;
 
    //If the dot went too far to the left
    if( enemyRec.PosX  < 0)
    {
        //Move from the beginning
        enemyRec.PosX = SCREEN_WIDTH;
    }
}

void Enemy::moveToRight()
{
    //Move the right enemy to the left
    enemyRec.PosX += ENEMY_VEL;
    
    //If the dot went too far to the left
    if( enemyRec.PosX  > (SCREEN_WIDTH - enemyRec.width))
    {
        //Move from the beginning
        enemyRec.PosX = 0;
    }
}

void Enemy::render()
{
    if(enemyLife)
    {
        //Show the dot
        gEnemyTexture.render( enemyRec.PosX, enemyRec.PosY );
    }
    
}


