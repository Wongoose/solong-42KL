#include "../so_long.h"

t_tile	**init_map(t_game *game, char **argv)
{
	char	**map;
	t_tile	**tilemap;

	// MISSING: Check for valid map file
	// map file parsed in argument
	map = read_map(argv[1]);
	if (!map)
		return (NULL);
	// MISSING: validate map content
	tilemap = init_tiles(map, game);
	// MISSIG: free map
	if (!tilemap)
		return (NULL);
	return (tilemap);
}

void	init_display(t_game *game)
{
	game->mlx = mlx_init();
	game->win = mlx_new_window(game->mlx, game->win_size.x, game->win_size.y, "so_long");
	init_images(game);
}

int	init_game(t_game *game, char **argv)
{
	// MISSING: init collect and moves
	game->tilemap = init_map(game, argv);
	if (!game->tilemap)
		err_exit("Failed to init tiles");
	// MISSING: animation setup
	init_display(game);
	return (1);
}

int	main(int argc, char **argv)
{
	t_game	game;

	(void)argc;
	if (!init_game(&game, argv))
		return (0);
	// BELOW: Commented destroy notify event key
	// mlx_hook(game.win, 17, 0, end_program, &game);
	mlx_hook(game.win, 2, 1L<<0, input, &game);
	mlx_loop_hook(game.mlx, render, (void *)&game);
	mlx_loop(game.mlx);
	system("leaks so_long");
}