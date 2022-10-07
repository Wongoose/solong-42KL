#include "../../so_long.h"

void	err_exit(char *err)
{
	perror(err);
	exit(1);
}