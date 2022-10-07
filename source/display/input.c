# include "../../so_long.h"

int	move_player(t_game *game, t_tile *tile)
{
	// TESTING: default empty
	if (tile->type == EMPTY)
	{
		tile->type = PLAYER;
		if (game->player.tile->type != EXIT)
			game->player.tile->type = EMPTY;
		game->player.tile = tile;
	}
	return (0);
}

int	input(int keycode, t_game *game)
{
	if (keycode == ESC)
		end_program(game);
	if (keycode == KEY_UP)
		move_player(game, game->player.tile->up);
	else if (keycode == KEY_DOWN)
		move_player(game, game->player.tile->down);
	else if (keycode == KEY_LEFT)
		move_player(game, game->player.tile->left);
	else if (keycode == KEY_RIGHT)
		move_player(game, game->player.tile->right);
	else
		return (0);
	return (1);
}