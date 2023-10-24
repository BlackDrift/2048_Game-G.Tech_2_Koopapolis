#include "Tile.h"

Position::Position(int x, int y)
{
	this->posx = x;
	this->posy = y;
}

Tile::Tile()
{
	this->value = getNumber();
}

int Tile::getNumber()
{
	int value = (rand() % 2 + 1) * 2;
	return value;
}

void Tile::evolve()
{
	this->value = this->value * 2;
}
