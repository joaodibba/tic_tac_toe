#include "game.h"

/**
 * * multiplayer_key_hook
 * @brief	Handles keyboard input for multiplayer tic-tac-toe game
 * @param key	The key code of the pressed key
 * @return	The key code that was processed
 * @details	Manages player movement, piece placement, help toggle, and game exit.
 * 		Player 1 uses WASD + SPACE, Player 2 uses arrow keys + ENTER.
 * 		H key toggles help display, ESC key exits the game.
 */
int	multiplayer_key_hook(int key)
{
	if (key == ESCAPE)
	{
		close_window();
		return (key);
	}
	
	// Toggle help with H key
	if (key == H_k)
	{
		game()->show_help = !game()->show_help;
		return (key);
	}
	
	// Randomize cursor positions with R key
	if (key == 15) // R key
	{
		player1()->select.x = rand() % 3;
		player1()->select.y = rand() % 3;
		player2()->select.x = rand() % 3;
		player2()->select.y = rand() % 3;
		return (key);
	}
	
	// Only allow moves during playing state
	if (game()->game_state != GAME_PLAYING)
	{
		if (key == SPACE || key == ENTER)
			reset_game();
		return (key);
	}
	
	// player 1 movement
	if (key == W_k)
	{
		player1()->select = find_next_available_position(player1()->select, 0); // up
	}
	else if (key == S_k)
	{
		player1()->select = find_next_available_position(player1()->select, 1); // down
	}
	else if (key == A_k)
	{
		player1()->select = find_next_available_position(player1()->select, 2); // left
	}
	else if (key == D_k)
	{
		player1()->select = find_next_available_position(player1()->select, 3); // right
	}
	else if (key == SPACE && game()->current_player == PLAYER_1)
	{
		if (is_valid_move(player1()->select.x, player1()->select.y))
		{
			make_move(player1()->select.x, player1()->select.y, PLAYER_1);
			if (check_win())
			{
				game()->game_state = GAME_WON;
				start_restart_timer();
			}
			else if (check_draw())
			{
				game()->game_state = GAME_DRAW;
				start_restart_timer();
			}
			else
			{
				switch_player();
				reset_cursor_after_move(game()->current_player);
			}
		}
	}
	// player 2 movement
	else if (key == UP)
	{
		player2()->select = find_next_available_position(player2()->select, 0); // up
	}
	else if (key == LEFT)
	{
		player2()->select = find_next_available_position(player2()->select, 2); // left
	}
	else if (key == DOWN)
	{
		player2()->select = find_next_available_position(player2()->select, 1); // down
	}
	else if (key == RIGHT)
	{
		player2()->select = find_next_available_position(player2()->select, 3); // right
	}
	else if (key == ENTER && game()->current_player == PLAYER_2)
	{
		if (is_valid_move(player2()->select.x, player2()->select.y))
		{
			make_move(player2()->select.x, player2()->select.y, PLAYER_2);
			if (check_win())
			{
				game()->game_state = GAME_WON;
				start_restart_timer();
			}
			else if (check_draw())
			{
				game()->game_state = GAME_DRAW;
				start_restart_timer();
			}
			else
			{
				switch_player();
				reset_cursor_after_move(game()->current_player);
			}
		}
	}
	return (key);
}

/**
 * * mouse_hook
 * @brief	Handles mouse click events for piece placement
 * @param button	The mouse button that was clicked (LEFT_CLICK, etc.)
 * @param x	The x coordinate of the mouse click
 * @param y	The y coordinate of the mouse click
 * @param param	Unused parameter (required by MLX hook signature)
 * @return	The button code that was processed
 * @details	Converts mouse coordinates to grid positions and places pieces
 * 		for the current player. Also handles game reset when not in playing state.
 */
int mouse_hook(int button, int x, int y, void *param)
{
	(void)param;
	
	if (game()->game_state != GAME_PLAYING)
	{
		if (button == LEFT_CLICK)
		{
			reset_game();
		}
		return (button);
	}
	
	if (button == LEFT_CLICK)
	{
		// Convert mouse coordinates to grid position
		int grid_x = (x - (WINDOW_SIZE / 2 - TEXTURE_SIZE * 1.5)) / TEXTURE_SIZE;
		int grid_y = (y - (WINDOW_SIZE / 2 - TEXTURE_SIZE * 1.5)) / TEXTURE_SIZE;
		
		// Check if click is within grid bounds
		if (grid_x >= 0 && grid_x < 3 && grid_y >= 0 && grid_y < 3)
		{
			if (is_valid_move(grid_x, grid_y))
			{
				make_move(grid_x, grid_y, game()->current_player);
				if (check_win())
				{
					game()->game_state = GAME_WON;
					start_restart_timer();
				}
				else if (check_draw())
				{
					game()->game_state = GAME_DRAW;
					start_restart_timer();
				}
				else
				{
					switch_player();
					reset_cursor_after_move(game()->current_player);
				}
			}
		}
	}
	return (button);
}