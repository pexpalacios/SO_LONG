/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cleaners.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: penpalac <penpalac@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/25 16:16:50 by penpalac          #+#    #+#             */
/*   Updated: 2025/09/25 17:26:32 by penpalac         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/so_long.h"

//clean structs
void	img_cleaner(t_game *game)
{
	
}

//close game
void	close_game(t_game *game, int error, char *str)
{
	mlx_destroy_window(game->mlx, game->window);
	mlx_destroy_display(game->mlx);
	free(game->mlx);
	if (error)
	{
		perror(str);
		exit(EXIT_FAILURE);
	}
	else
	{
		ft_printf("%s", str);
		exit(EXIT_SUCCESS);
	}
}

//error message