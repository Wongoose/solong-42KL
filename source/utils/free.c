/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   free.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zwong <zwong@student.42kl.edu.my>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/13 09:31:06 by zwong             #+#    #+#             */
/*   Updated: 2022/10/13 10:47:09 by zwong            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

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
	exit(1);
}
