# include "../../so_long.h"

int	move_player(t_game *game, t_tile *tile)
{
	if (tile->type == WALL)
		return (0);
	if (tile->type == EXIT || tile->type == ENEMY)
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

int	move_enemy(t_game *game, t_tile *tile)
{
	if (tile->type == WALL)
		return (0);
	if (tile->type == EXIT)
		return (0);
	if (tile->type == COLLECTIBLE)
		return (0);
	if (tile->type == PLAYER)
		end_program(game);
	tile->type = ENEMY;
	game->enemy.tile->type = EMPTY;
	game->enemy.tile = tile;
	return (1);
}

void	enemy_input(int keycode, t_game *game)
{
	if (keycode == ARROW_UP)
		move_enemy(game, game->enemy.tile->up);
	else if (keycode == ARROW_DOWN)
		move_enemy(game, game->enemy.tile->down);
	else if (keycode == ARROW_LEFT)
	{
		game->enemy.img = game->enemy.left_img;
		move_enemy(game, game->enemy.tile->left);
	}
	else if (keycode == ARROW_RIGHT)
	{
		game->enemy.img = game->enemy.right_img;
		move_enemy(game, game->enemy.tile->right);
	}
}

int	input(int keycode, t_game *game)
{
	game->player.img = game->player.right_img;
	if (keycode == ESC)
		end_program(game);
	if (keycode == KEY_UP)
		move_player(game, game->player.tile->up);
	else if (keycode == KEY_DOWN)
		move_player(game, game->player.tile->down);
	else if (keycode == KEY_LEFT)
	{
		game->player.img = game->player.left_img;
		move_player(game, game->player.tile->left);
	}
	else if (keycode == KEY_RIGHT)
		move_player(game, game->player.tile->right);
	else
		enemy_input(keycode, game);
	return (1);
}
