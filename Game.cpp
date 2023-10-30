 #include "Map.h"
#include "Game.h"

// Arrow keys + escape

#define KEY_UP 72
#define KEY_DOWN 80
#define KEY_LEFT 75
#define KEY_RIGHT 77
#define KEY_ESC 27

int	game::GameEvent(int	key, Map *map)
{
	switch (key)
		{
			case KEY_UP:
				map->MoveTiles('u');
				return 0;
				break;
			case KEY_DOWN:
				map->MoveTiles('d');
				return 0;
				break;
			case KEY_LEFT:
				map->MoveTiles('l');
				return 0;
				break;
			case KEY_RIGHT:
				map->MoveTiles('r');
				return 0;
				break;
			case KEY_ESC:
				return 1;
			default:
				return 0;
				break;
		}
	return (0);
}