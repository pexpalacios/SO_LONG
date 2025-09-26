/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: penpalac <penpalac@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/25 16:16:21 by penpalac          #+#    #+#             */
/*   Updated: 2025/09/26 15:56:20 by penpalac         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/so_long.h"

int	check_ext(char *map)
{
	char	*name_end;
	char	*ext;

	ext = ".ber";
	name_end = ft_substr(map, (ft_strlen(map) - 4), 4);
	if (ft_strncmp(name_end, ext, ft_strlen(name_end)) != 0)
	{
		free(name_end);
		return (0);
	}
	free(name_end);
	return (1);
}

int	main(int ac, char **av)
{
	//argument check
	if (ac != 2)
		perror("Invalid number of arguments");
	//check if it's .ber
	if (check_ext(av[1]))
		perror("File extension must be .ber");
	if (!parse_map(av[1]))
		return (1);
	init_game(av[1]);
	return (0);
}