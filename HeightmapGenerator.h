#include "Heightmap.cpp"
#include "Point.cpp"

#ifndef heightmapgenerator_h_included
#define heightmapgenerator_h_included

class HeightmapGenerator{
	private:
	void diamond(Heightmap heightmap, Point points[], int sizex, int sizey);
	void square(Heightmap heightmap, Point points[], int sizex, int sizey);
	
	int myavg(int a, int b, int c, int d);
	void gen4valdia(Heightmap heightmap,
					Point a, Point b, Point c, Point d, 
					int hsx, int hsy, 
					int& valuea, int& valueb, int& valuec, int& valued);
	void gen4valsqr(Heightmap heightmap,
					Point a, Point b, Point c, Point d, 
					int hsx, int hsy, 
					int& valuea, int& valueb, int& valuec, int& valued);
	public:
	HeightmapGenerator();
	Heightmap Generate(int width, int height);
	
};

#endif
