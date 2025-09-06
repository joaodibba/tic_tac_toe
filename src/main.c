#include "game.h"

char	**init_grid(void) 
{
    char **grid = (char **)malloc(3 * sizeof(char *));
    if (!grid)
    {
        return (NULL);
    }
    int i = 0, j = 0;
    while (i < 3) 
	{
        grid[i] = (char *)malloc(3 * sizeof(char));
        if (!grid[i])
        {
            return (NULL);
        }
        j = 0;
        while (j < 3) 
		{
            grid[i][j] = '0';
            j++;
        }
        i++;
    }
    return (grid);
}

void	init_vars(void)
{
	game()->grid = init_grid();
	game()->window_size.x = WINDOW_SIZE;
	game()->window_size.y = WINDOW_SIZE;
	game()->mlx = mlx_init();
	game()->window = mlx_new_window(game()->mlx, game()->window_size.x, game()->window_size.y, "TIC TAC TOE");
	image()->final_image.img = mlx_new_image(game()->mlx, game()->window_size.y, game()->window_size.x);
	// game()->screen_size = get_display_size();
	game()->current_player = PLAYER_1;
	game()->game_state = GAME_PLAYING;
	game()->moves_count = 0;
	game()->restart_timer = 0;
	game()->show_help = false;
	player1()->select.x = 1;
	player1()->select.y = 1;
	player2()->select.x = 1;
	player2()->select.y = 1;
	load_textures();
}

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