#include "game.h"

t_game	*game(void)
{
	static t_game	game;

	return (&game);
}

t_image *image(void)
{
	return(&(game()->image));
}

t_player *player1(void)
{
	return(&(game()->player1));
}

t_player *player2(void)
{
	return(&(game()->player2));
}