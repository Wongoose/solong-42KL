/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_validation.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zwong <zwong@student.42kl.edu.my>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/13 09:30:49 by zwong             #+#    #+#             */
/*   Updated: 2022/10/17 17:20:40 by zwong            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../so_long.h"

// Auto exit if invalid file
void	valid_file(int argc, char *filename)
{
	char	*filetype;

	if (argc < 2)
		putstr_fd_exit("Too few arguments.");
	if (argc > 2)
		putstr_fd_exit("Too many arguments.");
	filetype = ft_strnstr(filename, ".ber", ft_strlen(filename));
	if (!filetype || ft_strlen(filetype) != 4)
		putstr_fd_exit("Map should be a valid .ber file.");
}

t_map	*init_mapvars(void)
{
	t_map	*map_vars;

	map_vars = (t_map *)malloc(sizeof(t_map) * 1);
	map_vars->exit_num = 0;
	map_vars->start_num = 0;
	map_vars->enemy_num = 0;
	map_vars->collect_num = 0;
	map_vars->invalid_char = 0;
	return (map_vars);
}

void	update_map_vars(t_map *map_vars, char c)
{
	if (c == 'E')
		map_vars->exit_num++;
	else if (c == 'P')
		map_vars->start_num++;
	else if (c == 'C')
		map_vars->collect_num++;
	else if (c == 'X')
		map_vars->enemy_num++;
	else if (c == '0' || c == '1')
		return ;
	else
		map_vars->invalid_char++;
}

int	valid_wall(char **map)
{
	int		row;
	int		col;

	row = 0;
	while (map[row])
	{
		if (!(map[row][0] == '1' && map[row][ft_strlen(*map) - 1] == '1'))
			return (0);
		row++;
	}
	col = 0;
	row--;
	while (col < (int)ft_strlen(*map))
	{
		if (!(map[0][col] == '1' && map[row][col] == '1'))
			return (0);
		col++;
	}
	return (1);
}

char	*valid_map(t_game *game, char **map)
{
	t_map	*map_vars;
	int		row;
	int		col;

	map_vars = init_mapvars();
	game->map_vars = map_vars;
	row = 0;
	while (map[row])
	{
		col = 0;
		while (map[row][col])
			update_map_vars(map_vars, map[row][col++]);
		row++;
	}
	if (map_vars->invalid_char > 0)
		return ("Found invalid characters!");
	else if (row == col)
		return ("Map must be rectangular.");
	else if (!valid_wall(map))
		return ("Invalid wall detected!");
	else if (!(((map_vars->start_num == 1 && map_vars->exit_num == 1)
				&& map_vars->enemy_num == 1) && map_vars->collect_num > 0))
		return ("Map must have a 'P', an 'E', an 'X, and at least one 'C'.");
	return (0);
}
