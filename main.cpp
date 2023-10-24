#include <iostream>
#include "main.h"
#include "Tile.h"
#include "Tile.cpp"

int main() {
	Tile tile1, tile2, tile3;
	std::cout << tile1.value << std::endl;
	tile1.evolve();
	std::cout << tile1.value << std::endl;
	std::cout << tile2.value << std::endl;
	std::cout << tile3.value << std::endl;
}

/*


*/
