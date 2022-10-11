#ifndef SO_LONG_H
# define SO_LONG_H
# define IMG_SIZE 32

# include <mlx.h>
# include <stdio.h>
# include <stdlib.h>
# include <fcntl.h>
# include "libft/libft.h"

enum e_keycode
{
	KEY_UP = 13,
	KEY_DOWN = 1,
	KEY_LEFT = 0,
	KEY_RIGHT = 2,
	RESET = 15,
	ESC = 53
};

typedef enum	e_tiletype {
	EMPTY = '0',
	WALL = '1',
	COLLECTIBLE = 'C',
	PLAYER = 'P',
	EXIT = 'E',
}	t_tiletype;

typedef struct s_vector {
	int	x;
	int	y;
}	t_vector;

typedef struct	s_tile {
	t_tiletype		type;
	t_tiletype		prev_type;
	t_vector		pos;
	struct s_tile	*up;
	struct s_tile	*down;
	struct s_tile	*left;
	struct s_tile	*right;
}	t_tile;

typedef struct	s_player {
	void	*img;
	t_tile	*tile;
	int		img_width;
	int		img_height;
}	t_player;

typedef struct	s_map {
	int	exitNum;
	int	startNum;
	int	collectNum;
	int	invalidChar;
}	t_map;

typedef struct	s_game {
	void		*mlx;
	void		*win;
	t_map		*map_vars;
	t_tile		**tilemap;
	t_vector	win_size;
	t_vector	img_size;
	t_player	player;
	void		*wall_img;
	void		*background_img;
	void		*collectible_img;
	void		*exit_img;
	int			moves;
}	t_game;

void	my_mlx_pixel_put(t_player *data, int x, int y, int color);
char	**read_map(char *file);
void	valid_file(int argc, char *filename);
char	*valid_map(t_game *game, char **map);
void	init_images(t_game *game);
void	init_background(t_game *game);
t_tile	**init_tiles(char **map, t_game *game);
int		input(int keycode, t_game *game);
int		render(t_game *game);
int		end_program(t_game *game);
void	putstr_fd_exit(char *err);
void	err_exit(char *err);
void	free_map(char **map);
void	free_tilemap(t_tile **tilemap);

#endif