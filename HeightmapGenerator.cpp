#include "HeightmapGenerator.h"
#include "Heightmap.cpp"
#include "Point.cpp"
#include <cstdlib>
#include <ctime>

#ifndef heightmapgenerator_cpp_included
#define heightmapgenerator_cpp_included

HeightmapGenerator::HeightmapGenerator(){}

Heightmap HeightmapGenerator::Generate(int width, int height){
	Heightmap heightmap(width, height);
	Point points[width * height];
	
	for (int i = 0; i < (width * height); i++){
		points[i] = Point(-1,-1);
	}
	
	srand(time(0));
	
	heightmap.setPixel(0,       0,        rand() % 256);
	heightmap.setPixel(width-1, 0,        rand() % 256);
	heightmap.setPixel(0,       height-1, rand() % 256);
	heightmap.setPixel(width-1, height-1, rand() % 256);
	
	points[0]                              = Point(0, 0);                             
	points[width-1]                        = Point(width-1, 0);
	points[width * (height-1)]             = Point(0, height-1);
	points[width * (height-1) + (width-1)] = Point(width-1, height-1);
	
	diamond(heightmap, points, width, height);
	}

void HeightmapGenerator::diamond(Heightmap heightmap, Point points[], int sizex, int sizey){
	int hsx = sizex / 2;
	int hsy = sizey / 2;
	
	for (int i = 0; i < heightmap.getWidth() * heightmap.getHeight(); i++)
	{
		Point point = points[i];
		if (point.x != -1 || point.y != -1)
			continue;
		
		// generate the 4 points to be filled
		Point a(point.x - hsx, point.y - hsy);
		Point b(point.x + hsx, point.y - hsy);
		Point c(point.x - hsx, point.y + hsy);
		Point d(point.x + hsx, point.y + hsy);

		// generate the 4 values of colour the points will have
		int valuea, valueb, valuec, valued;
		gen4valdia(heightmap,a,b,c,d,hsx,hsy,valuea,valueb,valuec,valued);
		
		// if our calculated points does not exist, just skip them
		if (a.x >= 0 && a.x < heightmap.getWidth() &&
		    a.y >= 0 && a.x < heightmap.getHeight())
			heightmap.setPixel(a.x, a.y, valuea);
		
		if (b.x >= 0 && b.x < heightmap.getWidth() &&
		    b.y >= 0 && b.x < heightmap.getHeight())
			heightmap.setPixel(b.x, b.y, valueb);
		
		if (c.x >= 0 && c.x < heightmap.getWidth() &&
		    c.y >= 0 && c.x < heightmap.getHeight())
			heightmap.setPixel(c.x, c.y, valuec);
		
		if (d.x >= 0 && d.x < heightmap.getWidth() &&
		    d.y >= 0 && d.x < heightmap.getHeight())
			heightmap.setPixel(d.x, d.y, valuea);
	}
	
	//after doing the diamond part, do the square part
	square(heightmap, points, sizex, sizey);
}

void HeightmapGenerator::square(Heightmap heightmap, Point points[], int sizex, int sizey){

	int hsx = sizex / 2;
	int hsy = sizey / 2;
	
	for (int i = 0; i < heightmap.getWidth() * heightmap.getHeight(); i++)
	{
		// generate the 4 points to be filled
		Point point = points[i];
		Point a(point.x, point.y - hsy);
		Point b(point.x + hsx, point.y);
		Point c(point.x - hsx, point.y);
		Point d(point.x, point.y + hsy);

		// generate the 4 values of colour the points will have
		int valuea, valueb, valuec, valued;
		gen4valsqr(heightmap,a,b,c,d,hsx,hsy,valuea,valueb,valuec,valued);
		
		// if our calculated points does not exist, just skip them
		if (a.x >= 0 && a.x < heightmap.getWidth() &&
		    a.y >= 0 && a.x < heightmap.getHeight())
			heightmap.setPixel(a.x, a.y, valuea);
		
		if (b.x >= 0 && b.x < heightmap.getWidth() &&
		    b.y >= 0 && b.x < heightmap.getHeight())
			heightmap.setPixel(b.x, b.y, valueb);
		
		if (c.x >= 0 && c.x < heightmap.getWidth() &&
		    c.y >= 0 && c.x < heightmap.getHeight())
			heightmap.setPixel(c.x, c.y, valuec);
		
		if (d.x >= 0 && d.x < heightmap.getWidth() &&
		    d.y >= 0 && d.x < heightmap.getHeight())
			heightmap.setPixel(d.x, d.y, valuea);
	}
	
	
	if (sizex >= 1 && sizey >= 1)
		return;
	
	sizex = sizex / 2;
	sizey   = sizey / 2;
	diamond(heightmap, points, sizex, sizey);
}

