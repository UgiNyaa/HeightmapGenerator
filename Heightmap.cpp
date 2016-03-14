#include "Heightmap.h"

#ifndef heightmapcpp
#def heightmapcpp

Heightmap::Heightmap(int width, int height){
	this->width = width;
	this->height = height;
	
	pixels = new unsigned char[width * height];
}

Heightmap::getWidth(){
	return this->width;
}

Heightmap::getHeight(){
	return this->height;
}

#endif
