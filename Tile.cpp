#include "Tile.h"
#include <cstdlib>

Tile::Tile()
{
	this->value = getNumber();
}

int Tile::getNumber()
{
	srand(time(0));
	int value = (rand() % 2 + 1) * 2;
	return value;
}

void Tile::evolve()
{
	this->value = this->value * 2;
}
