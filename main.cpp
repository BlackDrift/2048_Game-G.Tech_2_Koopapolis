#include <iostream>
#include "main.h"
#include "Tile.h"
#include "Map.h"
#include "time.h"
#include <conio.h>

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
	tile1->evolve();
	std::cout << tile1->value << std::endl;
	std::cout << tile2->value << std::endl;
	std::cout << tile3->value << std::endl;
	Map current;
	current.PrintMap();
	current.SpawnTile();
	current.RefreshScreen();
	
	while (gameLoop)
	{
		gameLoop = false;
		int c = 0;
		switch ((c = _getch()))
		{
			case KEY_UP:
				current.ChangeMap(1);
				break;
			case KEY_DOWN:
				current.ChangeMap(2);
				break;
			case KEY_RIGHT:
				current.ChangeMap(3);
				break;
			case KEY_LEFT:
				current.ChangeMap(4);
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
