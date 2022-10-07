#include "../../so_long.h"

t_tile	**allocate_tiles(char **map)
{
	t_tile	**tilemap;
	int		rows;

	rows = 0;
	while (map[rows])
		rows++;
	printf("NUMBER OF ROWS:%d\n", rows);
		// BELOW: +1 for null terminator at end of map
	tilemap = malloc(sizeof(t_tile *) * (rows + 1));
	if (!tilemap)
		return (NULL);
	rows = 0;
	while (map[rows])
	{
		// BELOW: +1 for null terminator at end of each row
		printf("Row len:%zu\n", ft_strlen(*map));
		tilemap[rows] = (t_tile *)malloc(sizeof(t_tile) * (ft_strlen(*map) + 1));
		if (!tilemap[rows])
			return (NULL);
			// MISSING: free tilemap
		rows++;
	}
	return (tilemap);
}

t_tiletype	define_type(char c)
{
	if (c == '1')
		return (WALL);
	if (c == 'C')
		return (COLLECTABLE);
	if (c == 'P')
		return (PLAYER);
	if (c == 'E')
		return (EXIT);
	if (c == 'H' || c == 'V')
		return (ENEMY);
	else if (c == 'F')
		return (FOLLOWER);
	return (EMPTY);
}

void	setup_tile(t_tile **tilemap, int col, int row)
{
	tilemap[row][col].pos.x = col * IMG_SIZE;
	tilemap[row][col].pos.y = row * IMG_SIZE;
	// BELOW: Setting link list for tiles (up, down, left, right)
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
		err_exit("Failed to allocate tiles");
	row = 0;
	while (map[row])
	{
		col = 0;
		while (map[row][col] != '\0')
		{
			tilemap[row][col].type = define_type(map[row][col]);
			setup_tile(tilemap, col, row);
			if (tilemap[row][col].type == PLAYER)
				game->player.tile = &tilemap[row][col];
			// MISSING: set game variables (i.e. collectibles++)
			col++;
		}
		// BELOW: Set end of each row as NULL
		printf("Setting col null at col:%d\n", col);
		tilemap[row][col].type = 0;
		row++;
	}
	// BELOW: Set end of map as NULL
	printf("Setting row null at row:%d\n", row);
	tilemap[row] = NULL;
	game->win_size.x = col * IMG_SIZE;
	game->win_size.y = row * IMG_SIZE;
	return (tilemap);
}