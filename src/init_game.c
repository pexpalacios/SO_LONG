/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_game.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: penpalac <penpalac@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/25 16:16:27 by penpalac          #+#    #+#             */
/*   Updated: 2025/09/25 17:27:51 by penpalac         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/so_long.h"

//after parse is okay
void init_game(char *arg)
{
	t_game *game = ft_calloc(sizeof(t_game), sizeof(t_game));
	
	game->mlx = mlx_init();
	
	game->map = ft_split(arg, '\n');
	int map_length = 0;
	while (game->map[0][map_length])
		map_length++;
	int map_height = 0;
	while (game->map[map_height])
		map_height++;
	game->window = mlx_new_window(game->mlx, map_length * TILE_SIZE, map_height * TILE_SIZE, "So_long");

	load_images(game);
	draw_map(game);
	//game loop -> key_hook(movement), mlx_hook, mlx_loop
}

//create map
void	draw_map(t_game *game)
{
	
}

//start game loop