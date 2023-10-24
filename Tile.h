#pragma once
#include "Map.h"
#include <iostream>

class Tile:Map
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

class Position:Tile
{
public:
	//Attributes
	int posx;
	int posy;

	//Constructor
	Position(int x, int y);

	//Method

	//Destructor
};