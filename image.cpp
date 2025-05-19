// The implementation file
#include <sstream>
#include <string>
#include <graphics.h>
#include "image.hpp"
using namespace std;




Image::Image(int w, int h, string imageDir){
    imageWidth = w;
    imageHeight = h;

    size = imagesize(0,0, imageWidth, imageHeight); // memory size in bytes
    image = new char[size];

    // read image from the external file and put it anywhere on the screen
	//   to prepare for the getimage(), as getimage() must get image from the screen

	readimagefile(imageDir.c_str(), 0, 0, imageWidth, imageHeight);

	// Copy the image from the screen into the buffer.
	getimage( 0, 0, imageWidth, imageHeight, image);

	// Once the image has been copied, clear it from the screen
	setcolor(WHITE);
	setfillstyle(SOLID_FILL, WHITE);
	bar( 0, 0, imageWidth, imageHeight);
}

void Image::draw(int x, int y){
    putimage(x, y, image, COPY_PUT);
}

void Image::updateImage(string dir){
    
}


 


