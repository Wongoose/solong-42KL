#include "../../so_long.h"

void	free_map(char **map)
{
	int	i;

	i = 0;
	while (map[i])
		free(map[i++]);
	free(map[i]);
	free(map);
}

void	free_tilemap(t_tile **tilemap)
{
	int	i;

	i = 0;
	while (tilemap[i])
		free(tilemap[i++]);
	free(tilemap[i]);
	free(tilemap);
}

int	end_program(t_game *game)
{
	free_tilemap(game->tilemap);
	mlx_destroy_window(game->mlx, game->win);
	// system("leaks so_long");
	exit(1);
}