#include "game.h"

/**
 * * load_file_to_texture
 * @brief	Loads an XPM image file into a texture structure
 * @param path	The file path to the XPM image file
 * @return	A t_texture structure containing the loaded image data
 * @details	Uses MLX to load XPM files and get image data address.
 * 		Returns empty texture if loading fails.
 */
t_texture	load_file_to_texture(char *path)
{
	t_texture	texture;

	texture.img = mlx_xpm_file_to_image(game()->mlx, path, &texture.width, &texture.height);
	if (!texture.img)
	{
		return (texture);
	}
	texture.addr = mlx_get_data_addr(texture.img, &texture.bpp, &texture.line_len, &texture.endian);
	return (texture);
}

/**
 * * load_textures
 * @brief	Loads all game textures from XPM files
 * @details	Loads textures for circles, crosses, empty squares, selections,
 * 		and background. Includes special variants for winning lines
 * 		(horizontal, vertical, diagonal).
 */
void	load_textures(void)
{
	image()->circle = load_file_to_texture("assets/XPM/CIRCLE.xpm");
	image()->circle_vertical = load_file_to_texture("assets/XPM/CIRCLE_VERTICAL.xpm");
	image()->circle_horizontal = load_file_to_texture("assets/XPM/CIRCLE_HORIZONTAL.xpm");
	image()->circle_diagonal_left = load_file_to_texture("assets/XPM/CIRCLE_DIAGONAL_LEFT.xpm");
	image()->circle_diagonal_right = load_file_to_texture("assets/XPM/CIRCLE_DIAGONAL_RIGHT.xpm");
	image()->cross = load_file_to_texture("assets/XPM/CROSS.xpm");
	image()->cross_vertical = load_file_to_texture("assets/XPM/CROSS_VERTICAL.xpm");
	image()->cross_horizontal = load_file_to_texture("assets/XPM/CROSS_HORIZONTAL.xpm");
	image()->cross_diagonal_left = load_file_to_texture("assets/XPM/CROSS_DIAGONAL_LEFT.xpm");
	image()->cross_diagonal_right = load_file_to_texture("assets/XPM/CROSS_DIAGONAL_RIGHT.xpm");
	image()->empty = load_file_to_texture("assets/XPM/EMPTY.xpm");
	image()->selected = load_file_to_texture("assets/XPM/SELECT.xpm");
	//delete
	image()->background = load_file_to_texture("assets/XPM/BACKGROUND.xpm");
}