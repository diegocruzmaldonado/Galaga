/*
 * Author: Zhuoxin Sun
 * Assignment Title:  Galaga
 * Assignment Description: This program is a simple galaga
 * Due Date: 04/25/2018
 * Date Created: 03/24/2018
 * Date Last Modified: 04/24/2018
 */

#ifndef display_h
#define display_h

#include <stdio.h>
#include <SDL2/SDL.h>
#include <SDL2_image/SDL_image.h>
#include <iostream>

//Screen dimension
const int SCREEN_WIDTH = 700;
const int SCREEN_HEIGHT = 500;

//The window renderer
extern SDL_Renderer* gRenderer;

//Texture wrapper class
class LTexture
{
public:
    /*
     * description: Initializes variables
     * return: no return
     * precondition: attributes are valid
     * postcondition: attributes has been set
     */
    LTexture();
    
    /*
     * description: Deallocates memory
     * return: no return
     * precondition: attributes are there
     * postcondition: attributes has been deallocated
     */
    ~LTexture();
    
    /*
     * description: Loads image at specified path
     * return: bool
     * precondition: the path is valid
     * postcondition: image has been loaded
     */
    bool loadFromFile( std::string path );
    
    /*
     * description: Deallocates texture
     * return: void
     * precondition: texture is existed
     * postcondition: textur has been deallocated
     */
    void free();
    
    /*
     * description: Renders texture at given point
     * return: void
     * precondition: valid arguments
     * postcondition: textur is rendered at the given point
     */
    void render( int x, int y, SDL_Rect* clip = NULL, double angle = 0.0, SDL_Point* center = NULL, SDL_RendererFlip flip = SDL_FLIP_NONE );
    
    /*
     * description: Gets image width
     * return: int
     * precondition: the width is valid
     * postcondition: return image's width
     */
    int getWidth();
    
    /*
     * description: Gets image height
     * return: int
     * precondition: the height is valid
     * postcondition: return image's height
     */
    int getHeight();
    
private:
    //The actual hardware texture
    SDL_Texture* mTexture;
    
    //Image dimensions
    int mWidth;
    int mHeight;
};


#endif /* display_h */
