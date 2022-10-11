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
		tilemap[rows] = (t_tile *)malloc(sizeof(t_tile) * (ft_strlen(*map) + 1));
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
			tilemap[row][col].prev_type = 0;
			setup_tile(tilemap, col, row);
			if (tilemap[row][col].type == PLAYER)
				game->player.tile = &tilemap[row][col];
			else if (tilemap[row][col].type == ENEMY)
				game->enemy.tile = &tilemap[row][col];
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