#ifndef GAME_H
# define GAME_H

# include <stdio.h>
# include <stdbool.h>
# include <stdlib.h>
# include "macros.h"
# include "structures.h"
#  include "../mlx_macos/mlx.h"

# ifdef __linux__
#  include "../mlx/mlx.h"
#  include <X11/Xlib.h>
#endif

# ifdef __APPLE__
#  include "../mlx_macos/mlx.h"
#  include <CoreGraphics/CoreGraphics.h>
#endif

int			render(void);
void		render_grid(void);
void		render_selection(void);
void		render_help(void);
void		load_textures(void);
int			close_window(void);
void		free_grid(void);

int			mouse_hook(int button, int x, int y, void *param);

// DISPLAY
t_pos		get_display_size(void);

// MULTIPLAYER
int			multiplayer_key_hook(int key);

// GAME LOGIC
int			is_valid_move(int x, int y);
void		make_move(int x, int y, int player);
int			check_win(void);
int			check_draw(void);
void		switch_player(void);
void		reset_game(void);
void		start_restart_timer(void);
void		update_restart_timer(void);
void		update_selection_display(void);
t_pos		find_next_available_position(t_pos current, int direction);
void		reset_cursor_after_move(int player);

t_player	*player2(void);
t_player	*player1(void);
t_image		*image(void);
t_game		*game(void);

#endif