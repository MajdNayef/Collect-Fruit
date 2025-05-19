

#include <graphics.h>
#include "Boy.hpp"
#include "ellipsee.hpp"
#include "score.hpp"
#include "food.hpp"
#include "vegetable.hpp"



Vegetable:: Vegetable() : Food(){};
Vegetable:: Vegetable(int _x, int _y, int _rx, int _ry, int _color, int _score) : Food(_x, _y, _rx, _ry, _color){
    score = _score;

    string vegPaths[3] = {tomatoPath, peaPath, potatoPath};
    vegPath = vegPaths[rand() % 3];

    size = imagesize(0,0, imageWidth, imageHeight); // memory size in bytes
    image = new char[size];

    // read image from the external file and put it anywhere on the screen
	//   to prepare for the getimage(), as getimage() must get image from the screen

	readimagefile(vegPath.c_str(), 0, 0, imageWidth, imageHeight);

	// Copy the image from the screen into the buffer.
	getimage( 0, 0, imageWidth, imageHeight, image);

	// Once the image has been copied, clear it from the screen
	setcolor(BLACK);
	setfillstyle(SOLID_FILL, BLACK);
	bar( 0, 0, imageWidth, imageHeight);

}
void Vegetable::draw(){
    x = getEllipse().getLeft() - imageWidth / 3.5;
    y = getEllipse().getTop() - imageHeight / 3.5;
    putimage(x, y, image, COPY_PUT);
}

void Vegetable::undraw() { 
    int extention = 0;
    setcolor(COLOR(25, 75, 22));
	setfillstyle(SOLID_FILL, COLOR(25, 75, 22));
	bar( getEllipse().getLeft() - extention, getEllipse().getTop()- extention, getEllipse().getRight()+ extention, getEllipse().getBottom()+ extention);
    }


 //overriding   
void Vegetable::handleFood(Boy* boi, Score* _score, int fruitSpeed)
{
    move(fruitSpeed); 
    if(inBasket(boi)){
        boi->hurt();

        //respawn
        undraw();
        ellipse.setX(rand() % getmaxwidth());
        ellipse.setY(-1000);
    } 
}





