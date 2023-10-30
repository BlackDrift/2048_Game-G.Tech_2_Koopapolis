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
	bool isWon;
	std::vector<Tile> mContent;

	//Constructor
	Map();

	//Method
	void SetSize();
	void PrintMap();
	void SpawnTile();
	void RefreshScreen();
	bool CanMove(char direction, Tile tile);
	bool CheckIsDone();
	void PrintNb(int nb);
	Tile TileAt(int x, int y);
	void MoveTiles(char direction);
	bool CanEvolve(char direction, Tile tile);
	void Swap(char direction, Tile tile);
	void MoveUp(Tile tile);
	void MoveDown(Tile tile);
	void MoveLeft(Tile tile);
	void MoveRight(Tile tile);

	//Destructor
};
