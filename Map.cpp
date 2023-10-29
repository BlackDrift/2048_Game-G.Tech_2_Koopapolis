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
	{
		this->SpawnTile();
	}
}

void	Map::SetSize()
{
	this->size = 4;
	this->squareSize = (this->size * this->size);
}

void	Map::PrintNb(int nb)
{
	int	i = 1;
	int	tmp = nb;
	int	sizeMax = 5;
	while (tmp / 10 >= 10)
	{
		tmp /= 10;
		i++;
	}
	for (int j = 0; j < (sizeMax - i); j++)
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

Tile	Map::TileAt(int x, int y)
{
	return (this->mContent.at(4 * x + y));
}


bool	Map::CheckIsDone()
{
	bool res;

	res = true;
	for (int i = 0; i < this->squareSize; ++i)
	{
		if (this->mContent.at(i).value != 0 && this->CanMove('0', this->mContent.at(i)) == true)
		{
			res = false;
		}
	}
	return res;
}


void Map::MoveTiles(char direction)
{
	switch (direction)
	{
	case ('u'):
		std::cout << "MoveTiles 'u'" << std::endl;
		for (int i = 0; i < this->squareSize; ++i)
		{
			std::cout << "Tile at " << i << " with value : " << this->mContent.at(i).value << std::endl;
			this->MoveUp(this->mContent.at(i));
			std::cout << "Tile at pos : " << i << " DONE" << std::endl << std::endl << std::endl;
		}
		this->PrintMap();
		break;

	case ('d'):
		std::cout << "MoveTiles 'd'" << std::endl;
		for (int i = this->squareSize - 1; i >= 0; --i)
		{
			std::cout << "Tile at " << i << " with value : " << this->mContent.at(i).value << std::endl;
			this->MoveDown(this->mContent.at(i));
			std::cout << "Tile at pos : " << i << " DONE" << std::endl << std::endl << std::endl;
		}
		this->PrintMap();
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
			for (int j = 0; j < this->size; j++)
			{
				this->MoveRight(this->mContent.at(i + (this->size * j)));
			}
		}
		break;
	default:
		break;
	}
}

bool Map::CanEvolve(char direction, Tile tile)
{
	int tileX = tile.x;
	int tileY = tile.y;
	std::cout << "Can Evolve Check" << std::endl;

	switch (direction)
	{
	case('u'):
		std::cout << "Can Evolve Check 'u'" << std::endl;
		std::cout << tile.x << " = tile.x | " << tile.value << " = tile.value" << std::endl;
		if (tile.x > 1 && tile.value == this->TileAt(tileX - 2, tileY - 1).value && tile.value != 0)
		{
			return true;
		}
		break;
	case('d'):
		std::cout << "Can Evolve Check 'd'" << std::endl;
		std::cout << tile.x << " = tile.x | " << tile.value << " = tile.value" << std::endl;
		if (tile.x < 4 && tile.value == this->TileAt(tileX, tileY - 1).value && tile.value != 0)
		{
			return true;
		}
		break;
	case('l'):
		if (tile.y > 1 && tile.value == this->TileAt(tileX - 1, tileY - 2).value && tile.value != 0)
			return true;
		break;
	case('r'):
		if (tile.y < 4 && tile.value == this->TileAt(tileX - 1, tileY).value && tile.value != 0)
		{
			return true;
		}
		break;
	default:
		std::cout << "Can Evolve no1" << std::endl;
		break;
	}
	std::cout << "Can Evolve no" << std::endl;
	return false;
}

