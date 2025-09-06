#include "game.h"

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
	exit (0);
}