#include "../../so_long.h"

void	valid_file(int argc, char *filename)
{
	char	*filetype;

	if (argc < 2)
	{
		ft_putstr_fd("Too few arguments.", 2);
		exit(1);
	}
	if (argc > 2)
	{
		ft_putstr_fd("Too few arguments.", 2);
		exit(1);
	}
	filetype = ft_strnstr(filename, ".ber", ft_strlen(filename));
	if(!filetype || ft_strlen(filetype) != 4)
	{
		ft_putstr_fd("Map should be a valid .ber file", 2);
		exit(1);
	}
}

void	init_mapvars(t_map *map_vars)
{
	map_vars->exitNum = 0;
	map_vars->startNum = 0;
	map_vars->collectNum = 0;
	map_vars->invalidChar = 0;
}

void	update_map_vars(t_map *map_vars, char c)
{
	if (c == 'E')
		map_vars->exitNum++;
	else if (c == 'P')
		map_vars->startNum++;
	else if (c == 'C')
		map_vars->collectNum++;
	else if (c == '0' || c == '1')
		return ;
	else
		map_vars->invalidChar++;
}

int	valid_wall(char **map)
{
	int		row;
	int		col;

	row = 0;
	// loop check front and end only
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

int	valid_map(char **map)
{
	t_map	map_vars;
	int		row;
	int		col;

	init_mapvars(&map_vars);
	row = 0;
	while (map[row])
	{
		col = 0;
		while (map[row][col])
		{
			update_map_vars(&map_vars, map[row][col]);
			if (map_vars.invalidChar > 0)
			{
				ft_putstr_fd("Error\nFound invalid characters!", 2);
				return (0);
			}
			col++;
		}
		row++;
	}
	// printf("Number of P is: %d\n", map_vars.startNum);
	// printf("Number of E is: %d\n", map_vars.exitNum);
	// printf("Number of C is: %d\n", map_vars.collectNum);
	// DONE: Check if map is rectangular
	if (row == col)
	{
		ft_putstr_fd("Error\nMap must be rectangular.", 2);
		return (0);
	}
	// Check if map is surrounded by walls
	if (!valid_wall(map))
	{
		ft_putstr_fd("Error\nInvalid wall detected!", 2);
		return (0);
	}
	if (!((map_vars.startNum == 1 && map_vars.exitNum == 1) && map_vars.collectNum > 0))
	{
		ft_putstr_fd("Error\nThere must only be one 'P' and one 'E' and at least one 'C' in the map.", 2);
		// must return because map will only be freed in parent function
		return (0);
	}
	return (1);
}