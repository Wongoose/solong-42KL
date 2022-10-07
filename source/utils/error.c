#include "../../so_long.h"

void	err_exit(char *err)
{
	perror(err);
	system("leaks so_long");
	exit(1);
}

void	putstr_fd_exit(char *err)
{
	ft_putstr_fd("Error\n", 2);
	ft_putstr_fd(err, 2);
	system("leaks so_long");
	exit(1);
}