#include "../../so_long.h"

void	draw_image(t_tile tile, t_game *game, t_vector pos)
{
	mlx_put_image_to_window(game->mlx, game->win, game->background_img, pos.x, pos.y);
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

void	draw_text(t_game *game)
{
	char	*str;

	str = ft_itoa((game->moves) - 1);
	mlx_string_put(game->mlx, game->win,
		game->win_size.x + 5,
		5,
		1, str);
	str = ft_itoa(game->moves);
	mlx_string_put(game->mlx, game->win,
		game->win_size.x + 5,
		5,
		-1, str);
	free(str);
}

int	render(t_game *game)
{
	t_tile	tile;
	int		col;
	int		row;

	row = 0;
	if (game->moves % 2)
		game->exit_img = game->exit_img2;
	else
		game->exit_img = game->exit_img1;
	while (game->tilemap[row] != NULL)
	{
		col = 0;
		while (game->tilemap[row][col].type != 0)
		{
			if ((game->tilemap[row][col].type == EXIT) || (game->tilemap[row][col].type != game->tilemap[row][col].prev_type))
			{
				tile = game->tilemap[row][col];
				draw_image(tile, game, tile.pos);
				game->tilemap[row][col].prev_type = game->tilemap[row][col].type;
			}
			col++;
		}
		row++;
	}
	draw_text(game);
	return (0);
}

// void	init_background(t_game *game)
// {
// 	int		col;
// 	int		row;

// 	row = 0;
// 	while (game->tilemap[row] != NULL)
// 	{
// 		col = 0;
// 		while (game->tilemap[row][col].type != 0)
// 		{
// 			mlx_put_image_to_window(game->mlx, game->win, game->background_img, game->tilemap[row][col].pos.x, game->tilemap[row][col].pos.y);
// 			col++;
// 		}
// 		row++;
// 	}
// }