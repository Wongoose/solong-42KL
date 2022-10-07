#include "../../so_long.h"

char	**read_map(char *file)
{
	char	**map;
	char	buffer[10000];
	int		fd;
	int		row;

	fd = open(file, O_RDONLY);
	if (read(fd, buffer, 10000) < 0)
		return (NULL);
	map = ft_split(buffer, '\n');
	if (!map)
		return (NULL);
	row = 0;
	while (map[row])
		row++;
	map[row - 1][ft_strlen(*map)] = 0;
	close(fd);
	return (map);
}