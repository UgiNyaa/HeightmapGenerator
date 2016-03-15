#ifndef heightmap_h_included
#define heightmap_h_included

class Heightmap{
	private:
	unsigned char *pixels;
	int width;
	int height;
	
	public:
	Heightmap(int width, int height);
	~Heightmap();
	
	int getWidth();
	int getHeight();
	
	int getPixel(unsigned int x, unsigned int y);
	void setPixel(unsigned int x, unsigned int y, unsigned char color);
	
};

#endif
