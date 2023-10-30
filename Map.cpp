#include "Map.h"
#include "Tile.h"
#include <iostream>


Map::Map()
{
	int position = 0;

	this->SetSize();
	for (int i = 0; i < size; ++i)
	{
		for (int j = 0; j < size; ++j)
		{			
			Tile tile;
			tile.value = 0;
			tile.x = i + 1;
			tile.y = j + 1;
			tile.pos = position;
			//std::cout << position;
			this->mContent.push_back((tile));
			position += 1;
		}
	}
	for (int k = 0; k < 2; k++)
		this->SpawnTile();
}

void	Map::SetSize()
{
	this->size = 4;
	this->squareSize = (this->size * this->size);
}

// PrintNb prints 5 - Nb size spaces to keep a 5 digits formated tab

void	Map::PrintNb(int nb)
{
	int	i = 1;
	int	tmp = nb;
	int	sizeMax = 5;
	while (tmp >= 10)
	{
		tmp = tmp / 10;
		++i;
	}
	for (int j = 0; j < (sizeMax - i); ++j)
	{
		std::cout << ' ';
	}
	std::cout << nb;
}

void	Map::PrintMap()
{
	for (int n = 0; n < (this->size * 5 + this->size + 1); n++)
	{
		std::cout << '-';
	}
	std::cout << std::endl;
	for (int i = 0; i < this->size; ++i)
	{
		for (int j = 0; j < this->size; j++)
		{
			if (j == 0 || j == this->size)
				std::cout << '|' ;
			PrintNb(this->TileAt(i,j).value);
			std::cout << '|';
		}
		std::cout << std::endl;
	}
	for (int m = 0; m < (this->size * 5 + this->size + 1); m++)
		std::cout << '-';
	if (this->isWon)
	{
		std::cout << std::endl << std::endl;
		std::cout << "GAME WON GOOD JOB" << std::endl;
		std::cout << "but you can still play" << std::endl;
	}
}

void	Map::SpawnTile()
{
	int pos = rand() % this->squareSize;
	while (this->mContent.at(pos).value != 0)
		pos = rand() % this->squareSize;
	this->mContent.at((pos)).value = this->mContent.at((pos)).GetNumber();
}

void	Map::RefreshScreen()
{
	system("cls");
	this->PrintMap();

}

// Get tile at (x, y) coords

Tile	Map::TileAt(int x, int y)
{
	return (this->mContent.at(4 * x + y));
}

//CheckIsDone checks CanMove and CanEvolve in all the directions but first checks if there is no empty tile.

bool	Map::CheckIsDone()
{
	for (int i = 0; i < this->squareSize; ++i)
	{
		if (this->mContent.at(i).value == 0)
			return false;
		else if (this->mContent.at(i).value == 2048 && !this->isWon)
			this->isWon = true;
	}
	for (int i = 0; i < this->squareSize; ++i)
	{
		if (this->CanMove('0', this->mContent.at(i)))
			return false;
		if (this->CanEvolve('0', this->mContent.at(i)))
			return false;
	}
	return true;
}

//MoveTiles calls the other move functions but for every single tile of the tab

void Map::MoveTiles(char direction)
{
	switch (direction)
	{
	case ('u'):
		for (int i = 0; i < this->squareSize; ++i)
		{
			this->MoveUp(this->mContent.at(i));
		}
		break;

	case ('d'):
		for (int i = this->squareSize - 1; i >= 0; --i)
		{
			this->MoveDown(this->mContent.at(i));
		}
		break;

	case ('l'):
		for (int i = 0; i < this->size; ++i)
		{
			for (int j = 0; j < this->size; j++)
			{
				this->MoveLeft(this->mContent.at(i + (this->size * j)));
			}
		}
		break;

	case ('r'):
		for (int i = this->size - 1; i >= 0; --i)
		{
			for (int j = this->size - 1; j >= 0; --j)
			{
				this->MoveRight(this->mContent.at(i + (this->size * j)));
			}
		}
		break;
	default:
		break;
	}
	this->SpawnTile();
	this->RefreshScreen();
}

bool Map::CanEvolve(char direction, Tile tile)
{
	int tileX = tile.x;
	int tileY = tile.y;

	switch (direction)
	{
	case('u'):
		if (tile.x > 1 && tile.value == this->TileAt(tileX - 2, tileY - 1).value && tile.value != 0)
			return true;
		break;
	case('d'):
		if (tile.x < 4 && tile.value == this->TileAt(tileX, tileY - 1).value && tile.value != 0)
			return true;
		break;
	case('l'):
		if (tile.y > 1 && tile.value == this->TileAt(tileX - 1, tileY - 2).value && tile.value != 0)
			return true;
		break;
	case('r'):
		if (tile.y < 4 && tile.value == this->TileAt(tileX - 1, tileY).value && tile.value != 0)
			return true;
		break;
// case ('0') is used for CheckIsDone and does all the cases together
	case('0'):
		if (tile.x > 1 && tile.value == this->TileAt(tileX - 2, tileY - 1).value && tile.value != 0)
			return true;
		else if (tile.x < 4 && tile.value == this->TileAt(tileX, tileY - 1).value && tile.value != 0)
			return true;
		else if (tile.y > 1 && tile.value == this->TileAt(tileX - 1, tileY - 2).value && tile.value != 0)
			return true;
		else if (tile.y < 4 && tile.value == this->TileAt(tileX - 1, tileY).value && tile.value != 0)
			return true;
		else
			return false;
	default:
		break;
	}
	return false;
}

