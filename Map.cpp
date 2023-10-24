#include "Map.h"
#include <iostream>

Map::Map()
{
	this->SetSize();
	for (int i = 0; i < this->size; ++i)
	{
		for (int j = 0; j < this->size; ++j)
			this->mContent.push_back(('0'));
		this->mContent.push_back(('\n'));
	}
}

void	Map::SetSize()
{
	this->size = 4;
	this->squareSize = (this->size * this->size) + this->size;
}

void	Map::PrintMap()
{
	for (int i = 0; i < this->squareSize; ++i)
		std::cout << this->mContent.at(i);


}/*
 void	FillMap()
{

}
*/

