/*
 * Author: Zhuoxin Sun
 * Assignment Title:  Galaga
 * Assignment Description: This program is a simple galaga
 * Due Date: 04/25/2018
 * Date Created: 03/24/2018
 * Date Last Modified: 04/24/2018
 */

#include "player.h"

//implement Player class
Player::Player()
{
    //Initialize the offsets(use the rectangle)
    playerRect.PosX = SCREEN_WIDTH / 2;
    playerRect.PosY = SCREEN_HEIGHT / 5 * 4;
    
    //set the height and width with the texture's
    playerRect.width = gPlayerTexture.getWidth();
    playerRect.height = gPlayerTexture.getHeight();
    
    //Initialize the velocity
    pVelX = 0;
    pVelY = 0;
}

void Player::handleEvent( SDL_Event& e )
{
    //If a key was pressed
    if( e.type == SDL_KEYDOWN && e.key.repeat == 0 )
    {
        //Adjust the velocity
        switch( e.key.keysym.sym )
        {
            case SDLK_UP: pVelY -= PLAYER_VEL; break;
            case SDLK_DOWN: pVelY += PLAYER_VEL; break;
            case SDLK_LEFT: pVelX -= PLAYER_VEL; break;
            case SDLK_RIGHT: pVelX += PLAYER_VEL; break;
        }
    }
    //If a key was released
    else if( e.type == SDL_KEYUP && e.key.repeat == 0 )
    {
        //Adjust the velocity
        switch( e.key.keysym.sym )
        {
            case SDLK_UP: pVelY += PLAYER_VEL; break;
            case SDLK_DOWN: pVelY -= PLAYER_VEL; break;
            case SDLK_LEFT: pVelX += PLAYER_VEL; break;
            case SDLK_RIGHT: pVelX -= PLAYER_VEL; break;
        }
    }
}

void Player::move()
{
    //Move the dot left or right
    playerRect.PosX += pVelX;
    
    //If the dot went too far to the left or right
    if( ( playerRect.PosX  < 0 ) || ( playerRect.PosX + PLAYER_WIDTH > SCREEN_WIDTH ) )
    {
        //Move back
        playerRect.PosX  -= pVelX;
    }
    
    //Move the dot up or down
    playerRect.PosY  += pVelY;
    
    //If the dot went too far up or down
    if( ( playerRect.PosY < 0 ) || ( playerRect.PosY + PLAYER_HEIGHT > SCREEN_HEIGHT ) )
    {
        //Move back
        playerRect.PosY -= pVelY;
    }
}

void Player::render()
{
    //if the player still alive, render it
    if(playerLife)
    gPlayerTexture.render( playerRect.PosX, playerRect.PosY );
}