int HeightmapGenerator::myavg(int a, int b, int c, int d){
	int count = 4;
	
	if (a == -1){
		a = 0;
		count --;
	}
	
	if (b == -1){
		b = 0;
		count --;
	}
	
	if (c == -1){
		c = 0;
		count --;
	}
	
	if (d == -1){
		d = 0;
		count --;
	}
	
	return (a+b+c+d)/count;
}

void HeightmapGenerator::gen4valdia (
	Heightmap heightmap,
	Point a, Point b, Point c, Point d, 
    int hsx, int hsy, 
	int& valuea, int& valueb, int& valuec, int& valued){
	valuea = myavg(
	(heightmap.getPixel(a.x - hsx, a.y - hsy)),
	(heightmap.getPixel(a.x + hsx, a.y - hsy)),
	(heightmap.getPixel(a.x - hsx, a.y + hsy)),
	(heightmap.getPixel(a.x + hsx, a.y + hsy))
	);
		
	valueb = myavg(
	(heightmap.getPixel(b.x - hsx, b.y - hsy)),
	(heightmap.getPixel(b.x + hsx, b.y - hsy)),
	(heightmap.getPixel(b.x - hsx, b.y + hsy)),
	(heightmap.getPixel(b.x + hsx, b.y + hsy))
	);
		
	valuec = myavg(
	(heightmap.getPixel(c.x - hsx, c.y - hsy)),
	(heightmap.getPixel(c.x + hsx, c.y - hsy)),
	(heightmap.getPixel(c.x - hsx, c.y + hsy)),
	(heightmap.getPixel(c.x + hsx, c.y + hsy))
	);
		
	valued = myavg(
	(heightmap.getPixel(d.x - hsx, d.y - hsy)),
	(heightmap.getPixel(d.x + hsx, d.y - hsy)),
	(heightmap.getPixel(d.x - hsx, d.y + hsy)),
	(heightmap.getPixel(d.x + hsx, d.y + hsy))
	);	  
}

void HeightmapGenerator::gen4valsqr (
	Heightmap heightmap,
	Point a, Point b, Point c, Point d, 
    int hsx, int hsy, 
	int& valuea, int& valueb, int& valuec, int& valued){
	valuea = myavg(
	(heightmap.getPixel(a.x, a.y - hsy)),
	(heightmap.getPixel(a.x + hsx, a.y)),
	(heightmap.getPixel(a.x - hsx, a.y)),
	(heightmap.getPixel(a.x, a.y + hsy))
	);
		
	valueb = myavg(
	(heightmap.getPixel(b.x, b.y - hsy)),
	(heightmap.getPixel(b.x + hsx, b.y)),
	(heightmap.getPixel(b.x - hsx, b.y)),
	(heightmap.getPixel(b.x, b.y + hsy))
	);
		
	valuec = myavg(
	(heightmap.getPixel(c.x, c.y - hsy)),
	(heightmap.getPixel(c.x + hsx, c.y)),
	(heightmap.getPixel(c.x - hsx, c.y)),
	(heightmap.getPixel(c.x, c.y + hsy))
	);
		
	valued = myavg(
	(heightmap.getPixel(d.x, d.y - hsy)),
	(heightmap.getPixel(d.x + hsx, d.y)),
	(heightmap.getPixel(d.x - hsx, d.y)),
	(heightmap.getPixel(d.x, d.y + hsy))
	);	  
}

#endif
