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
	Map current;

	current.SpawnTile();
	current.SpawnTile();
	current.PrintMap();
	std::cout << std::endl;

	while (gameLoop)
	{	
		int c = _getch();
		game::GameEvent(c, current);
		//if (current.CheckIsDone())
			//gameLoop = 0;
	}
	return 0;
}

/*


*/
