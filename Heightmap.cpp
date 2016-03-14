#include "Heightmap.h"
#include <iostream>
#include <cstdlib>
#include <ctime>
#include <fstream>

#ifndef heightmapcpp
#define heightmapcpp

using namespace std;

Heightmap::Heightmap(int width, int height){
	this->width = width;
	this->height = height;
	
	pixels = new unsigned char[width * height];
	
	srand(time(0));
	
	for (int i = 0; i < (width * height); i++){
		pixels[i] = rand() % 256;
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
	return (int)pixels[width * y + x];
}

void Heightmap::setPixel(unsigned int x, unsigned int y, unsigned char color){
	if (x > width)
		return;
	
	if (y > height)
		return;
	
	pixels[width * y + x] = color;
}

main()
{
	Heightmap heightmap(100, 100);
	
	cout << "Start Writing..." << endl;
	
	ofstream f("heightmap.pgm", ios_base::out
	                      |ios_base::binary
                          |ios_base::trunc
	);
	
	f << "P5\n" << heightmap.getWidth() << " " 
	<< heightmap.getHeight() << "\n" << "255\n";
	
	for(int i = 0; i < heightmap.getWidth(); i++){
		for(int j = 0; j < heightmap.getWidth(); j++){
			f << (unsigned char)heightmap.getPixel(i, j);
		}
	}
	
	f.close();
	cout << "end" << endl;
}

#endif
