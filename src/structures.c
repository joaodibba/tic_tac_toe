#include "game.h"

/**
 * * game
 * @brief	Returns a pointer to the singleton game instance
 * @return	Pointer to the static t_game structure
 * @details	Implements singleton pattern to ensure only one game instance exists
 */
t_game	*game(void)
{
	static t_game	game;

	return (&game);
}

/**
 * * image
 * @brief	Returns a pointer to the game's image structure
 * @return	Pointer to the t_image structure within the game instance
 */
t_image *image(void)
{
	return(&(game()->image));
}

/**
 * * player1
 * @brief	Returns a pointer to player 1's data structure
 * @return	Pointer to the t_player structure for player 1
 */
t_player *player1(void)
{
	return(&(game()->player1));
}

/**
 * * player2
 * @brief	Returns a pointer to player 2's data structure
 * @return	Pointer to the t_player structure for player 2
 */
t_player *player2(void)
{
	return(&(game()->player2));
}