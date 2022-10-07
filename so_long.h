#ifndef SO_LONG_H
# define SO_LONG_H
# define IMG_SIZE 128

# include <mlx.h>
# include <stdio.h>
# include <stdlib.h>
# include <fcntl.h>
# include "libft/libft.h"


typedef enum	e_tiletype {
	EMPTY = '0',
	WALL = '1',
	COLLECTABLE = 'C',
	PLAYER = 'P',
	EXIT = 'E',
	ENEMY = 'M',
	FOLLOWER = 'F'
}	t_tiletype;

typedef struct s_vector {
	int	x;
	int	y;
}	t_vector;

typedef struct	s_tile {
	t_tiletype		type;
	t_vector		pos;
	struct s_tile	*up;
	struct s_tile	*down;
	struct s_tile	*left;
	struct s_tile	*right;
}	t_tile;

typedef struct	s_player {
	void	*img;
	t_tile	*tile;
	char	*addr;
	int		bits_per_pixel;
	int		line_length;
	int		endian;
	int		img_width;
	int		img_height;
}	t_player;

typedef struct	s_game {
	void		*mlx;
	void		*win;
	t_tile		**tilemap;
	t_vector	win_size;
	t_vector	img_size;
	t_player	player;
	void		*panel;
}	t_game;

enum e_keycode
{
	KEY_UP = 13,
	KEY_DOWN = 1,
	KEY_LEFT = 0,
	KEY_RIGHT = 2,
	RESET = 15,
	ESC = 53
};

void	my_mlx_pixel_put(t_player *data, int x, int y, int color);
int	input(int keycode, t_game *game);
int	mouse(int x, int y, t_game *game);
void	err_exit(char *err);
char	**read_map(char *file);
t_tile	**init_tiles(char **map, t_game *game);
void	init_images(t_game *game);
int	render(t_game *game);

#endif