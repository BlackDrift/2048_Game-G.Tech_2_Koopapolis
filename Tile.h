#ifndef TILE_H
# define TILE_H

#include "main.h"

class Tile
{
public:
	//Attributes
	int	value;

	//Constructor
	Tile();

	//Method
	int getNumber()
	{
		int value = (rand() % 2 + 1) * 2 ;
		return value;
	}

	void evolve()
	{
		this->value = value * 2;
	}
	

	//Destructor
	~Tile()
	{

	}
};

#endif
