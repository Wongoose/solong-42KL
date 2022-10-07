#include "../../so_long.h"

void	open_player(t_game *game)
{
	game->player.img = mlx_xpm_file_to_image(game->mlx, "assets/idle_8.xpm", &game->img_size.x, &game->img_size.y);
}

// MISSING: Open wall images
// MISSING: Open collect images
// MISSING: Open enemy images
// MISSING: Open door images

void	init_images(t_game *game)
{
	open_player(game);
}