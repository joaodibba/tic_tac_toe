#include "game.h"

char	**init_grid(void) 
{
    char **grid = (char **)malloc(3 * sizeof(char *));
    int i, j = 0;
    while (i < 3) 
	{
        grid[i] = (char *)malloc(3 * sizeof(char));
        j = 0;
        while (j < 3) 
		{
            grid[i][j++] = '0';
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