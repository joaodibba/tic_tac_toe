#include "game.h"

// for multiplayer mode
int	multiplayer_key_hook(int key)
{
	if (key == ESCAPE)
	{

		// TODO: open menu
		// THIS HAS TO CHANGE (TEMPORARY)
		close_window();
		return (key);
	}
	// player 1
	else if (key == W_k)
		return (player1()->select.y -= 1);
	else if (key == S_k)
		return (player1()->select.y += 1);
	else if (key == A_k)
		return (player1()->select.x -= 1);
	else if (key == D_k)
		return (player1()->select.x += 1);
	else if (key == SPACE)
	{
		// TODO: player 1 confirm selection
		return (key);
	}
	// player 2
	else if (key == UP)
		return (player2()->select.y -= 1);
	else if (key == LEFT)
		return (player2()->select.x -= 1);
	else if (key == DOWN)
		return (player2()->select.y += 1);
	else if (key == RIGHT)
		return (player2()->select.x += 1);
	else if (key == ENTER)
	{
		// TODO: player 2 confirm selection
		return (key);
	}
	return (key);
}

int mouse_hook(int key)
{
	if (key == LEFT_CLICK)
		return (key);
		// confirm
	else if (key == SCROLL_UP)
		// select
		return (key);
	else if (key == SCROLL_DOWN)
		// select
		return (key);
	return (key);
}