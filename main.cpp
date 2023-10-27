#include <iostream>
#include "main.h"
#include "Tile.h"
#include "Map.h"
#include "time.h"
#include "Game.h"
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
		int c = _getch();
		if (!game::GameEvent(c, current))
		{
			current.SpawnTile();
			current.RefreshScreen();
		}
		//if (current.CheckIsDone())
			//gameLoop = 0;
	}
	

	
	return 0;
}

/*


*/
