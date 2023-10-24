#include <iostream>
#include "main.h"
#include "Tile.h"
#include "Map.h"

int main() 
{
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
	return 0;
}

/*


*/
