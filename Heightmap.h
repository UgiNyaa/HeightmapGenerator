#ifndef heightmaph
#def heightmaph

class Heightmap{
	private:
	unsigned char *pixels;
	int width;
	int height;
	
	public:
	Heightmap(int width, int height);
	int getWidth();
	int getHeight();
	
}

#endif
