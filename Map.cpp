#include "Map.h"
#include "Tile.h"
#include <iostream>

Map::Map()
{
	this->SetSize();
	for (int i = 0; i < this->squareSize; ++i)
			this->mContent.push_back(('0'));
}

void	Map::SetSize()
{
	this->size = 4;
	this->squareSize = (this->size * this->size);
}

void	Map::PrintMap()
{
	for (int i = 0; i < this->squareSize; ++i)
	{
		std::cout << this->mContent.at(i);
		if ((i + 1) % this->size == 0)
			std::cout << std::endl;
	}
}

void	Map::SpawnTile()
{
	Tile tile;
	int	x;
	int	y;

	x = rand() % this->size + 1;
	y = rand() % this->size + 1;

	this->mContent.at((x * y)) = tile.value;
}

