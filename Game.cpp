 #include "Map.h"
#include "Game.h"

#define KEY_UP 72
#define KEY_DOWN 80
#define KEY_LEFT 75
#define KEY_RIGHT 77

void	game::GameEvent(int	key, Map map)
{
	switch (key)
		{
			case KEY_UP:
				map.MoveTiles('u');
				break;
			case KEY_DOWN:
				map.MoveTiles('d');
				break;
			case KEY_LEFT:
				map.MoveTiles('l');
				break;
			case KEY_RIGHT:
				map.MoveTiles('r');
				break;
			default:
				break;
		}
}