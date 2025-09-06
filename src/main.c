#include "game.h"
#include <time.h>

/**
 * * init_grid
 * @brief	Sets all positions in the static 3x3 grid to EMPTY
 * @details	Initializes the static 3x3 grid in game()->grid by setting every cell to EMPTY.
 */

void init_grid(void)
{
	for (int i = 0; i < 3; i++)
		for (int j = 0; j < 3; j++)
			game()->grid[i][j] = EMPTY;
}

/**
 * * init_vars
 * @brief	Initializes all game variables and resources
 * @details	Sets up the game grid, window size, MLX instance, window,
 * 		final image, game state, player selections, and loads all textures.
 * 		This function must be called before starting the game loop.
 */
void	init_vars(void)
{
	init_grid();
	game()->window_size.x = WINDOW_SIZE;
	game()->window_size.y = WINDOW_SIZE;
	game()->mlx = mlx_init();
	game()->window = mlx_new_window(game()->mlx, game()->window_size.x, game()->window_size.y, "TIC TAC TOE");
	image()->final_image.img = mlx_new_image(game()->mlx, game()->window_size.y, game()->window_size.x);
	// Randomize starting player
	srand(time(NULL));
	game()->current_player = (rand() % 2) ? PLAYER_1 : PLAYER_2;
	game()->game_state = GAME_PLAYING;
	game()->moves_count = 0;
	game()->restart_timer = 0;
	game()->show_help = false;
	
	// Randomize initial cursor positions
	player1()->select.x = rand() % 3;
	player1()->select.y = rand() % 3;
	player2()->select.x = rand() % 3;
	player2()->select.y = rand() % 3;
	load_textures();
}

/**
 * * main
 * @brief	Main entry point for the tic-tac-toe game
 * @return	0 on successful completion
 * @details	Initializes the game, sets up event hooks for keyboard and mouse,
 * 		and starts the MLX game loop. The game runs until the window is closed.
 */
int	main(void)
{
	init_vars();
	mlx_mouse_hook(game()->window, &mouse_hook, NULL);
	mlx_hook(game()->window, KeyPress, KeyPressMask, &multiplayer_key_hook, NULL);
	mlx_hook(game()->window, DestroyNotify, KeyPressMask, &close_window, NULL);
	mlx_loop_hook(game()->mlx, &render, NULL);
	mlx_loop(game()->mlx);
	return (0);
}