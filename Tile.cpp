#include "Tile.h"
#include <cstdlib>

Tile::Tile()
{
	this->value = GetNumber();
}

int Tile::GetNumber()
{
	int value = (rand() % 2 + 1) * 2;
	return value;
}

void Tile::Evolve()
{
	this->value = this->value * 2;
}

void Tile::Reset()
{
	this->value = 0;
}