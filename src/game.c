#include "game.h"

/**
 * * is_valid_move
 * @brief	Checks if a move is valid at the given coordinates
 * @param x	The x coordinate (0-2) of the grid position
 * @param y	The y coordinate (0-2) of the grid position
 * @return	1 if the move is valid (within bounds and position is empty), 0 otherwise
 */
int	is_valid_move(int x, int y)
{
	if (x < 0 || x >= 3 || y < 0 || y >= 3)
		return (0);
	return (game()->grid[y][x] == EMPTY);
}

/**
 * * make_move
 * @brief	Places a player's piece on the grid at the specified coordinates
 * @param x	The x coordinate (0-2) where the piece will be placed
 * @param y	The y coordinate (0-2) where the piece will be placed
 * @param player	The player making the move (PLAYER_1 or PLAYER_2)
 */
void	make_move(int x, int y, int player)
{
	if (!is_valid_move(x, y))
	{
		return;
	}
	
	if (player == PLAYER_1)
		game()->grid[y][x] = CIRCLE;
	else
		game()->grid[y][x] = CROSS;
	
	game()->moves_count++;
}

/**
 * * check_win
 * @brief	Checks if any player has won the game by having three in a row
 * @return	1 if a player has won, 0 if no winner yet
 * @note	When a win is detected, the winning line is marked with special
 * 		textures (HORIZONTAL, VERTICAL, or DIAGONAL variants)
 */
int	check_win(void)
{
	char (*grid)[3] = game()->grid;
	
	// Check rows
	for (int i = 0; i < 3; i++)
	{
		if (grid[i][0] != EMPTY && grid[i][0] == grid[i][1] && grid[i][1] == grid[i][2])
		{
			// Mark winning line
			grid[i][0] = (grid[i][0] == CIRCLE) ? CIRCLE_HORIZONTAL : CROSS_HORIZONTAL;
			grid[i][1] = (grid[i][1] == CIRCLE) ? CIRCLE_HORIZONTAL : CROSS_HORIZONTAL;
			grid[i][2] = (grid[i][2] == CIRCLE) ? CIRCLE_HORIZONTAL : CROSS_HORIZONTAL;
			return (1);
		}
	}
	
	// Check columns
	for (int j = 0; j < 3; j++)
	{
		if (grid[0][j] != EMPTY && grid[0][j] == grid[1][j] && grid[1][j] == grid[2][j])
		{
			// Mark winning line
			grid[0][j] = (grid[0][j] == CIRCLE) ? CIRCLE_VERTICAL : CROSS_VERTICAL;
			grid[1][j] = (grid[1][j] == CIRCLE) ? CIRCLE_VERTICAL : CROSS_VERTICAL;
			grid[2][j] = (grid[2][j] == CIRCLE) ? CIRCLE_VERTICAL : CROSS_VERTICAL;
			return (1);
		}
	}
	
	// Check diagonals
	if (grid[0][0] != EMPTY && grid[0][0] == grid[1][1] && grid[1][1] == grid[2][2])
	{
		// Mark winning line
		grid[0][0] = (grid[0][0] == CIRCLE) ? CIRCLE_DIAGONAL_LEFT : CROSS_DIAGONAL_LEFT;
		grid[1][1] = (grid[1][1] == CIRCLE) ? CIRCLE_DIAGONAL_LEFT : CROSS_DIAGONAL_LEFT;
		grid[2][2] = (grid[2][2] == CIRCLE) ? CIRCLE_DIAGONAL_LEFT : CROSS_DIAGONAL_LEFT;
		return (1);
	}
	if (grid[0][2] != EMPTY && grid[0][2] == grid[1][1] && grid[1][1] == grid[2][0])
	{
		// Mark winning line
		grid[0][2] = (grid[0][2] == CIRCLE) ? CIRCLE_DIAGONAL_RIGHT : CROSS_DIAGONAL_RIGHT;
		grid[1][1] = (grid[1][1] == CIRCLE) ? CIRCLE_DIAGONAL_RIGHT : CROSS_DIAGONAL_RIGHT;
		grid[2][0] = (grid[2][0] == CIRCLE) ? CIRCLE_DIAGONAL_RIGHT : CROSS_DIAGONAL_RIGHT;
		return (1);
	}
	
	return (0);
}

/**
 * * check_draw
 * @brief	Checks if the game has ended in a draw (all positions filled)
 * @return	1 if the game is a draw, 0 if moves are still available
 */
int	check_draw(void)
{
	return (game()->moves_count >= 9);
}

/**
 * * switch_player
 * @brief	Switches the current player between PLAYER_1 and PLAYER_2
 */
void	switch_player(void)
{
	if (game()->current_player == PLAYER_1)
		game()->current_player = PLAYER_2;
	else
		game()->current_player = PLAYER_1;
}

/**
 * * reset_game
 * @brief	Resets the game to its initial state with randomization
 * @details	Clears the grid, randomly selects starting player, sets game state
 * 		to GAME_PLAYING, resets move count and timer, and randomly positions
 * 		both player cursors for variety
 */
void	reset_game(void)
{
	for (int i = 0; i < 3; i++)
	{
		for (int j = 0; j < 3; j++)
			game()->grid[i][j] = EMPTY;
	}
	
	// Randomize starting player
	game()->current_player = (rand() % 2) ? PLAYER_1 : PLAYER_2;
	game()->game_state = GAME_PLAYING;
	game()->moves_count = 0;
	game()->restart_timer = 0;
	game()->show_help = false;
	
	// Randomize cursor positions
	player1()->select.x = rand() % 3;
	player1()->select.y = rand() % 3;
	player2()->select.x = rand() % 3;
	player2()->select.y = rand() % 3;
}

