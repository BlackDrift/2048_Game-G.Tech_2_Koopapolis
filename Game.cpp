 #include "Map.h"
#include "Game.h"

#define KEY_UP 72
#define KEY_DOWN 80
#define KEY_LEFT 75
#define KEY_RIGHT 77

bool	game::GameEvent(int	key, Map map)
{
	std::cout << "GameEvent" << std::endl;
	switch (key)
		{
			case KEY_UP:
				map.MoveTiles('u');
				return (0);
				break;
			case KEY_DOWN:
				map.MoveTiles('d');
				return (0);
				break;
			case KEY_LEFT:
				map.MoveTiles('l');
				return (0);
				break;
			case KEY_RIGHT:
				map.MoveTiles('r');
				return (0);
				break;
			default:
				return (1);
				break;
		}
}