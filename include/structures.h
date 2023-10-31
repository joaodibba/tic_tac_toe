#ifndef STRUCTURES_H
# define STRUCTURES_H

typedef struct s_texture
{
	void	*img;
	char	*addr;
	int		bpp;
	int		line_len;
	int		endian;
	int		width;
	int		height;
}			t_texture;

typedef	struct s_image
{
	t_texture	final_image;
	t_texture	circle;
	t_texture	circle_vertical;
	t_texture	circle_horizontal;
	t_texture	circle_diagonal_left;
	t_texture	circle_diagonal_right;
	t_texture	cross;
	t_texture	cross_vertical;
	t_texture	cross_horizontal;
	t_texture	cross_diagonal_left;
	t_texture	cross_diagonal_right;
	t_texture	empty;
	t_texture	selected;
	t_texture	background;
}				t_image;

typedef struct s_pos
{
	int		x;
	int		y;
}			t_pos;


typedef struct s_player
{
	t_pos	select;
}			t_player;

typedef struct s_game
{
	void		*mlx;
	void		*window;
	t_pos		window_size;
	t_pos		screen_size;
	char		**grid;
	t_player	player1;
	t_player	player2;
	t_image		image;
}	t_game;

#endif