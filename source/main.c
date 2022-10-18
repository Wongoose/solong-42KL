/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zwong <zwong@student.42kl.edu.my>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/13 09:24:09 by zwong             #+#    #+#             */
/*   Updated: 2022/10/18 11:14:59 by zwong            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../so_long.h"

t_tile	**init_map(t_game *game, int argc, char **argv)
{
	char	**map;
	char	*err_msg;
	t_tile	**tilemap;

	valid_file(argc, argv[1]);
	map = read_map(argv[1]);
	if (!map)
		err_exit("Failed to read file");
	err_msg = valid_map(game, map);
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
	game->win = mlx_new_window(game->mlx, game->win_size.x
			+ IMG_SIZE * 1.5, game->win_size.y, "so_long");
}

void	init_images(t_game *game)
{
	game->player.img = my_xpm_to_img(game, "assets/character-right.xpm");
	game->player.right_img = my_xpm_to_img(game, "assets/character-right.xpm");
	game->player.left_img = my_xpm_to_img(game, "assets/character-left.xpm");
	game->player.slash_img = my_xpm_to_img(game, "assets/character-slash.xpm");
	game->exit_img = my_xpm_to_img(game, "assets/trophy.xpm");
	game->exit_img1 = my_xpm_to_img(game, "assets/trophy.xpm");
	game->exit_img2 = my_xpm_to_img(game, "assets/trophy2.xpm");
	game->enemy.img = my_xpm_to_img(game, "assets/slime-right.xpm");
	game->enemy.right_img = my_xpm_to_img(game, "assets/slime-right.xpm");
	game->enemy.left_img = my_xpm_to_img(game, "assets/slime-left.xpm");
	game->wall_img = my_xpm_to_img(game, "assets/tree.xpm");
	game->background_img = my_xpm_to_img(game, "assets/wood.xpm");
	game->collectible_img = my_xpm_to_img(game, "assets/apple.xpm");
}

int	init_game(t_game *game, int argc, char **argv)
{
	game->moves = 0;
	game->tilemap = init_map(game, argc, argv);
	init_display(game);
	init_images(game);
	return (1);
}

int	main(int argc, char **argv)
{
	t_game	game;

	if (!init_game(&game, argc, argv))
		return (0);
	mlx_hook(game.win, 17, 0, end_program, &game);
	mlx_hook(game.win, 2, 1L, input, &game);
	mlx_loop_hook(game.mlx, render, (void *)&game);
	mlx_loop(game.mlx);
	return (0);
}
