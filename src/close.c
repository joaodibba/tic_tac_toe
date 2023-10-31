#include "game.h"

int	close_window(void)
{
	mlx_destroy_window(game()->mlx, game()->window);
	// TODO: free stuff
	exit (0);
}