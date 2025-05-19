// The specification file
#ifndef Food_H
#define Food_H
#include <graphics.h>
#include "Boy.hpp"
#include "ellipsee.hpp"
#include "score.hpp"

class Food
{
protected:
    int score = 1;
    Ellipsee ellipse;
    int color;
    void _draw(int c) const;
    void _move(int _dy);

public:
Food();
Food(int _x, int _y, int _rx, int _ry, int _color = WHITE);
    virtual void draw() ;
    virtual void undraw();
    void move(int _dy); // use parameters for movement. To be used by the player object
    virtual void handleFood(Boy* boi, Score* score, int fruitSpeed);
    bool inBasket(Boy* boi);

    Ellipsee getEllipse();
~Food(); // destructor method

};

// 
#endif
