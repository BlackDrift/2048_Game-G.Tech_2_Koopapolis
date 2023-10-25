#include "Map.h"
#include "Tile.h"
#include <iostream>
#include <cstdlib>

Map::Map()
{
	int position = 0;

	this->SetSize();
	for (int i = 0; i < size; ++i)
	{
		for (int j = 0; j < size; ++j)
		{
			position += 1;
			Tile tile;
			tile.value = 0;
			tile.x = i + 1;
			tile.y = j + 1;
			this->mContent.push_back((tile));
			tile.pos = position;
		}
	}
	for (int k = 0; k < 2; k++)
	{
		this->SpawnTile();
	}
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
		std::cout << this->mContent.at(i).value;
		if ((i + 1) % this->size == 0)
			std::cout << std::endl;
	}
}

void	Map::SpawnTile()
{
	srand(time(0));
	int pos = rand() % this->squareSize + 1;
	while (this->mContent.at(pos).value != 0)
		pos = rand() % this->squareSize + 1;
	this->mContent.at((pos)).value = (rand() % 2 + 1) * 2;
	
}

void	Map::ChangeMap(char direction)
{
	switch ()
	{
	case direction == 'L':
		this->mContent;
	}
}

