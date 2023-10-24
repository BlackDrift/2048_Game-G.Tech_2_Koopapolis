#include "Tile.h"

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
