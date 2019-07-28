#ifndef MAPCHIP
#define MAPCHIP

class MapchipLoading {
public:
	int** mapchip(const char* filename, int Hrow, int Hcol, int** data);
	int textureprint(int** F, int s, int d);

};

#endif // !MAPCHIP
