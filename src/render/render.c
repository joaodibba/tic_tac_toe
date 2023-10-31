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
	mlx_put_image_to_window(game()->mlx, game()->window, image()->empty.img, leftmost.x, leftmost.y);
}

void	put_texture(t_pos pos, char c)
{
	if (c == EMPTY)
		put_square(image()->empty, pos.x, pos.y);
	else if(c == SELECTED)
		put_square(image()->selected, pos.x, pos.y);
	else if(c == CIRCLE)
		put_square(image()->circle, pos.x, pos.y);
	else if(c == CIRCLE_DIAGONAL_LEFT)
		put_square(image()->circle_diagonal_left, pos.x, pos.y);
	else if(c == CIRCLE_DIAGONAL_RIGHT)
		put_square(image()->circle_diagonal_right, pos.x, pos.y);
	else if(c == CIRCLE_VERTICAL)
		put_square(image()->circle_vertical, pos.x, pos.y);
	else if(c == CIRCLE_HORIZONTAL)
		put_square(image()->circle_horizontal, pos.x, pos.y);
	else if(c == CROSS)
		put_square(image()->selected, pos.x, pos.y);
	else if(c == CROSS_DIAGONAL_LEFT)
		put_square(image()->cross_diagonal_left, pos.x, pos.y);
	else if(c == CROSS_DIAGONAL_RIGHT)
		put_square(image()->cross_diagonal_left, pos.x, pos.y);
	else if(c == CROSS_VERTICAL)
		put_square(image()->cross_vertical, pos.x, pos.y);
	else if(c == CROSS_HORIZONTAL)
		put_square(image()->cross_horizontal, pos.x, pos.y);
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
			put_texture((t_pos){pos.x - 1, pos.y - 1}, current_square);
			pos.x++;
		}
		pos.y++;
	}
}

int	render(void)
{
	if (!game()->window)
		return (1);
	//put background
	mlx_put_image_to_window(game()->mlx, game()->window, image()->background.img, 0, 0);
	render_grid();
	return (0);
}