bool Map::CanMove(char direction, Tile tile)
{
	int	tileX = tile.x;
	int tileY = tile.y;
	int position = tile.pos;

	std::cout << std::endl << std::endl << std::endl << std::endl << std::endl;
	std::cout << "call Can Move" << std::endl;
	std::cout << "Tile.value == " << tile.value << " | Position == " << position << " | tileX == " << tileX << " | tileY == " << tileY << std::endl;

	switch (direction)
	{
		
	case('u'):
		if (tile.value != 0 && tile.x > 1 && TileAt(tileX - 2, tileY - 1).value == 0)
		{
			std::cout << "Tile y - 1 pos == " << TileAt(tileX - 2, tileY - 1).pos << std::endl;
			return true;
		}
		break;
	case ('d'):
		if (tile.value != 0 && tile.x < 4 && TileAt(tileX, tileY - 1).value == 0)
		{
			return true;
		}
		break;
	case('l'):
		if (tile.value != 0 && tile.y > 1 && TileAt(tileX - 1, tileY - 2).value == 0)
		{
			return true;
		}
		break;
	case('r'):
		if (tile.value != 0 && tile.y < 4 && TileAt(tileX - 1, tileY).value == 0)
		{
			return true;
		}
		break;
	/*case('0'):
		if ((position + 1 >= 0 && position + 1 < 16) && ((this->mContent.at(position + 1).value == 0)) || (this->mContent.at(position + 1).value == this->mContent.at(position).value))
			return true;
		else if ((position - 1 >= 0 && position - 1 < 16) && ((this->mContent.at(position - 1).value == 0)) || (this->mContent.at(position - 1).value == this->mContent.at(position).value))
			return true;
		else if ((position + 4 >= 0 && position + 4 < 16) && ((this->mContent.at(position + 4).value == 0)) || (this->mContent.at(position + 4).value == this->mContent.at(position).value))
			return true;
		else if ((position - 4 >= 0 && position - 4 < 16) && ((this->mContent.at(position - 4).value == 0)) || (this->mContent.at(position - 4).value == this->mContent.at(position).value))
			return true;
		else
			return false;*/
	}
	std::cout << "TEST" << std::endl;
	//std::cout << "tileX = " << tile.x << " | Tile value x - 1 == " << TileAt(tileX - 1, tileY).value << std::endl;
	std::cout << "Can't Move" << std::endl;
	return false;
}

void Map::Swap(char direction, Tile tile)
{
	std::cout << "SWAP : " << tile.pos << std::endl;
	switch (direction)
	{
	case('u'):
		std::cout << "Tile.value == " << tile.value << " | Tile(x-1).value == " << this->mContent.at(tile.pos - 4).value << std::endl;
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


void Map::MoveUp(Tile tile)
{
	bool	hasEvolved = false;
	std::cout << "tile.y == " << tile.y << std::endl;
	for (int i = 0; i < tile.x + 1; ++i)
	{
		std::cout << "Moveup tour " << i << std::endl;
		if (CanEvolve('u', tile) && !hasEvolved)
		{
			std::cout << "CanEvolve True" << std::endl;
			this->mContent.at(tile.pos - 4).Evolve();
			this->mContent.at(tile.pos).Reset();
			hasEvolved = true;
		}
		else if (CanMove('u', tile))
		{
			std::cout << "CanMove True" << std::endl;
			this->Swap('u', tile);
			tile = this->mContent.at(tile.pos - 4);
		}
		else
		{
			i = tile.x;
			std::cout << "Can't Move nor Evolve up" << std::endl;
		}
	}
	this->PrintMap();
	std::cout << std::endl;
	//std::cout << "Can't Move nor Evolve" << std::endl;
}

void Map::MoveDown(Tile tile)
{
	bool	hasEvolved = false;
	std::cout << "tile.y == " << tile.y << std::endl;
	for (int i = tile.x + 1; i >= 0; --i)
	{
		std::cout << "Movedown tour " << i << std::endl;
		if (CanEvolve('d', tile) && !hasEvolved)
		{
			std::cout << "CanEvolve True" << std::endl;
			this->mContent.at(tile.pos + 4).Evolve();
			this->mContent.at(tile.pos).Reset();
			hasEvolved = true;
		}
		else if (CanMove('d', tile))
		{
			std::cout << "CanMove True" << std::endl;
			this->Swap('d', tile);
			tile = this->mContent.at(tile.pos + 4);
		}
		else
		{
			i = 0;
			std::cout << "Can't Move nor Evolve up" << std::endl;
		}
	}
	this->PrintMap();
	std::cout << std::endl;
	//std::cout << "Can't Move nor Evolve" << std::endl;
}

void Map::MoveLeft(Tile tile)
{
	if (CanEvolve('l', tile))
	{
		this->mContent.at(tile.pos - 1).Evolve();
		tile.Reset();
	}
	else if (CanMove('l', tile))
	{
		while (CanMove('l', tile) && tile.pos % 4 != 0){
			this->Swap('l', tile);
			tile = this->mContent.at(tile.pos - 1);
		}

	}
}

void Map::MoveRight(Tile tile)
{
	if (CanEvolve('r', tile))
	{
		this->mContent.at(tile.pos + 1).Evolve();
		tile.Reset();
	}
	else if (CanMove('r', tile))
	{
		while (CanMove('r', tile) && tile.pos % 4 != 3){
			this->Swap('r', tile);
			tile = this->mContent.at(tile.pos + 1);
		}

	}
}
