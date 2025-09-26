/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_game.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: penpalac <penpalac@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/25 16:16:27 by penpalac          #+#    #+#             */
/*   Updated: 2025/09/26 16:47:24 by penpalac         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/so_long.h"

//after parse is okay
void init_game(char *arg)
{
	t_game *game = ft_calloc(sizeof(t_game), sizeof(t_game));
	t_player *player = ft_calloc(sizeof(t_player), sizeof(t_player));

	game->mlx = mlx_init();
	
	game->map = ft_split(arg, '\n');
	int map_height = 0;
	while (game->map[map_height])
		map_height++;
	int map_length = 0;
	while (game->map[0][map_length])
		map_length++;
	game->window = mlx_new_window(game->mlx, map_length * TILE_SIZE, map_height * TILE_SIZE, "So_long");

	load_images(game);
	draw_map(game, player, map_length, map_height);
	start_game_loop(game, player);
}

//create map
void	draw_map(t_game *game, t_player *player, int length, int height)
{
	int i = 0;

	while (i < height)
	{
		int j = 0;
		while (j < length)
		{
			if (game->map[i][j] == '1')
				mlx_put_image_to_window(game->mlx, game->window, game->wall->image, i * TILE_SIZE, j * TILE_SIZE);
			else if (game->map[i][j] == '0')
				mlx_put_image_to_window(game->mlx, game->window, game->floor->image, i * TILE_SIZE, j * TILE_SIZE);
			else if (game->map[i][j] == 'P')
			{
				mlx_put_image_to_window(game->mlx, game->window, game->player->image, i * TILE_SIZE, j * TILE_SIZE);
				player->posx = j;
				player->posy = i;
			}
			else if (game->map[i][j] == 'C')
				mlx_put_image_to_window(game->mlx, game->window, game->item->image, i * TILE_SIZE, j * TILE_SIZE);
			else if (game->map[i][j] == 'E')
				mlx_put_image_to_window(game->mlx, game->window, game->exit->image, i * TILE_SIZE, j * TILE_SIZE);
			j++;
		}
		i++;
	}
}

//start game loop
void	start_game_loop(t_game *game, t_player *player)
{
	game->items = 0;
	game->steps = 0;
	//mlx_key_hook(game->window, key_input, game);
	mlx_hook(game->window, ClientMessage, LeaveWindowMask, close_game, game);
	mlx_hook(game->window, 2, 1L << 0, key_press, game);
	mlx_hook(game->window, 3, 1L << 1, key_release, game);
	mlx_loop(game->mlx);
}
