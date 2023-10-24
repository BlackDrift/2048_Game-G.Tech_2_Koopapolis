#pragma once

#include <vector>

class Map
{
public:

	//Attributes
	int	size;
	int squareSize;
	std::vector<char> mContent;

	//Constructor
	Map();

	//Method
	void SetSize();
	//void FillMap();
	void PrintMap();

	//Destructor
};
