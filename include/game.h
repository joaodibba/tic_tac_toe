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
void		load_textures(void);
int			close_window(void);

int			mouse_hook(int key);

// DISPLAY
t_pos		get_display_size(void);

// MULTIPLAYER
int			multiplayer_key_hook(int key);


t_player	*player2(void);
t_player	*player1(void);
t_image		*image(void);
t_game		*game(void);

#endif