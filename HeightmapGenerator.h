#include "Heightmap.cpp"

#ifndef heightmapgeneratorh
#define heightmapgeneratorh

struct Point{
	int x;
	int y;
	Point();
	Point(int x, int y){this->x=x;this->y=y;}
};

class HeightmapGenerator{
	private:
	void diamond(Heightmap heightmap, Point points, int sizex, int sizey, int width, int height);
	void square(Heightmap heightmap, Point points, int sizex, int sizey, int width, int height);
	
	public:
	HeightmapGenerator();
	Heightmap Generate(int width, int height);
	
};

#endif
