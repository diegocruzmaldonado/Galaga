//Part of the code is referred to
//Lazy Foo' Productions tutorial

/*Instructions:
 *press space key to fire the bullet
 *use arrow keys to move the player ship
 *the player only has one Health Point
*/

/*
 * Author: Zhuoxin Sun
 * Assignment Title:  Galaga
 * Assignment Description: This program is a simple galaga
 * Due Date: 04/25/2018
 * Date Created: 03/24/2018
 * Date Last Modified: 04/24/2018
 */

/*
 * Data Abstraction:
 *       No data input needed in the program
        This is a vedio game
 * Input:
 *      The program reads input from the users in the format
        of the key they pressed
 * Process:
 *      The inputs are read from the user and the corresponding
        movement is made
 * Output:
        The corresponding movement/destroyment with the input
 * Assumptions:
 *      It is assumed that, having been prompted to do so,
        the user will correctly pressed keys
 */

#include "bullet.h"
using namespace std;

//The window we'll be rendering to and its render
SDL_Window* gWindow = NULL;
SDL_Renderer* gRenderer = NULL;

//declare textures
LTexture gPlayerTexture;

LTexture gEnemyTexture;

LTexture gBulletTexture;

LTexture gEBulletTexture;

LTexture gBackground;

LTexture gMainMenu;

LTexture gEndsWin;

LTexture gEndsLose;

/*
 * description: Starts up SDL and creates window
 * return: bool
 * precondition: SDL has been set up
 * postcondition: SDL has been initialed and
                    window has been created
 */
bool init();


/*
 * description: Loads media
 * return: bool
 * precondition: SDL has been set up
 * postcondition: textures has been loaded
 */
bool loadMedia();


/*
 * description: Frees media and shuts down SDL
 * return: void
 * precondition: SDL has been set up
 * postcondition: textures has been freed
 */
void close();

//implement init()
bool init()
{
    
    //Initialization flag
    bool success = true;
    
    //Initialize SDL
    if( SDL_Init( SDL_INIT_VIDEO ) < 0 )
    {
        printf( "SDL could not initialize! SDL Error: %s\n", SDL_GetError() );
        success = false;
    }
    else
    {
        //Set texture filtering to linear
        if( !SDL_SetHint( SDL_HINT_RENDER_SCALE_QUALITY, "1" ) )
        {
            printf( "Warning: Linear texture filtering not enabled!" );
        }
        
        //Create window
        gWindow = SDL_CreateWindow( "Galaga", SDL_WINDOWPOS_UNDEFINED,
                                   SDL_WINDOWPOS_UNDEFINED, SCREEN_WIDTH,
                                   SCREEN_HEIGHT, SDL_WINDOW_SHOWN );
        if( gWindow == NULL )
        {
            printf( "Window could not be created! SDL Error: %s\n", SDL_GetError() );
            success = false;
        }
        else
        {
            //Create vsynced renderer for window
            gRenderer = SDL_CreateRenderer( gWindow, -1,
                                           SDL_RENDERER_ACCELERATED |
                                           SDL_RENDERER_PRESENTVSYNC );
            if( gRenderer == NULL )
            {
                printf( "Renderer could not be created! SDL Error: %s\n", SDL_GetError() );
                success = false;
            }
            else
            {
                //Initialize renderer color
                SDL_SetRenderDrawColor( gRenderer, 0xFF, 0xFF, 0xFF, 0xFF );
                
                //Initialize PNG loading
                int imgFlags = IMG_INIT_PNG;
                if( !( IMG_Init( imgFlags ) & imgFlags ) )
                {
                    printf( "SDL_image could not initialize! SDL_image Error: %s\n",
                           IMG_GetError() );
                    success = false;
                }
            }
        }
    }
    
    return success;
}

//implement loadMedia()
bool loadMedia()
{
    bool success = true;

    
    //load the backgroud and the main menu
    if(!gBackground.loadFromFile("background.bmp") ||
       !gMainMenu.loadFromFile("mainMenu.bmp"))
    {
        printf( "Failed to load dot texture!\n" );
        success = false;
    }
    
    //load textures
    if( !gPlayerTexture.loadFromFile("pShip.png") ||
       !gEnemyTexture.loadFromFile("eShip.png")
       || !gBulletTexture.loadFromFile("bulletNew.png") ||
       !gEBulletTexture.loadFromFile("bulletNew.png"))
    {
        printf( "Failed to load dot texture!\n" );
        success = false;
    }
    
    //load the endding image win and lose
    if(!gEndsWin.loadFromFile("win.bmp") ||
       !gEndsLose.loadFromFile("lose.bmp"))
    {
        printf( "Failed to load dot texture!\n" );
        success = false;
    }
    
    return success;
}

//implement close()
void close()
{
    //Free loaded images
    gPlayerTexture.free();
    gEnemyTexture.free();
    gBulletTexture.free();
    gEBulletTexture.free();
    gBackground.free();
    gMainMenu.free();
    gEndsWin.free();
    gEndsLose.free();
    
    //Destroy window
    SDL_DestroyRenderer( gRenderer );
    SDL_DestroyWindow( gWindow );
    gWindow = NULL;
    gRenderer = NULL;
    
    //Quit SDL subsystems
    IMG_Quit();
    SDL_Quit();
}


