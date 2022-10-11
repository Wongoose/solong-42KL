# include "../../so_long.h"

int	move_player(t_game *game, t_tile *tile)
{
	if (tile->type == WALL)
		return (0);
	if (tile->type == EXIT)
		end_program(game);
	if (tile->type == COLLECTIBLE)
	{
		game->map_vars->collectNum--;
		game->player.img = game->player.slash_img;
	}
	tile->type = PLAYER;
	game->player.tile->type = EMPTY;
	game->player.tile = tile;
	game->moves++;
	return (1);
}

int	input(int keycode, t_game *game)
{
	if (keycode == ESC)
		end_program(game);
	if (keycode == KEY_UP)
	{
		game->player.img = game->player.right_img;
		move_player(game, game->player.tile->up);
	}
	else if (keycode == KEY_DOWN)
	{
		game->player.img = game->player.right_img;
		move_player(game, game->player.tile->down);
	}
	else if (keycode == KEY_LEFT)
	{
		game->player.img = game->player.left_img;
		move_player(game, game->player.tile->left);
	}
	else if (keycode == KEY_RIGHT)
	{
		game->player.img = game->player.right_img;
		move_player(game, game->player.tile->right);
	}
	else
		return (0);
	return (1);
}