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

//MISSING: validate map