//main function
int main( int argc, char* args[] )
{
    //Start up SDL and create window
    if( !init() )
    {
        cout << "Failed to initialize!\n";
    }
    else
    {
        //Load media
        if( ! loadMedia() )
        {
            cout << "Failed to load player!\n" ;
        }
        else
        {
            //main loop flag
            bool quit = false;
            
            //event handler
            SDL_Event e;
            
            //declare a player
            Player player;
        
            //declare two groups of enemy
            int numOfEnemyEachSide = 7;
            //one start at the left
            Enemy enemyL[numOfEnemyEachSide];
            int incrementW = 10;
            int incrementH = 10;
            for (int i = 0; i < numOfEnemyEachSide; i++)
            {
                enemyL[i] = Enemy(50 + incrementW, incrementH);
                incrementW += 70;
                incrementH += 30;
            }
            //one start at the right
            Enemy enemyR[numOfEnemyEachSide];
            incrementW = 10;
            incrementH = 10;
            for (int i = 0; i < numOfEnemyEachSide; i++)
            {
                enemyR[i] = Enemy(450 - incrementW, incrementH);
                incrementW += 70;
                incrementH += 30;
            }
           
            //declare 10 enemy's bullet
            int numOfBullet = 10;
            BulletOfEnemy eBullet[numOfBullet];
            
            //declare 10 player's bullet
            Bullet bullet[numOfBullet];
            //keep track of playerBullet
            int nextPlayerBullet = 0;
            
            //keep track of frames
            int framesUntilEnemyFire = 1;
            int nextBulletFile = 0;
            
            //flag to show the main menu
            bool showMainmenu = true;
     
            //While application is running
            while( !quit )
            {
                //Handle events on queue
                while( SDL_PollEvent( &e ) != 0 )
                {
                    //User requests quit
                    if( e.type == SDL_QUIT )
                    {
                        quit = true;
                    }
                    
                    if (!showMainmenu)
                    {
                        //Handle input for the dot
                        player.handleEvent( e );
                        
                        //Handle input for the bullet
                        bullet[nextPlayerBullet].handleEvent( e, player);
                    }
                    
                    //enter space key to play the game
                    if( e.type == SDL_KEYDOWN && e.key.repeat == 0 )
                       {
                           //play the game
                           switch( e.key.keysym.sym )
                           {
                               case SDLK_SPACE: showMainmenu = false;
                           }
                       }
                }
                if(!showMainmenu)
                {
                    //Move the dot
                    player.move();
                    
                    //Move the player's bullets
                    for (int i = 0; i < numOfBullet; i++)
                    {
                        bullet[i].move();
                    }
                    
                    //check if the player's bullets collide 2 groups of enemy
                    for (int i = 0; i < numOfBullet; i++)
                    {
                        for (int j = 0; j < numOfEnemyEachSide; j++)
                        {
                            bullet[i].collideWithEnemy(enemyR[j]);
                            bullet[i].collideWithEnemy(enemyL[j]);
                        }
                    }
                    
                    //update the playerBullet
                    nextPlayerBullet++;
                    //recycle the 10 bullets of the enemy
                    if (nextPlayerBullet == numOfBullet)
                    { nextPlayerBullet = 0; }
                    
                    //move the enemy
                    for (int i = 0; i < numOfEnemyEachSide; i++)
                    {
                        enemyL[i].moveToRight();
                        enemyR[i].moveToLeft();
                    }
                    
                    //enemy fires its first bullet,
                    //then wait for 50 frames to fire the next bullet
                    framesUntilEnemyFire--;
                    if(framesUntilEnemyFire == 0)
                    {
                        //enemy fire the bullet only when they are alive
                        for (int i = 0; i < numOfEnemyEachSide; i++)
                        {
                            if(enemyL[i].enemyLife == true)
                            {
                                eBullet[nextBulletFile].fire(enemyL[i]);
                            }
                        }
                        
                        for (int i = 0; i < numOfEnemyEachSide; i++)
                        {
                            if(enemyR[i].enemyLife == true)
                            {
                                eBullet[nextBulletFile + 1].fire(enemyR[i]);
                            }
                        }
                        
                        //update the bullet
                        nextBulletFile += 2;
                        
                        //waite 20 frams to fire another bullet from enemy
                        framesUntilEnemyFire = 50;
                    }
                    
                    //recycle the 10 bullets of the enemy
                    if (nextBulletFile == numOfBullet)
                    { nextBulletFile = 0; }
                    
                    //move the current bullet
                    for (int i = 0; i < numOfBullet; i++)
                    { eBullet[i].move(player); }
                    
                    //Clear screen
                    SDL_SetRenderDrawColor( gRenderer, 0xFF, 0xFF, 0xFF, 0xFF );
                    SDL_RenderClear( gRenderer );
                    
                    //draw background first
                    gBackground.render(0, 0);
                    
                    //Render objects
                    player.render();
                    
                    //Render bullets
                    for (int i = 0; i < numOfBullet; i++)
                    {
                        bullet[i].render();
                        bullet[i].render();
                    }
                    
                    //render the current bullet
                    for (int i = 0; i < numOfBullet; i++)
                    { eBullet[i].render(); }
                    
                    
                    //Render enemy
                    for (int i = 0; i < numOfEnemyEachSide; i++)
                    {
                        enemyL[i].render();
                        enemyR[i].render();
                    }
                    
                    //flag if win the game
                    bool won = true;
                    //render winEnds if win
                    for (int i = 0; i < numOfEnemyEachSide; i++)
                    {
                        if(enemyR[i].enemyLife == true ||
                           enemyL[i].enemyLife == true)
                        {
                            won = false;
                        }
                    }
                    
                    if (won)
                    {
                        //render winEnds if lose
                        gEndsWin.render(0, 0);
                    }
                    else if (player.playerLife == false)
                    {
                        //render loseEnds if lose
                        gEndsLose.render(0, 0);
                    }
                }
                
                if(showMainmenu == true)
                {
                    //show the main menu for 15s
                    gMainMenu.render(0, 0);
                }

                //Update screen
                SDL_RenderPresent( gRenderer );
            }
        }
    }
    
    //Free resources and close SDL
    close();
    
    return 0;
}

