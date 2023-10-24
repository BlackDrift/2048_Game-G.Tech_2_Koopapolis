#pragma once

#include <vector>
#include "Tile.h"

class Map
{
public:

	//Attributes
	int	size;
	int squareSize;
	std::vector<Tile> mContent;

	//Constructor
	Map();

	//Method
	void SetSize();
	void PrintMap();
	void SpawnTile();
	//Destructor
};
