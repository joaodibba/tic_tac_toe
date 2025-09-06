#include "game.h"

int	is_valid_move(int x, int y)
{
	if (x < 0 || x >= 3 || y < 0 || y >= 3)
		return (0);
	return (game()->grid[y][x] == EMPTY);
}

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

int	check_win(void)
{
	char	**grid = game()->grid;
	
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

int	check_draw(void)
{
	return (game()->moves_count >= 9);
}

void	switch_player(void)
{
	if (game()->current_player == PLAYER_1)
		game()->current_player = PLAYER_2;
	else
		game()->current_player = PLAYER_1;
}

void	reset_game(void)
{
	for (int i = 0; i < 3; i++)
	{
		for (int j = 0; j < 3; j++)
			game()->grid[i][j] = EMPTY;
	}
	game()->current_player = PLAYER_1;
	game()->game_state = GAME_PLAYING;
	game()->moves_count = 0;
	game()->restart_timer = 0;
	game()->show_help = false;
	player1()->select.x = 1;
	player1()->select.y = 1;
	player2()->select.x = 1;
	player2()->select.y = 1;
}

void	start_restart_timer(void)
{
	game()->restart_timer = 180; // 3 seconds at 60 FPS
}

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

void	update_selection_display(void)
{
	// This function is now just a placeholder since we use player selections directly
}

// Helper function to find next available position in a direction
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

// Function to reset cursor to next available position after a move
void	reset_cursor_after_move(int player)
{
	t_pos	*current_selection;
	
	// Get the current player's selection
	if (player == PLAYER_1)
		current_selection = &player1()->select;
	else
		current_selection = &player2()->select;
	
	// Find the first available position starting from (0,0)
	for (int y = 0; y < 3; y++)
	{
		for (int x = 0; x < 3; x++)
		{
			if (is_valid_move(x, y))
			{
				current_selection->x = x;
				current_selection->y = y;
				return;
			}
		}
	}
	
	// If no available positions (shouldn't happen in normal gameplay)
}
