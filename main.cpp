//
//  main.cpp
//  move enemy
//
//  Created by wang ting Chen on 2018/4/24.
//  Copyright © 2018年 program. All rights reserved.
//

#include <iostream>

int main(int argc, const char * argv[]) {
   
    void Enemy::render()
    {
        
        //Show the dot
        for(int i=0;i<2;i++)
        {
            bool change=false;
            
            gEnemyTexture.render( enemy.PosX, enemy.PosY );
            
            if(!change)
            {
                enemy.PosX+=eVelX;
                if( ( enemy.PosX + enemy.width == SCREEN_WIDTH ) )
                {eVelX=-2;
                    if(enemy.PosX==0)
                    {
                        enemy.PosX=0;
                    }
                    
                }
                change=true;
            }
            
        }
        
        
        
        
        
        
    }
    return 0;
}
