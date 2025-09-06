#include "game.h"

/**
 * * free_grid
 * @brief	Frees the memory allocated for the game grid
 * @details	Iterates through each row of the 3x3 grid and frees the memory,
 * 		then frees the grid array itself. Handles NULL pointer checks.
 */
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

/**
 * * close_window
 * @brief	Closes the game window and cleans up resources
 * @return	Never returns (calls exit(0))
 * @details	Destroys the MLX window, frees the game grid memory,
 * 		and exits the program with status 0.
 */
int	close_window(void)
{
	mlx_destroy_window(game()->mlx, game()->window);
	free_grid();
	exit (0);
}