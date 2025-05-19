// The specification file
#ifndef Fruit_H
#define Fruit_H
#include <graphics.h>
#include "Boy.hpp"
#include "ellipsee.hpp"
#include "score.hpp"
#include "food.hpp"

#include<string>
using namespace std;

class Fruit : public Food
{
protected:
    string applePath = "Assets/apple.jpg";
	string bananasPath = "Assets/bananas.jpg";
	string dorianPath = "Assets/dorian.jpeg";
	string orangePath = "Assets/orange.jpg";
    
    string fruitPath;


    int size;
	void *image;

    int imageWidth = 100;
	int imageHeight = 100;

	int x = 0;
	int y = 0;

public:
Fruit();
Fruit(int _x, int _y, int _rx, int _ry, int _color = WHITE, int _score = 1);

void draw();

void undraw();

void handleFood(Boy* boi, Score* _score, int fruitSpeed);
};

// 
#endif























//Boy(int _x=0 , int _w=0, int _p=0 , int m = 0);



// second Class
// class Boy
// {

// public:

// Boy(int _x=0 , int _w=0, int _p=0 , int _m = 0); // constructor  method

// void draw();
// void undraw();
// void collectFood();

// ~Boy(); // destructor method

// };
