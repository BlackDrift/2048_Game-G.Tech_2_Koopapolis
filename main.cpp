#include <iostream>
#include "main.h"
#include "Tile.h"
#include "Map.h"
#include "time.h"
#include <conio.h>
//#include "Move.h"

#define KEY_UP 72
#define KEY_DOWN 80
#define KEY_LEFT 75
#define KEY_RIGHT 77

int main() 
{
	srand(time(0));
	bool gameLoop = true;
	Tile* tile1 = new Tile();
	Tile* tile2 = new Tile();
	Tile* tile3 = new Tile();
	std::cout << tile1->value << std::endl;
	tile1->Evolve();
	std::cout << tile1->value << std::endl;
	std::cout << tile2->value << std::endl;
	std::cout << tile3->value << std::endl;
	Map current;
	current.PrintMap();
	current.SpawnTile();
	current.RefreshScreen();
	std::cout << std::endl;
	//std::cout << current.CheckIsDone() << std::endl;
	
	
	while (gameLoop)
	{
		gameLoop = false;
		int c = 0;
		switch ((c = _getch()))
		{
			case KEY_UP:
				current.MoveTiles('u');
				break;
			case KEY_DOWN:
				current.MoveTiles('d');
				break;
			case KEY_LEFT:
				current.MoveTiles('l');
				break;
			case KEY_RIGHT:
				current.MoveTiles('r');
				break;
			default:
				gameLoop = true;
				break;
		}
		current.SpawnTile();
		current.RefreshScreen();
	}
	
	return 0;
}

/*


*/
