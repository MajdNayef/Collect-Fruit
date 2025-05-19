
#ifndef Vegetable_H
#define Vegetable_H
#include <graphics.h>
#include "Boy.hpp"
#include "ellipsee.hpp"
#include "score.hpp"
#include "food.hpp"
#include <string>
using namespace std;

class Vegetable : public Food
{
protected:
	string tomatoPath = "Assets/tomato.jpg";
	string peaPath = "Assets/pea.jpg";
	string potatoPath = "Assets/potato.jpg";
    string vegPath;

    int size;
	void *image;

    int imageWidth = 100;
	int imageHeight = 100;

	int x = 0;
	int y = 0;

public:
Vegetable();
Vegetable(int _x, int _y, int _rx, int _ry, int _color, int _score);

void draw();

void undraw();


 //overriding   
void handleFood(Boy* boi, Score* _score, int fruitSpeed);
};

// 
#endif