/**
 * * start_restart_timer
 * @brief	Starts a 3-second countdown timer for automatic game restart
 * @details	Sets the restart timer to 180 frames (3 seconds at 60 FPS)
 */
void	start_restart_timer(void)
{
	game()->restart_timer = 180; // 3 seconds at 60 FPS
}

/**
 * * update_restart_timer
 * @brief	Decrements the restart timer and resets the game when it reaches 0
 * @details	Called every frame to count down the restart timer.
 * 		When the timer reaches 0, automatically calls reset_game()
 */
void	update_restart_timer(void)
{
	if (game()->restart_timer > 0)
	{
		game()->restart_timer--;
		if (game()->restart_timer == 0)
		{
			reset_game();
		}
	}
}

/**
 * * update_selection_display
 * @brief	Placeholder function for selection display updates
 * @details	This function is currently unused as player selections
 * 		are handled directly in the rendering system
 */
void	update_selection_display(void)
{
	// This function is now just a placeholder since we use player selections directly
}

/**
 * * find_next_available_position
 * @brief	Finds the next available position in a specified direction from current position
 * @param current	The current position on the grid
 * @param direction	The direction to search (0=up, 1=down, 2=left, 3=right)
 * @return	The next available position in the requested direction
 * @details	If the immediate direction is blocked, finds the best alternative
 * 		position that most closely matches the requested direction using
 * 		a scoring system that considers both direction preference and distance
 */
t_pos	find_next_available_position(t_pos current, int direction)
{
	t_pos	next = current;
	
	// First, try to move in the specified direction
	switch (direction)
	{
		case 0: // up
			next.y = (next.y > 0) ? next.y - 1 : 2;
			break;
		case 1: // down
			next.y = (next.y < 2) ? next.y + 1 : 0;
			break;
		case 2: // left
			next.x = (next.x > 0) ? next.x - 1 : 2;
			break;
		case 3: // right
			next.x = (next.x < 2) ? next.x + 1 : 0;
			break;
	}
	
	// If the immediate next position is valid, return it
	if (is_valid_move(next.x, next.y))
		return (next);
	
	// If immediate direction is blocked, find all available positions
	// and choose the one that best matches the requested direction
	t_pos	available_positions[9];
	int		available_count = 0;
	
	// Collect all available positions
	for (int y = 0; y < 3; y++)
	{
		for (int x = 0; x < 3; x++)
		{
			if (is_valid_move(x, y) && !(x == current.x && y == current.y))
			{
				available_positions[available_count].x = x;
				available_positions[available_count].y = y;
				available_count++;
			}
		}
	}
	
	// If no positions available (shouldn't happen), return current
	if (available_count == 0)
	{
		return (current);
	}
	
	// Find the position that best matches the requested direction
	t_pos	best_position = available_positions[0];
	int		best_score = -1000; // Start with very low score
	
	for (int i = 0; i < available_count; i++)
	{
		t_pos pos = available_positions[i];
		int score = 0;
		
		// Calculate directional preference score
		int dx = pos.x - current.x;
		int dy = pos.y - current.y;
		
		// Handle wrapping - choose the shorter path
		if (dx > 1) dx -= 3;      // If dx = 2, it's actually -1 (left wrap)
		else if (dx < -1) dx += 3; // If dx = -2, it's actually 1 (right wrap)
		
		if (dy > 1) dy -= 3;      // If dy = 2, it's actually -1 (up wrap)
		else if (dy < -1) dy += 3; // If dy = -2, it's actually 1 (down wrap)
		
		// Score based on alignment with requested direction
		switch (direction)
		{
			case 0: // up - prefer negative dy
				score = -dy * 10;
				if (dy < 0) score += 20; // Bonus for actual upward movement
				break;
			case 1: // down - prefer positive dy
				score = dy * 10;
				if (dy > 0) score += 20; // Bonus for actual downward movement
				break;
			case 2: // left - prefer negative dx
				score = -dx * 10;
				if (dx < 0) score += 20; // Bonus for actual leftward movement
				break;
			case 3: // right - prefer positive dx
				score = dx * 10;
				if (dx > 0) score += 20; // Bonus for actual rightward movement
				break;
		}
		
		// Secondary preference: closer positions get slight bonus
		int distance = abs(dx) + abs(dy);
		score += (3 - distance); // Closer = higher score
		
		if (score > best_score)
		{
			best_score = score;
			best_position = pos;
		}
	}
	
	return (best_position);
}

/**
 * * reset_cursor_after_move
 * @brief	Resets the specified player's cursor to a random available position
 * @param player	The player whose cursor should be reset (PLAYER_1 or PLAYER_2)
 * @details	Finds all available positions and randomly selects one for variety
 */
void	reset_cursor_after_move(int player)
{
	t_pos	*current_selection;
	t_pos	available_positions[9];
	int		available_count = 0;
	
	// Get the current player's selection
	if (player == PLAYER_1)
		current_selection = &player1()->select;
	else
		current_selection = &player2()->select;
	
	// Collect all available positions
	for (int y = 0; y < 3; y++)
	{
		for (int x = 0; x < 3; x++)
		{
			if (is_valid_move(x, y))
			{
				available_positions[available_count].x = x;
				available_positions[available_count].y = y;
				available_count++;
			}
		}
	}
	
	// Randomly select from available positions
	if (available_count > 0)
	{
		int random_index = rand() % available_count;
		current_selection->x = available_positions[random_index].x;
		current_selection->y = available_positions[random_index].y;
	}
}
