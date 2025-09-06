#ifndef MACROS_H
# define MACROS_H

# define EMPTY '0'
# define SELECTED '1'

# define CIRCLE 'O'
# define CIRCLE_DIAGONAL_LEFT 'A'
# define CIRCLE_DIAGONAL_RIGHT 'B'
# define CIRCLE_VERTICAL 'C'
# define CIRCLE_HORIZONTAL 'D'

# define CROSS 'X'
# define CROSS_DIAGONAL_LEFT 'J'
# define CROSS_DIAGONAL_RIGHT 'K'
# define CROSS_VERTICAL 'L'
# define CROSS_HORIZONTAL 'M'

# define WINDOW_SIZE 750
# define TEXTURE_SIZE 128

// Game states
# define GAME_PLAYING 0
# define GAME_WON 1
# define GAME_DRAW 2
# define GAME_MENU 3

// Players
# define PLAYER_1 1
# define PLAYER_2 2

# ifdef __APPLE__
#  define KeyPress 2
#  define KeyPressMask 1L<<0
#  define KeyRelease 3
#  define KeyReleaseMask 1L<<1
#  define NoEventMask 0
#  define DestroyNotify 17
# endif

// KEYCODES FOR MACOS
# ifdef __APPLE__
#  define ESCAPE 53
#  define SPACE 49
#  define ENTER 36
#  define W_k 13
#  define S_k 1
#  define A_k 0
#  define D_k 2
#  define H_k 4
#  define LEFT 123
#  define RIGHT 124
#  define UP 126
#  define DOWN 125
#  define LEFT_CLICK 1
#  define RIGHT_CLICK 2
#  define MIDDLE_CLICK 3
#  define SCROLL_UP 4
#  define SCROLL_DOWN 5
# endif

// KEYCODES FOR LINUX
# ifdef __linux__
#  define ESCAPE 65307
#  define W 119
#  define S 115
#  define A 97
#  define D 100
#  define LEFT 65361
#  define RIGHT 65363
#  define UP 65362
#  define DOWN 65364
# endif

#endif