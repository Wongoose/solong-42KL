#include "../../so_long.h"

char	**read_map(char *file)
{
	char	**map;
	char	buffer[10000];
	int		fd;
	int		i;

	fd = open(file, O_RDONLY);
	// READ FILE then SPLIT
	if (read(fd, buffer, 10000) < 0)
		return (NULL);
	map = ft_split(buffer, '\n');
	i = 0;
	while (map[i])
		i++;
	map[i - 1][ft_strlen(*map)] = 0;
	// i = 0;
	// while (map[i])
	// 	printf("split: %s\n", map[i++]);
	// printf("split: %s\n", map[i]);
	close(fd);
	return (map);
}