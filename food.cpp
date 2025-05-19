// The implementation file

#include <iostream>
#include <graphics.h>
#include "food.hpp"
#include "Boy.hpp"
#include "score.hpp"
// (Defining a Member Function) using class name and scope resolution operator (::)
    Food::Food(){}

   Food::Food(int _x, int _y, int _rx, int _ry, int _color) {
        ellipse.setX(_x);
        ellipse.setY(_y);
        ellipse.setRX(_rx);
        ellipse.setRY(_ry);
        color = _color;
     };
    void Food::_draw(int c) const
    {
        setcolor(c);
        setfillstyle(SOLID_FILL, c);
        fillellipse(ellipse.getX(), ellipse.getY(), ellipse.getRX(), ellipse.getRY());
    }

    void Food::_move(int _dy)
    {
        undraw();
        ellipse.y += _dy;
        draw();
    }

    void Food::draw()  { _draw(color); }
    void Food::undraw() { _draw(WHITE); }
    void Food:: move(int _dy) { _move(_dy); }
    void Food:: handleFood(Boy* boi, Score* _score, int fruitSpeed)
    {

    }
    bool Food:: inBasket(Boy* boi){
        return ellipse.ellipseCollision(ellipse, boi->getEllipse());
    }

    Ellipsee Food::getEllipse() { return ellipse;}

 Food::~Food(){
    undraw();
 }

