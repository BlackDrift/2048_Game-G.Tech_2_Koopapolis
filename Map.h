#pragma once

#include <vector>
#include "Tile.h"
#include <string>

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
	void RefreshScreen();
	bool CanMove(Tile tile);
	bool CheckIsDone();
	//void ChangeMap(int direction);
	//Destructor
};
