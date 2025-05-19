//
#include <iostream>
#include <graphics.h>
#include "food.hpp"
#include "Boy.hpp"
#include "score.hpp"
#include "fruit.hpp"

Fruit::Fruit() : Food(){};
Fruit::Fruit(int _x, int _y, int _rx, int _ry, int _color, int _score) : Food(_x, _y, _rx, _ry, _color)
{
    score = _score;

    string fruitPaths[4] = {applePath, bananasPath, dorianPath, orangePath};
    fruitPath = fruitPaths[rand() % 4];

    size = imagesize(0, 0, imageWidth, imageHeight); // memory size in bytes
    image = new char[size];

    // read image from the external file and put it anywhere on the screen
    //   to prepare for the getimage(), as getimage() must get image from the screen

    readimagefile(fruitPath.c_str(), 0, 0, imageWidth, imageHeight);

    // Copy the image from the screen into the buffer.
    getimage(0, 0, imageWidth, imageHeight, image);

    // Once the image has been copied, clear it from the screen
    setcolor(WHITE);
    setfillstyle(SOLID_FILL, WHITE);
    bar(0, 0, imageWidth, imageHeight);
}

void Fruit::draw()
{
    x = getEllipse().getLeft() - imageWidth / 3.5;
    y = getEllipse().getTop() - imageHeight / 3.5;
    putimage(x, y, image, COPY_PUT);
}

void Fruit::undraw()
{
    int extention = 0; // changed here
    setcolor(COLOR(25, 75, 22));
    setfillstyle(SOLID_FILL, COLOR(25, 75, 22));
    bar(getEllipse().getLeft() - extention, getEllipse().getTop() - extention, getEllipse().getRight() + extention, getEllipse().getBottom() + extention);
}

void Fruit::handleFood(Boy *boi, Score *_score, int fruitSpeed)
{
    move(fruitSpeed);
    if (inBasket(boi))
    {
        _score->UpdateScore(score); // when its true

        // respawn
        undraw();
        ellipse.setX(rand() % getmaxwidth());
        ellipse.setY(-200);
    }
}

// Boy:: Boy(int _x , int _w, int _p , int _m)
// {
// //  width=_w; height=_h;
// }

// void Boy:: collectFood()
// {

// }

// void Boy:: draw()
// {

// }

// void Boy:: undraw()
// {

// }

// Boy::~Boy()
// {

// }
