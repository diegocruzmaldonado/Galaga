/*
 * Author: Zhuoxin Sun
 * Assignment Title:  Galaga
 * Assignment Description: This program is a simple galaga
 * Due Date: 04/25/2018
 * Date Created: 03/24/2018
 * Date Last Modified: 04/24/2018
 */

#include <stdio.h>
#include "bullet.h"

//implement of Bullet class
Bullet::Bullet()
{
    //bullet died before working
    playerBulletLife = false;
    
    //set height and width as the corresponding texture's
    bullet.width = gBulletTexture.getWidth();
    bullet.height = gBulletTexture.getHeight();
    
    //Initialize the velocity
    bVelX = 0;
    bVelY = 0;
}

void Bullet::handleEvent( SDL_Event& e, Player dot)
{
    
    //If a key was pressed
    if( e.type == SDL_KEYDOWN && e.key.repeat == 0 )
    {
        //Adjust the velocity
        switch( e.key.keysym.sym )
        {
            case SDLK_SPACE: bVelY = BULLET_VEL;
                //player fires the bullet only when it's alive
                if (dot.playerLife == true)
                {
                    playerBulletLife = true;
                    bullet.PosX = dot.playerRect.PosX + (dot.playerRect.width / 2.5);
                    bullet.PosY = dot.playerRect.PosY + (dot.playerRect.height / 2);
                }
                break;
        }
    }
}

void Bullet::move()
{
    //Move the bullet up
    bullet.PosY -= bVelY;
    
}

void Bullet::collideWithEnemy(Enemy &enemy)
{
    //check each time for each enemy
    if(bullet.collision(enemy.enemyRec))
    {
        //playerBullet/enemy/enemyBullet die
        playerBulletLife = false;
        enemy.enemyLife = false;
    }
}

void Bullet::render()
{
    if(playerBulletLife)
    {
        //Show the dot
        gBulletTexture.render( bullet.PosX, bullet.PosY );
    }
    
}

//implement of BulletOfEnemy class
BulletOfEnemy::BulletOfEnemy()
{
    //set height and width as the corresponding texture's
    eBullet.width = gBulletTexture.getWidth();
    eBullet.height = gBulletTexture.getHeight();
    
    //Initialize the velocity
    eBVelX = 0;
    eBVelY = 0;
}

void BulletOfEnemy::fire(Enemy enemy)
{
    //set the bullet as alive
    enemyBulletLife = true;
    
    //start where the enemy is
    eBullet.PosX = enemy.enemyRec.PosX + (enemy.enemyRec.width / 3);
    eBullet.PosY = enemy.enemyRec.PosY + (enemy.enemyRec.height / 2);
}

void BulletOfEnemy::move(Player &player)
{
    //Move the bullet down
    eBullet.PosY += EBULLET_VEL;
    
    //deal with collision
    if(eBullet.collision(player.playerRect))
    {
        //enemyBullet dies
        enemyBulletLife = false;
        player.playerLife = false;
        //playerBullet dies
    }
}

void BulletOfEnemy::render()
{
    if(enemyBulletLife)
    {
        //Show the dot
        gEBulletTexture.render( eBullet.PosX, eBullet.PosY );
    }
}
