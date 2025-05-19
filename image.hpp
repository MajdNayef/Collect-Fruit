// The specification file
#ifndef Image_H
#define Image_H
#include <graphics.h>
#include <string>
using namespace std;

class Image
{
private:
	int size;
	void *image;

	int imageWidth = 100;
	int imageHeight = 100;

public:
	Image(int w, int h, string imageDir);

	void draw(int x, int y);

	void updateImage(string dir);
};

#endif
