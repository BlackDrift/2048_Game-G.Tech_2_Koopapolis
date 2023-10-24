#include <iostream>
#include <string>

int main() {
	int tileValue;
	int i;
	int j;
	while (1)
	{
		int randomValue = rand() % 4 + 2;
		if (randomValue % 2 == 0) {
			tileValue = randomValue;
			break;
		}
	}
	std::cout << tileValue << std::endl;
	
	std::string Map = "abcdefghijklmnop";
	for (i = 0; i < 4; i++) {
		for (j = 0; j < 4; j++) {
			std::cout << Map[4*i+j];
		}
		std::cout << std::endl;
	}

	return 0;
}