#include "game.h"

void	free_grid(void)
{
	if (game()->grid)
	{
		for (int i = 0; i < 3; i++)
		{
			if (game()->grid[i])
				free(game()->grid[i]);
		}
		free(game()->grid);
	}
}

int	close_window(void)
{
	mlx_destroy_window(game()->mlx, game()->window);
	free_grid();
	exit (0);
}