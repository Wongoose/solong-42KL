/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   render.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zwong <zwong@student.42kl.edu.my>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/13 09:30:33 by zwong             #+#    #+#             */
/*   Updated: 2022/10/13 10:06:30 by zwong            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../so_long.h"

void	animate_trophy(t_game *game)
{
	if (game->moves % 2)
		game->exit_img = game->exit_img2;
	else
		game->exit_img = game->exit_img1;
}

void	draw_image(t_tile tile, t_game *game, t_vector pos)
{
	mlx_put_image_to_window(game->mlx, game->win,
		game->background_img, pos.x, pos.y);
	if (tile.type == PLAYER)
		mlx_put_image_to_window(game->mlx, game->win,
			game->player.img, pos.x, pos.y);
	else if (tile.type == WALL)
		mlx_put_image_to_window(game->mlx, game->win,
			game->wall_img, pos.x, pos.y);
	else if (tile.type == EMPTY)
		mlx_put_image_to_window(game->mlx, game->win,
			game->background_img, pos.x, pos.y);
	else if (tile.type == COLLECTIBLE)
		mlx_put_image_to_window(game->mlx, game->win,
			game->collectible_img, pos.x, pos.y);
	else if (tile.type == EXIT)
		mlx_put_image_to_window(game->mlx, game->win,
			game->exit_img, pos.x, pos.y);
	else if (tile.type == ENEMY)
		mlx_put_image_to_window(game->mlx, game->win,
			game->enemy.img, pos.x, pos.y);
}

void	draw_text(t_game *game)
{
	char	*str;

	str = ft_itoa((game->moves) - 1);
	mlx_string_put(game->mlx, game->win,
		game->win_size.x + 5,
		5,
		1, str);
	free(str);
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

	animate_trophy(game);
	row = 0;
	while (game->tilemap[row] != NULL)
	{
		col = 0;
		while (game->tilemap[row][col].type != 0)
		{
			tile = game->tilemap[row][col];
			if ((tile.type == EXIT) || (tile.type != tile.prev_type))
			{
				draw_image(tile, game, tile.pos);
				game->tilemap[row][col].prev_type = tile.type;
			}
			col++;
		}
		row++;
	}
	draw_text(game);
	return (0);
}
