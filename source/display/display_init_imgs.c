#include "../../so_long.h"

void	open_player(t_game *game)
{
	game->player.img = mlx_xpm_file_to_image(game->mlx, "assets/idle_0.xpm", &game->img_size.x, &game->img_size.y);
	game->wall_img = mlx_xpm_file_to_image(game->mlx, "assets/Brown.xpm", &game->img_size.x, &game->img_size.y);
	game->background_img = mlx_xpm_file_to_image(game->mlx, "assets/Gray.xpm", &game->img_size.x, &game->img_size.y);
	game->collectible_img = mlx_xpm_file_to_image(game->mlx, "assets/Apple.xpm", &game->img_size.x, &game->img_size.y);
	game->exit_img = mlx_xpm_file_to_image(game->mlx, "assets/Exit.xpm", &game->img_size.x, &game->img_size.y);
}

// MISSING: Open wall images
// MISSING: Open collect images
// MISSING: Open enemy images
// MISSING: Open door images

void	init_images(t_game *game)
{
	open_player(game);
}