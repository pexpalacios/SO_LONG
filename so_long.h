/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: penpalac <penpalac@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/28 10:01:44 by penpalac          #+#    #+#             */
/*   Updated: 2025/09/25 16:04:23 by penpalac         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SO_LONG_H
# define SO_LONG_H

# include "libft/libft.h"
# include "mlx/mlx.h"
# include "mlx/mlx_int.h"
# include <errno.h>
# include <fcntl.h>
# include <stdlib.h>
# include <string.h>
# include <sys/stat.h>
# include <sys/types.h>
# include <unistd.h>

# ifndef WIN_HEIGHT
#  define WIN_HEIGHT 2048
# endif

# ifndef WIN_WIDTH
#  define WIN_WIDTH 2048
# endif

# ifndef TILE_SIZE
#  define TILE_SIZE 64
# endif

// KEYS //
# define K_ESC 65307
# define K_A 97
# define K_D 100
# define K_S 115
# define K_W 119

// COLORS //
#define	WHITE	"\033[0m"
#define	RED		"\033[1;31m"
#define	GREEN	"\033[1;32m"
#define	YELLOW	"\033[1;33m"
#define	BLUE	"\033[1;34m"
#define	PURPLE	"\033[1;35m"

// STRUCTS //
typedef struct s_tile
{
	int				tile_x;
	int				tile_y;
	char			*img;
	char			*addr;
	int				bits;
	int				size_line;
	int				endian;
}					t_tile;

typedef struct s_player
{
	char			*player;
	int				player_x;
	int				player_y;
	int				cont_moves;
	int				items;
}					t_player;

typedef struct s_map
{
	char			**map;
	int				map_x;
	int				map_y;
	int				titems;
	int				citems;
	int				cexit;
	int				cplayer;
	int				lenline;
	int				lencol;
}					t_map;

typedef struct s_game
{
	struct s_player	player;
	struct s_tile	pc;
	struct s_tile	item;
	struct s_tile	exit;
	struct s_tile	wall;
	struct s_tile	floor;
	struct s_map	map;
	void			*mlx;
	void			*window;
	void			*img;
	char			*addr;
	int				window_x;
	int				window_y;
	int				bits;
	int				len;
	int				endian;
}					t_game;

// MAIN
void				start_game(t_game *game);
t_game				*valid_map(char *map, t_game *game);

// CHECK_VALID
int					check_ber(char *map);
t_game				*map_init(char *map, t_game *game);
int					check_map(t_game *game);

// CHECK_MAP
int					is_rect(t_game *game);
int					is_closed(t_game *game);
int					has_chars(t_game *game);
int					check_char(char c, t_game *game);
int					put_chars(t_game *game);

// MAKE_MAP
void				read_map(char *map, t_game *game);
char				**fill_map(char *map, t_game *game, char **maparr);
void				draw_map(t_game *game);
void				get_tiles(t_game *game, int x, int y);

// PARSE_MAP
int					has_path(t_game *game);
void				flooder(t_game *game, t_map size, t_player pos,
						char to_fill);
void				flood_fill(t_game *game, t_map size, t_player pos);
int					check_access(t_game *game, int item_check, int exit_check);

// XMP_LOADERS
int					xpm_check(t_game *game);
t_game				*get_xmp_image(t_game *game);
int					get_xmp_address(t_game *game);
int					open_exit(t_game *game);

// MOVEMENT
int					key_input(int keycode, t_game *game);
void				move_up(t_game *game);
void				move_down(t_game *game);
void				move_left(t_game *game);
void				move_right(t_game *game);

// EXTRAS
void				victory(t_game *game);
void				move_counter(t_game *game, int mov);
void				call_error(t_game *game, char *str);

// CLOSE_GAME
void				map_destroyer(t_game *game);
void				img_destroyer(t_game *game);
int					close_game(t_game *game);

// STRUCTS
int					init_game_structs(t_game *game);
int					init_game_display(t_game *game);
int					init_char(t_game *game);
int					init_map(t_game *game);
int					init_tile(t_game *game);
int					init_tile_player(t_game *game);
int					init_tile_item(t_game *game);
int					init_tile_exit(t_game *game);
int					init_tile_floor(t_game *game);
int					init_tile_wall(t_game *game);

#endif
