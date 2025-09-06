#include "game.h"

t_pos	find_center(int	x, int y)
{
	return((t_pos){x / 2, y / 2});
}

t_pos	find_leftmost(t_pos pos, int square_size)
{
	return((t_pos){pos.x - (square_size / 2), pos.y - (square_size / 2)});
}

void	put_square(t_texture texture, int x_offset, int y_offset)
{
	t_pos center = find_center(WINDOW_SIZE, WINDOW_SIZE);
	center.x += x_offset * TEXTURE_SIZE;
	center.y += y_offset * TEXTURE_SIZE;
	t_pos leftmost = find_leftmost(center, TEXTURE_SIZE);
	mlx_put_image_to_window(game()->mlx, game()->window, texture.img, leftmost.x, leftmost.y);
}

void	put_texture(t_pos pos, char c)
{
	// Transform grid coordinates (0,1,2) to screen offsets (-1,0,1)
	int x_offset = pos.x - 1;
	int y_offset = pos.y - 1;
	
	if (c == EMPTY)
		put_square(image()->empty, x_offset, y_offset);
	else if(c == SELECTED)
		put_square(image()->selected, x_offset, y_offset);
	else if(c == CIRCLE)
		put_square(image()->circle, x_offset, y_offset);
	else if(c == CIRCLE_DIAGONAL_LEFT)
		put_square(image()->circle_diagonal_left, x_offset, y_offset);
	else if(c == CIRCLE_DIAGONAL_RIGHT)
		put_square(image()->circle_diagonal_right, x_offset, y_offset);
	else if(c == CIRCLE_VERTICAL)
		put_square(image()->circle_vertical, x_offset, y_offset);
	else if(c == CIRCLE_HORIZONTAL)
		put_square(image()->circle_horizontal, x_offset, y_offset);
	else if(c == CROSS)
		put_square(image()->cross, x_offset, y_offset);
	else if(c == CROSS_DIAGONAL_LEFT)
		put_square(image()->cross_diagonal_left, x_offset, y_offset);
	else if(c == CROSS_DIAGONAL_RIGHT)
		put_square(image()->cross_diagonal_right, x_offset, y_offset);
	else if(c == CROSS_VERTICAL)
		put_square(image()->cross_vertical, x_offset, y_offset);
	else if(c == CROSS_HORIZONTAL)
		put_square(image()->cross_horizontal, x_offset, y_offset);
}

void	render_selection(void)
{
	t_pos	selection;
	
	// Show selection for current player
	if (game()->current_player == PLAYER_1)
		selection = player1()->select;
	else
		selection = player2()->select;
	
	// Only show selection if the position is empty
	if (game()->grid[selection.y][selection.x] == EMPTY)
			put_texture(selection, SELECTED);
}

void	render_grid(void)
{
	t_pos	pos;
	char	current_square;

	pos.y = 0;
	pos.x = 0;
	while (pos.y < 3)
	{
		pos.x = 0;
		while (pos.x < 3)
		{
			current_square = game()->grid[pos.y][pos.x];
			put_texture((t_pos){pos.x, pos.y}, current_square);
			pos.x++;
		}
		pos.y++;
	}
	
	// Render selection after grid
	render_selection();
}

void	render_help(void)
{
	int	text_color = 0xFFFFFF; // White color
	int	y_pos = 20;
	int	x_pos = 20;
	
	// Player 1 controls
	mlx_string_put(game()->mlx, game()->window, x_pos, y_pos, text_color, "PLAYER 1 (O):");
	y_pos += 20;
	mlx_string_put(game()->mlx, game()->window, x_pos, y_pos, text_color, "  WASD - Move cursor");
	y_pos += 20;
	mlx_string_put(game()->mlx, game()->window, x_pos, y_pos, text_color, "  SPACE - Place piece");
	y_pos += 30;
	
	// Player 2 controls
	mlx_string_put(game()->mlx, game()->window, x_pos, y_pos, text_color, "PLAYER 2 (X):");
	y_pos += 20;
	mlx_string_put(game()->mlx, game()->window, x_pos, y_pos, text_color, "  Arrow Keys - Move cursor");
	y_pos += 20;
	mlx_string_put(game()->mlx, game()->window, x_pos, y_pos, text_color, "  ENTER - Place piece");
	y_pos += 30;
	
	// General controls
	mlx_string_put(game()->mlx, game()->window, x_pos, y_pos, text_color, "GENERAL:");
	y_pos += 20;
	mlx_string_put(game()->mlx, game()->window, x_pos, y_pos, text_color, "  Mouse Click - Place piece");
	y_pos += 20;
	mlx_string_put(game()->mlx, game()->window, x_pos, y_pos, text_color, "  H - Toggle this help");
	y_pos += 20;
	mlx_string_put(game()->mlx, game()->window, x_pos, y_pos, text_color, "  ESC - Quit game");
	y_pos += 30;
	
	// Game info
	mlx_string_put(game()->mlx, game()->window, x_pos, y_pos, text_color, "GAME INFO:");
	y_pos += 20;
	mlx_string_put(game()->mlx, game()->window, x_pos, y_pos, text_color, "  Green highlight = Valid move");
	y_pos += 20;
	mlx_string_put(game()->mlx, game()->window, x_pos, y_pos, text_color, "  Red highlight = Invalid move");
	y_pos += 20;
}

int	render(void)
{
	if (!game()->window)
		return (1);
	if (image()->background.img)
		mlx_put_image_to_window(game()->mlx, game()->window, image()->background.img, 0, 0);
	render_grid();
	if (game()->show_help)
		render_help();
	return (0);
}