/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   game_loop.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: penpalac <penpalac@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/25 16:16:38 by penpalac          #+#    #+#             */
/*   Updated: 2025/09/30 18:42:03 by penpalac         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/so_long.h"

//movement
void	key_press(t_game *game, int key, t_player *player)
{
	if (key == K_ESC)
		close_game(game, 0, "ESC pressed. Buh bye!");
	else if (key == K_W || key == A_UP)
		game->key_w = 1; //this should make it so it can be pressed
	else if (key == K_A || key == A_LF)
		game->key_a = 1;
	else if (key == K_S || key == A_DW)
		game->key_s = 1;
	else if (key == K_D || key == A_RG)
		game->key_d = 1;
	move_player(game, player);
}

void	key_release(t_game *game, int key,  t_player *player)
{
	if (key == K_ESC)
		close_game(game, 0, "ESC pressed. Buh bye!");
	else if (key == K_W || key == A_UP)
		game->key_w = 0;
	else if (key == K_A || key == A_LF)
		game->key_a = 0;
	else if (key == K_S || key == A_DW)
		game->key_s = 0;
	else if (key == K_D || key == A_RG)
		game->key_d = 0;
	move_player(game, player);
}

void	move_player(t_game *game, t_player *player)
{
	int	next_tile;

	// set next tile depending on direction
	if (game->key_a)
		next_tile = game->map[player->posx][player->posy - 1];
	else if (game->key_d)
		next_tile = game->map[player->posx][player->posy + 1];
	else if (game->key_w)
		next_tile = game->map[player->posx - 1][player->posy];
	else if (game->key_s)
		next_tile = game->map[player->posx + 1][player->posy];
	if (next_tile != '1')
	{
		game->steps++;
		if (next_tile == 'C' || next_tile == 'P' || next_tile == '0')
		{
			if (next_tile == 'C')
			{
				game->items++;
				if (game->items == game->total_items)
					open_exit(game);
			}
			// change player's position to floor and next tile to player
			mlx_put_image_to_window(game->mlx, game->window, game->player->image,
				player->posx * TILE_SIZE, (player->posy - 1) * TILE_SIZE);
			mlx_put_image_to_window(game->mlx, game->window, game->floor->image,
				player->posx * TILE_SIZE, player->posy * TILE_SIZE);
			// change map[posx][posy] to 0
			// if next tile is c -> items++
			// if enogh items -> open exit
		}
		// if next tile e and all items complete -> victory
	}
}


