/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_init_tiles.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zwong <zwong@student.42kl.edu.my>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/13 09:30:44 by zwong             #+#    #+#             */
/*   Updated: 2022/10/13 10:26:57 by zwong            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../so_long.h"

t_tile	**allocate_tiles(char **map)
{
	t_tile	**tilemap;
	int		rows;

	rows = 0;
	while (map[rows])
		rows++;
	tilemap = malloc(sizeof(t_tile *) * (rows + 1));
	if (!tilemap)
		return (NULL);
	rows = 0;
	while (map[rows])
	{
		tilemap[rows] = malloc(sizeof(t_tile) * (ft_strlen(*map) + 1));
		if (!tilemap[rows])
		{
			free_tilemap(tilemap);
			return (NULL);
		}
		rows++;
	}
	return (tilemap);
}

t_tiletype	define_type(char c)
{
	if (c == '1')
		return (WALL);
	else if (c == 'C')
		return (COLLECTIBLE);
	else if (c == 'P')
		return (PLAYER);
	else if (c == 'E')
		return (EXIT);
	else if (c == 'X')
		return (ENEMY);
	else
		return (EMPTY);
}

void	setup_tile(t_tile **tilemap, int col, int row)
{
	tilemap[row][col].pos.x = col * IMG_SIZE;
	tilemap[row][col].pos.y = row * IMG_SIZE;
	if (row != 0)
		tilemap[row][col].up = &tilemap[row - 1][col];
	if (tilemap[row + 1] != NULL)
		tilemap[row][col].down = &tilemap[row + 1][col];
	if (col != 0)
		tilemap[row][col].left = &tilemap[row][col - 1];
	tilemap[row][col].right = &tilemap[row][col + 1];
	tilemap[row][col].prev_type = 0;
}

void	setup_players(t_game *game, t_tile *tile)
{
	if (tile->type == PLAYER)
		game->player.tile = tile;
	else if (tile->type == ENEMY)
		game->enemy.tile = tile;
}

t_tile	**init_tiles(char **map, t_game *game)
{
	t_tile	**tilemap;
	int		col;
	int		row;

	tilemap = allocate_tiles(map);
	if (!tilemap)
		return (NULL);
	row = 0;
	while (map[row])
	{
		col = 0;
		while (map[row][col])
		{
			tilemap[row][col].type = define_type(map[row][col]);
			setup_tile(tilemap, col, row);
			setup_players(game, &tilemap[row][col]);
			col++;
		}
		tilemap[row][col].type = 0;
		row++;
	}
	tilemap[row] = NULL;
	game->win_size.x = col * IMG_SIZE;
	game->win_size.y = row * IMG_SIZE;
	return (tilemap);
}
