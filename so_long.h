/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zwong <zwong@student.42kl.edu.my>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/13 10:41:29 by zwong             #+#    #+#             */
/*   Updated: 2022/10/13 10:45:16 by zwong            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SO_LONG_H
# define SO_LONG_H
# define IMG_SIZE 32

# include <mlx.h>
# include <stdlib.h>
# include <fcntl.h>
# include "libft/libft.h"

enum e_keycode
{
	KEY_UP = 13,
	KEY_DOWN = 1,
	KEY_LEFT = 0,
	KEY_RIGHT = 2,
	ARROW_UP = 126,
	ARROW_DOWN = 125,
	ARROW_LEFT = 123,
	ARROW_RIGHT = 124,
	RESET = 15,
	ESC = 53
};

typedef enum e_tiletype {
	EMPTY = '0',
	WALL = '1',
	COLLECTIBLE = 'C',
	PLAYER = 'P',
	EXIT = 'E',
	ENEMY = 'X',
}	t_tiletype;

typedef struct s_vector {
	int	x;
	int	y;
}	t_vector;

typedef struct s_tile {
	t_tiletype		type;
	t_tiletype		prev_type;
	t_vector		pos;
	struct s_tile	*up;
	struct s_tile	*down;
	struct s_tile	*left;
	struct s_tile	*right;
}	t_tile;

typedef struct s_player {
	void	*img;
	void	*right_img;
	void	*left_img;
	void	*slash_img;
	t_tile	*tile;
	int		img_width;
	int		img_height;
}	t_player;

typedef struct s_enemy {
	void	*img;
	void	*right_img;
	void	*left_img;
	void	*slash_img;
	t_tile	*tile;
	int		img_width;
	int		img_height;
}	t_enemy;

typedef struct s_map {
	int	exit_num;
	int	start_num;
	int	enemy_num;
	int	collect_num;
	int	invalid_char;
}	t_map;

typedef struct s_game {
	void		*mlx;
	void		*win;
	t_map		*map_vars;
	t_tile		**tilemap;
	t_vector	win_size;
	t_vector	img_size;
	t_player	player;
	t_enemy		enemy;
	void		*wall_img;
	void		*background_img;
	void		*collectible_img;
	void		*exit_img;
	void		*exit_img1;
	void		*exit_img2;
	int			moves;
}	t_game;

void	my_mlx_pixel_put(t_player *data, int x, int y, int color);
char	**read_map(char *file);
void	valid_file(int argc, char *filename);
char	*valid_map(t_game *game, char **map);
void	*my_xpm_to_img(t_game *game, char *str);
t_tile	**init_tiles(char **map, t_game *game);
int		input(int keycode, t_game *game);
int		render(t_game *game);
int		end_program(t_game *game);
void	putstr_fd_exit(char *err);
void	err_exit(char *err);
void	free_map(char **map);
void	free_tilemap(t_tile **tilemap);

#endif