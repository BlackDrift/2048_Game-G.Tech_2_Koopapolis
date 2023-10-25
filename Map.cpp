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

void	Map::PrintMap()
{
	for (int i = 0; i < this->squareSize; ++i)
	{
		std::cout << this->mContent.at(i).value;
		if ((i + 1) % this->size == 0)
			std::cout << std::endl;
	}
}

void	Map::SpawnTile()
{
	
	int pos = rand() % this->squareSize;
	while (this->mContent.at(pos).value != 0)
		pos = rand() % this->squareSize;
	this->mContent.at((pos)).value = this->mContent.at((pos)).getNumber();
}

void	Map::RefreshScreen()
{
	system("cls");
	this->PrintMap();

}

/*bool Map::CanMove(Tile tile)
{
	int position = tile.pos;
	switch(position)
	{
		case ((position + 1 >= 0 && position + 1 < 16 ) && ((this->mContent.at(position + 1) == 0)) || (this->mContent.at(position + 1) == this->mContent.at(position))):
			return true;
		case ((position - 1 >= 0 && position - 1 < 16) && ((this->mContent.at(position - 1) == 0)) || (this->mContent.at(position - 1) == this->mContent.at(position))):
			return true;
		case ((position + 4 >= 0 && position + 4 < 16) && ((this->mContent.at(position + 4) == 0)) || (this->mContent.at(position + 4) == this->mContent.at(position))):
			return true;
		case ((position - 4 >= 0 && position - 4 < 16) && ((this->mContent.at(position - 4) == 0)) || (this->mContent.at(position - 4) == this->mContent.at(position))):
			return true;
		default:
			return false;
	}
}

bool	Map::CheckIsDone()
{
	for (int i = 0; i < this->squareSize; ++i)
	{
		if (this->mContent.at(i) == 0 && )
	}
}
*/

void	Map::ChangeMap(int direction)
{
	switch (...)
	{
		case (direction == 1):
			for (int i = 0; i < this->squareSize; i++)
			{
				for (int j = 0; j < this->squareSize; j++)
				{
					if (this->mContent.at((4 * i + j)).value != 0) {
						if (this->mContent.at((4 * i + j - 1)).value == 0) {
							this->mContent.at((4 * i + j - 1)).value = this->mContent.at((4 * i + j)).value;
							this->mContent.at((4 * i + j)).value = 0;
						}
					}
				}
			}
		case (direction == 2):
			break;
		case (direction == 3):
			break;
		case (direction == 4):
			break;
		default:
			break;
	}
}