bool Map::CanMove(char direction, Tile tile)
{
	int	tileX = tile.x;
	int tileY = tile.y;
	int position = tile.pos;

	switch (direction)
	{
		
	case('u'):
		if (tile.value != 0 && tile.x > 1 && TileAt(tileX - 2, tileY - 1).value == 0)
			return true;
		break;
	case ('d'):
		if (tile.value != 0 && tile.x < 4 && TileAt(tileX, tileY - 1).value == 0)
			return true;
		break;
	case ('l'):
		if (tile.value != 0 && tile.y > 1 && TileAt(tileX - 1, tileY - 2).value == 0)
			return true;
		break;
	case ('r'):
		if (tile.value != 0 && tile.y < 4 && TileAt(tileX - 1, tileY).value == 0)
			return true;
		break;
	case('0'):
// case ('0') is used for CheckIsDone and does all the cases together
		if (tile.value != 0 && tile.x > 1 && TileAt(tileX - 2, tileY - 1).value == 0)
			return true;
		else if (tile.value != 0 && tile.x < 4 && TileAt(tileX, tileY - 1).value == 0)
			return true;
		else if (tile.value != 0 && tile.y > 1 && TileAt(tileX - 1, tileY - 2).value == 0)
			return true;
		else if (tile.value != 0 && tile.y < 4 && TileAt(tileX - 1, tileY).value == 0)
			return true;
		else
			return false;
	}
	return false;
}

void Map::Swap(char direction, Tile tile)
{
	switch (direction)
	{
	case('u'):
		this->mContent.at(tile.pos - 4).value = tile.value;
		this->mContent.at(tile.pos).Reset();
		break;
	case('d'):
		this->mContent.at(tile.pos + 4).value = tile.value;
		this->mContent.at(tile.pos).Reset();
		break;
	case('l'):
		this->mContent.at(tile.pos - 1).value = tile.value;
		this->mContent.at(tile.pos).Reset();
		break;
	case('r'):
		this->mContent.at(tile.pos + 1).value = tile.value;
		this->mContent.at(tile.pos).Reset();
		break;
	}
}


// Move in direction functions


void Map::MoveUp(Tile tile)
{
	bool	hasEvolved = false;
	for (int i = 0; i < tile.x + 1; ++i)
	{
		if (CanEvolve('u', tile) && !hasEvolved)
		{
			this->mContent.at(tile.pos - 4).Evolve();
			this->mContent.at(tile.pos).Reset();
			hasEvolved = true;
		}
		else if (CanMove('u', tile))
		{
			this->Swap('u', tile);
			tile = this->mContent.at(tile.pos - 4);
		}
		else
		{
			i = tile.x;
		}
	}
}

void Map::MoveDown(Tile tile)
{
	bool	hasEvolved = false;
	for (int i = tile.x + 1; i >= 0; --i)
	{
		if (CanEvolve('d', tile) && !hasEvolved)
		{
			this->mContent.at(tile.pos + 4).Evolve();
			this->mContent.at(tile.pos).Reset();
			hasEvolved = true;
		}
		else if (CanMove('d', tile))
		{
			this->Swap('d', tile);
			tile = this->mContent.at(tile.pos + 4);
		}
		else
		{
			i = 0;
		}
	}
}

void Map::MoveLeft(Tile tile)
{
	bool	hasEvolved = false;
	for (int i = 0; i < tile.y + 1; ++i)
	{
		if (CanEvolve('l', tile) && !hasEvolved)
		{
			this->mContent.at(tile.pos - 1).Evolve();
			this->mContent.at(tile.pos).Reset();
			hasEvolved = true;
		}
		else if (CanMove('l', tile))
		{
			this->Swap('l', tile);
			tile = this->mContent.at(tile.pos - 1);
		}
		else
		{
			i = tile.y;
		}
	}
}

void Map::MoveRight(Tile tile)
{
	bool	hasEvolved = false;
	for (int i = tile.y + 1; i >= 0; --i)
	{
		if (CanEvolve('r', tile) && !hasEvolved)
		{
			this->mContent.at(tile.pos + 1).Evolve();
			this->mContent.at(tile.pos).Reset();
			hasEvolved = true;
		}
		else if (CanMove('r', tile))
		{
			this->Swap('r', tile);
			tile = this->mContent.at(tile.pos + 1);
		}
		else
		{
			i = 0;
		}
	}
}
