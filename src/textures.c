#include "game.h"

t_texture	load_file_to_texture(char *path)
{
	t_texture	texture;

	texture.img = mlx_xpm_file_to_image(game()->mlx, path, &texture.width, &texture.height);
	texture.addr = mlx_get_data_addr(texture.img, &texture.bpp, &texture.line_len, &texture.endian);
	return (texture);
}

void	load_textures(void)
{
	image()->circle = load_file_to_texture("assets/XPM/CIRCLE.xpm");
	image()->circle_vertical = load_file_to_texture("assets/XPM/CIRCLE_VERTICAL.xpm");
	image()->circle_horizontal = load_file_to_texture("assets/XPM/CIRCLE_HORIZONTAL.xpm");
	image()->circle_diagonal_left = load_file_to_texture("assets/XPM/CIRCLE_DIAGONAL_LEFT.xpm");
	image()->circle_diagonal_right = load_file_to_texture("assets/XPM/CROSS_DIAGONAL_RIGHT.xpm");
	image()->cross = load_file_to_texture("assets/XPM/CROSS.xpm");
	image()->cross_vertical = load_file_to_texture("assets/XPM/CROSS_VERTICAL.xpm");
	image()->cross_horizontal = load_file_to_texture("assets/XPM/CROSS_HORIZONTAL.xpm");
	image()->cross_diagonal_left = load_file_to_texture("assets/XPM/CROSS_DIAGONAL_LEFT.xpm");
	image()->cross_diagonal_right = load_file_to_texture("assets/XPM/CROSS_DIAGONAL_RIGHT.xpm");
	image()->empty = load_file_to_texture("assets/XPM/EMPTY.xpm");
	image()->selected = load_file_to_texture("assets/XPM/SELECTED.xpm");
	//delete
	image()->background = load_file_to_texture("assets/BACKGROUND.xpm");
}