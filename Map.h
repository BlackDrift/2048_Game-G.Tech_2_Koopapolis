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
	bool CheckIsDone();
	Tile TileAt(int* tab);
	void MoveTiles(char direction);
	bool CanEvolve(char direction, Tile tile);
	bool CanMove(char direction, Tile tile);
	void Swap(char direction, Tile tile);
	void MoveUp(Tile tile);
	void MoveDown(Tile tile);
	void MoveLeft(Tile tile);
	void MoveRight(Tile tile);

	//Destructor
};
