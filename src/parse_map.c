/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_map.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: penpalac <penpalac@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/25 16:14:59 by penpalac          #+#    #+#             */
/*   Updated: 2025/09/25 16:25:58 by penpalac         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/so_long.h"

// in map[i][j]: i is the number or rows(height) and j the number of columns(length)

//Master function that calls the different checks
int parse_map(char *arg)
{
	char **map = ft_split(arg, '\n');

	if (!map_is_valid(map))
		return (0);
	if (!has_correct_characters(map))
		return (0);
	if (!right_nb_of_characters(map))
		return (0);
	if (!available_path(map))
		return (0);
	return (1);
}

//Checks if the map is rectangular and if it is closed by walls (1)
int map_is_valid(char **map)
{
	int length = 0, height = 0, i = 0, j = 0;

	while (map[0][length] && map[0][length] != '\n')
		length++;
	while (map[height])
		height++;
	//Check if the rows are the same length as the first
	while (map[i])
	{
		j = 0;
		while (map[i][j] && (map[i][j] != '\n'))
			j++;
		if (j != length)
		{
			perror("Map is not rectangular");
			return (0);
		}
		i++;
	}
	//Check if all the sides are closed by '1's
	i = 0;
	while (i < height)
	{
		if (map[i][0] != '1' || map[i][length - 1] != '1')
		{
			perror("Map is not closed");
			return (0);
		}	
		i++;
	}
	j = 0;
	while (j < length)
	{
		if (map[0][j] != '1' || map[height - 1][j] != '1')
		{
			perror("Map is not closed");
			return (0);
		}	
		j++;
	}
	return (1);
}

//Checks if there's any characters that aren't valid (1, 0, P, E, C)
int has_correct_characters(char **map)
{
	int length = 0, height = 0, i = 0, j = 0;
	char *valid = "01PEC";

	while (map[0][length] && map[0][length] != '\n')
		length++;
	while (map[height])
		height++;

	while (i < height)
	{
		j = 0;
		while (j < length)
		{
			if (!ft_strchr(valid, map[i][j]))
			{
				perror("Map contains invalid characters");
				return (0);
			}
			j++;
		}
		i++;
	}
	return (1);
}

// Checks the number of special characters so there's no more than one P and E
// and that there's at least one C
int right_nb_of_characters(char **map)
{
	int nb_p = 0, nb_e = 0, nb_c = 0;
	int length = 0, height = 0, i = 0, j = 0;

	while (map[0][length] && map[0][length] != '\n')
		length++;
	while (map[height])
		height++;
	
	while (i < height)
	{
		j = 0;
		while (j < length)
		{
			if (map[i][j] == 'P')
				nb_p++;
			if (map[i][j] == 'E')
				nb_e++;
			if (map[i][j] == 'C')
				nb_c++;
			j++;
		}
		i++;
	}
	if (nb_p > 1 || nb_p <= 0)
	{
		perror("Number of character P invalid: must be 1");
		return (0);
	}
	if (nb_e > 1 || nb_e <= 0)
	{
		perror("Number of character E invalid: must be 1");
		return (0);
	}
	if (nb_c <= 0)
	{
		perror("Number of character C invalid: must be at least 1");
		return (0);
	}
	return (1);	
}

//pathfinder
int available_path(char **map)
{
	
	return (1);
}