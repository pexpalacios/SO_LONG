/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   xmp.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: penpalac <penpalac@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/25 17:01:59 by penpalac          #+#    #+#             */
/*   Updated: 2025/09/30 18:44:37 by penpalac         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/so_long.h"

void	load_images(t_game *game)
{
	game->floor->image = mlx_xpm_file_to_image(game->mlx, "../textures/0_floor.xpm", 
		&game->floor->bpp, &game->floor->size_line);
	game->wall->image = mlx_xpm_file_to_image(game->mlx, "../textures/1_wall.xpm", 
		&game->wall->bpp, &game->wall->size_line);
	game->player->image = mlx_xpm_file_to_image(game->mlx, "../textures/P_player.xpm", 
		&game->player->bpp, &game->player->size_line);
	game->item->image = mlx_xpm_file_to_image(game->mlx, "../textures/C_item.xpm", 
		&game->item->bpp, &game->item->size_line);
	game->exit->image = mlx_xpm_file_to_image(game->mlx, "../textures/E_exit_closed.xpm", 
		&game->exit->bpp, &game->exit->size_line);
	
	if (!game->floor->image || game->wall->image || !game->player->image || !game->item->image || !game->exit->image)
	{
		img_cleaner(game);
		close_game(game, 1, "Error: couldn't load images");
	}

	game->floor->data = mlx_get_data_addr(&game->floor->image, &game->floor->bpp, 
		&game->floor->size_line, &game->floor->image->byte_order);
	game->wall->data = mlx_get_data_addr(&game->wall->image, &game->wall->bpp, 
		&game->wall->size_line, &game->wall->image->byte_order);
	game->player->data = mlx_get_data_addr(&game->player->image, &game->player->bpp, 
		&game->player->size_line, &game->player->image->byte_order);
	game->item->data = mlx_get_data_addr(&game->item->image, &game->item->bpp, 
		&game->item->size_line, &game->item->image->byte_order);
	game->exit->data = mlx_get_data_addr(&game->exit->image, &game->exit->bpp, 
		&game->exit->size_line, &game->exit->image->byte_order);
	
}

int	open_exit(t_game *game)
{
	game->exit->image = mlx_xpm_file_to_image(game->mlx, "../textures/E_exit_opened.xpm", 
		&game->exit->bpp, &game->exit->size_line);
	game->exit->data = mlx_get_data_addr(&game->exit->image, &game->exit->bpp, 
		&game->exit->size_line, &game->exit->image->byte_order);

	int i = 0;
	while ()
	mlx_put_image_to_window(game->mlx, game->window, game->exit->image,
		game->exit. * TILE_SIZE, game->exit.tile_y * TILE_SIZE);
	ft_printf("Se ha abierto la salida!\n");
	return (1);
}