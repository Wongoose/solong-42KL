#include "../so_long.h"

t_tile	**init_map(t_game *game, int argc, char **argv)
{
	char	**map;
	char	*err_msg;
	t_tile	**tilemap;

	valid_file(argc, argv[1]);
	map = read_map(argv[1]);
	if (!map)
		putstr_fd_exit("Failed to read map file.");
	err_msg = valid_map(map);
	if (err_msg)
	{
		free_map(map);
		putstr_fd_exit(err_msg);
	}
	tilemap = init_tiles(map, game);
	if (!tilemap)
		putstr_fd_exit("Failed to initialize tilemap.");
	free_map(map);
	return (tilemap);
}

void	init_display(t_game *game)
{
	game->mlx = mlx_init();
	game->win = mlx_new_window(game->mlx, game->win_size.x, game->win_size.y, "so_long");
}

void	init_images(t_game *game)
{
	game->player.img = mlx_xpm_file_to_image(game->mlx, "assets/idle_0.xpm", &game->img_size.x, &game->img_size.y);
	game->wall_img = mlx_xpm_file_to_image(game->mlx, "assets/Brown.xpm", &game->img_size.x, &game->img_size.y);
	game->background_img = mlx_xpm_file_to_image(game->mlx, "assets/Gray.xpm", &game->img_size.x, &game->img_size.y);
	game->collectible_img = mlx_xpm_file_to_image(game->mlx, "assets/Apple.xpm", &game->img_size.x, &game->img_size.y);
	game->exit_img = mlx_xpm_file_to_image(game->mlx, "assets/Exit.xpm", &game->img_size.x, &game->img_size.y);
}

int	init_game(t_game *game, int argc, char **argv)
{
	// MISSING: init collect and moves
	game->tilemap = init_map(game, argc, argv);
	// MISSING: animation setup
	init_display(game);
	init_images(game);
	return (1);
}

int	main(int argc, char **argv)
{
	t_game	game;

	(void)argc;
	if (!init_game(&game, argc, argv))
		return (0);
	mlx_hook(game.win, 17, 0, end_program, &game);
	mlx_hook(game.win, 2, 1L<<0, input, &game);
	mlx_loop_hook(game.mlx, render, (void *)&game);
	mlx_loop(game.mlx);
	return (0);
}