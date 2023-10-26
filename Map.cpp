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
		std::cout << ' ';
	std::cout << nb;

}

void	Map::PrintMap()
{
	for (int n = 0; n < (this->size * 5 + this->size + 1); n++)
		std::cout << '-';
	std::cout << std::endl;
	for (int i = 0; i < this->size; ++i)
	{
		for (int j = 0; j < this->size; j++)
		{
			if (j == 0 || j == this->size)
				std::cout << '|' ;
			int tab[2] = { j, i };
			PrintNb(this->TileAt(tab).value);
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

/*bool Map::IsValid(int x, int y)
{
}

int*	Map::GetCoords(int position)
{
	int x = position / 4;
	int y = position % 4;
	int* tab[2] { x, y } ;
	return tab;
}*/

Tile	Map::TileAt(int *tab)
{
	int x = tab[1];
	int y = tab[0];
	
	return (this->mContent.at(4 * x + y));
}


bool	Map::CheckIsDone()
{
	bool res;

	res = true;
	for (int i = 0; i < this->squareSize; ++i)
		if (this->mContent.at(i).value != 0 && this->CanMove('0',this->mContent.at(i)) == true)
			res = false;
	return res;
}


void Map::MoveTiles(char direction)
{
	switch (direction)
	{
	case ('u'):
		for (int i = 0; i < this->squareSize; ++i)
			this->MoveUp(this->mContent.at(i));
		break;

	case ('d'):
		for (int i = this->squareSize - 1; i >= 0; --i)
			this->MoveDown(this->mContent.at(i));
		break;

	case ('l'):
		for (int i = 0; i < this->size; ++i)
		{
			for (int j = 0; j < this->size; j++)
				this->MoveLeft(this->mContent.at(i + (this->size * j)));
		}
		break;
	case ('r'):
		for (int i = this->size - 1; i >= 0; --i)
		{
			for (int j = 0; j < this->size; j++)
				this->MoveDown(this->mContent.at(i + (this->size * j)));
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
	int* tab[2];

	switch (direction)
	{
	case('u'):
		if (tile.x > 1 && tile.value == this->TileAt(tab[tileX-1, tileY]).value)
			return true;
		break;
	case ('d'):
		if (tile.x < 4 && tile.value == this->TileAt(tab[tileX+1, tileY]).value)
			return true;
		break;
	case('l'):
		if (tile.y > 1 && tile.value == this->TileAt(tab[tileX, tileY-1]).value)
			return true;
		break;
	case('r'):
		if (tile.y < 4 && tile.value == this->TileAt(tab[tileX, tileY+1]).value)
			return true;
		break;
	}
	return false;
}

bool Map::CanMove(char direction, Tile tile)
{
	int	tileX = tile.x;
	int tileY = tile.y;
	int position = tile.pos;
	int* tab[2];

	switch (direction)
	{
		
	case('u'):
		if (tile.x > 1 && TileAt(tab[tileX - 1, tileY]).value == 0)
			return true;
		break;
	case ('d'):
		if (tile.x < 4 && TileAt(tab[tileX + 1, tileY]).value == 0)
			return true;
		break;
	case('l'):
		if (tile.y > 1 && TileAt(tab[tileX, tileY - 1]).value == 0)
			return true;
		break;
	case('r'):
		if (tile.y < 4 && TileAt(tab[tileX, tileY + 1]).value == 0)
			return true;
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
	return false;
}

void Map::Swap(char direction, Tile tile)
{
	switch (direction)
	{
	case('u'):
		this->mContent.at(tile.pos - 4).value = tile.value;
		tile.value = 0;
		break;
	case('d'):
		this->mContent.at(tile.pos + 4).value = tile.value;
		tile.value = 0;
		break;
	case('l'):
		this->mContent.at(tile.pos - 1).value = tile.value;
		tile.value = 0;
		break;
	case('r'):
		this->mContent.at(tile.pos + 1).value = tile.value;
		tile.value = 0;
		break;
	}
}

void Map::MoveUp(Tile tile)
{
	if (CanEvolve('u', tile))
	{
		this->mContent.at(tile.pos - 4).Evolve();
		tile.Reset();
	}
	else if (CanMove('u', tile))
	{
		while (CanMove('u', tile)){
			this->Swap('l', tile);
			tile = this->mContent.at(tile.pos - 4);
		}

	}
}

void Map::MoveDown(Tile tile)
{
	if (CanEvolve('d', tile))
	{
		this->mContent.at(tile.pos + 4).Evolve();
		tile.Reset();
	}
	else if (CanMove('d', tile))
	{
		while (CanMove('d', tile)){
			this->Swap('d', tile);
			tile = this->mContent.at(tile.pos + 4);
		}

	}
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
		while (CanMove('l', tile)){
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
		while (CanMove('r', tile)){
			this->Swap('r', tile);
			tile = this->mContent.at(tile.pos + 1);
		}

	}
}
