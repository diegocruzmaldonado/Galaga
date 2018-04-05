#ifndef PLAYERSHIP_H_INCLUDED
#define PLAYERSHIP_H_INCLUDED

class PlayerShip
{
private:
    double x, y;
    
public:
    PlayerShip();
    PlayerShip(int startX, int startY);
    
    
    void setXPos(double newX);
    double getXPos();
    void setYPos(double newY) {y = newY;}
    double getYPos() {return y;}
    
    void moveShip(int direction);
    void moveShip(int dir1, int dir2);
};


#endif // PLAYERSHIP_H_INCLUDED

