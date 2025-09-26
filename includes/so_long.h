/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: penpalac <penpalac@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/28 10:01:44 by penpalac          #+#    #+#             */
/*   Updated: 2025/09/26 17:28:52 by penpalac         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SO_LONG_H
# define SO_LONG_H

# include "libft/libft.h"
# include "mlx/mlx.h"
# include "mlx/mlx_int.h"
# include <errno.h>
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
# define A_UP 65362
# define A_DW 65364
# define A_LF 65361
# define A_RG 65363

// COLORS //
#define	WHITE	"\033[0m"
#define	RED		"\033[1;31m"
#define	GREEN	"\033[1;32m"
#define	YELLOW	"\033[1;33m"
#define	BLUE	"\033[1;34m"
#define	PURPLE	"\033[1;35m"

// STRUCTS //
typedef struct s_game
{
	void	*mlx;
	void	*window;

	char	**map;

	t_img	*floor;
	t_img	*wall;
	t_img	*player;
	t_img	*item;
	t_img	*exit;

	int	steps;
	int	items;
	
	int key_w;
	int key_a;
	int key_s;
	int key_d;
	
}	t_game;

typedef struct s_player
{
	int posx;
	int posy;

}	t_player;

// MAIN
int	check_ext(char *map);

// PARSE_MAP
int	parse_map(char *arg);
int	map_is_valid(char **map);
int	has_correct_characters(char **map);
int	right_nb_of_characters(char **map);
int	available_path(char **map);

// INIT_GAME
void	init_game(char *arg);
void	load_images(t_game *game);
void	draw_map(t_game *game, int length, int height);
void	start_game_loop(t_game *game);
// GAME_LOOP
void	key_press(t_game *game, int key, t_player *player);
void	key_release(t_game *game, int key,  t_player *player);
void	move_player(t_game *game, t_player *player);

// CLEANERS
void	img_cleaner(t_game *game);
void	close_game(t_game *game, int error, char *str);

#endif
