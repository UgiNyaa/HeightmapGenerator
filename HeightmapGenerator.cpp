#include "HeightmapGenerator.h"
#include "Heightmap.cpp"

#ifndef heightmapgeneratorcpp
#define heightmapgeneratorcpp

struct Point{
	int x;
	int y;
	Point(int x, int y){this->x=x;this->y=y;}
};

HeightmapGenerator::HeightmapGenerator(){}

Heightmap HeightmapGenerator::Generate(int width, int height){
	Heightmap heightmap(width, height);
	Point points[width * height];
	
	for (int i = 0; i < (width * height); i++){
		points[i] = -1;
	}
	
	srand(time(0));
	
	heightmap.setPixel(0,       0,        rand() % 256);
	heightmap.setPixel(width-1, 0,        rand() % 256);
	heightmap.setPixel(0,       height-1, rand() % 256);
	heightmap.setPixel(width-1, height-1, rand() % 256);
	
	definedChars[0]                              = height.getPixel(0,       0);
	definedChars[width-1]                        = height.getPixel(width-1, 0);
	definedChars[width * (height-1)]             = height.getPixel(0,       height-1);
	definedChars[width * (height-1) + (width-1)] = height.getPixel(width-1, height-1);
	
	diamond(heightmap, definedChars, width-1, height-1, width, height);
	}

void diamond(Heightmap heightmap, Point points, int sizex, int sizey, int width, int height){
	int hsx = sizex / 2;
	int hsy = sizey / 2;
	
	for (int i = 0; i < points.Length; i++)
	{
		Point point = points[i];
		Point a(point.x - hsx, point.y - hsy);
		Point b(point.x + hsx, point.y - hsy);
		Point c(point.x - hsx, point.y + hsy);
		Point d(point.x + hsx, point.y + hsy);
		
		int valuea = (
		(heightmap.getPixel(a.x - hsx, a.y - hsy))+
		(heightmap.getPixel(a.x + hsx, a.y - hsy))+
		(heightmap.getPixel(a.x - hsx, a.y + hsy))+
		(heightmap.getPixel(a.x + hsx, a.y + hsy))
		) / 4;
		
		int valueb = (
		(heightmap.getPixel(b.x - hsx, b.y - hsy))+
		(heightmap.getPixel(b.x + hsx, b.y - hsy))+
		(heightmap.getPixel(b.x - hsx, b.y + hsy))+
		(heightmap.getPixel(b.x + hsx, b.y + hsy))
		) / 4;
		
		int valuec = (
		(heightmap.getPixel(c.x - hsx, c.y - hsy))+
		(heightmap.getPixel(c.x + hsx, c.y - hsy))+
		(heightmap.getPixel(c.x - hsx, c.y + hsy))+
		(heightmap.getPixel(c.x + hsx, c.y + hsy))
		) / 4;
		
		int valued = (
		(heightmap.getPixel(d.x - hsx, d.y - hsy))+
		(heightmap.getPixel(d.x + hsx, d.y - hsy))+
		(heightmap.getPixel(d.x - hsx, d.y + hsy))+
		(heightmap.getPixel(d.x + hsx, d.y + hsy))
		) / 4;
		
		if (a.x >= 0 && a.x < width &&
		    a.y >= 0 && a.x < height)
			heightmap.setPoint(a.x, a.y, valuea);
		
		if (b.x >= 0 && b.x < width &&
		    b.y >= 0 && b.x < height)
			heightmap.setPoint(b.x, b.y, valueb);
		
		if (c.x >= 0 && c.x < width &&
		    c.y >= 0 && c.x < height)
			heightmap.setPoint(c.x, c.y, valuec);
		
		if (d.x >= 0 && d.x < width &&
		    d.y >= 0 && d.x < height)
			heightmap.setPoint(d.x, d.y, valuea);
	}
	
	square(heightmap, points, sizex, sizey, width, height);
}

void square(Heightmap heightmap, Point points, int sizex, int sizey, int width, int height){
	
	
	sizex = sizex / 2;
	sizey   = sizey / 2;
	diamond(heightmap, points, sizex, sizey, width, height);
}

#endif
