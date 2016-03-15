#include "Heightmap.h"
#include <iostream>
#include <fstream>

#ifndef heightmap_cpp_included
#define heightmap_cpp_included

using namespace std;

Heightmap::Heightmap(int width, int height){
	this->width = width;
	this->height = height;
	
	pixels = new unsigned char[width * height];
	
	for (int i = 0; i < (width * height); i++){
		pixels[i] = 0;
	}
}

Heightmap::~Heightmap(){
	delete pixels;
}

int Heightmap::getWidth(){
	return this->width;
}

int Heightmap::getHeight(){
	return this->height;
}

int Heightmap::getPixel(unsigned int x, unsigned int y){
	
	if (x < 0 || x >= width-1)
		return -1;
	
	if (y < 0 || y >= height-1)
		return -1;
	
	return (int)pixels[width * y + x];
}

void Heightmap::setPixel(unsigned int x, unsigned int y, unsigned char color){
	if (x > width)
		return;
	
	if (y > height)
		return;
	
	pixels[width * y + x] = color;
}

#endif
