#include "../../so_long.h"

void	draw_image(t_tile tile, t_game *game, t_vector pos)
{
	if (tile.type == PLAYER)
		mlx_put_image_to_window(game->mlx, game->win, game->player.img, pos.x, pos.y);
	else if (tile.type == WALL)
		mlx_put_image_to_window(game->mlx, game->win, game->wall_img, pos.x, pos.y);
	else if (tile.type == EMPTY)
		mlx_put_image_to_window(game->mlx, game->win, game->background_img, pos.x, pos.y);
	else if (tile.type == COLLECTIBLE)
		mlx_put_image_to_window(game->mlx, game->win, game->collectible_img, pos.x, pos.y);
	else if (tile.type == EXIT)
		mlx_put_image_to_window(game->mlx, game->win, game->exit_img, pos.x, pos.y);
}

int	render(t_game *game)
{
	t_tile	tile;
	int		col;
	int		row;

	row = 0;
	while (game->tilemap[row] != NULL)
	{
		col = 0;
		while (game->tilemap[row][col].type != 0)
		{
			if (game->tilemap[row][col].type != game->tilemap[row][col].prev_type)
			{
				tile = game->tilemap[row][col];
				draw_image(tile, game, tile.pos);
				game->tilemap[row][col].prev_type = game->tilemap[row][col].type;
			}
			col++;
		}
		row++;
	}
	return (0);
}

int	init_background(t_game *game)
{
	int		col;
	int		row;

	row = 0;
	while (game->tilemap[row] != NULL)
	{
		col = 0;
		while (game->tilemap[row][col].type != 0)
		{
			mlx_put_image_to_window(game->mlx, game->win, game->background_img, game->tilemap[row][col].pos.x, game->tilemap[row][col].pos.y);
			col++;
		}
		row++;
	}
	return (0);
}