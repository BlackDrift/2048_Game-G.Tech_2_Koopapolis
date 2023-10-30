#include <iostream>
#include <conio.h>
#include <time.h>
#include <Windows.h>

#include "main.h"
#include "Tile.h"
#include "Map.h"
#include "Game.h"

int main() 
{
	srand(time(0));
	bool gameLoop = true;
	Map current;

	current.SpawnTile();
	current.SpawnTile();
	current.PrintMap();

	while (gameLoop)
	{	
		int c = _getch();
		if (game::GameEvent(c, &current) == 1)
			gameLoop = false;
		if (current.CheckIsDone())
		{
			std::cout << std::endl << std::endl << "Game Over" << std::endl;
			gameLoop = false;
		}
		Sleep(100);
	}
	return 0;
}

