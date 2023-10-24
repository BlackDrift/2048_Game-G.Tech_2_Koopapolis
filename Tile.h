#pragma once

#include <iostream>

class Tile
{
public:
	//Attributes
	int	value;

	//Constructor
	Tile();

	//Method
	int getNumber();
	void evolve();


	//Destructor
	~Tile()
	{

	}
};

