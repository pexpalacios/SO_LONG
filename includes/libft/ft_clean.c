/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_clean.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: penpalac <penpalac@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/23 16:03:02 by penpalac          #+#    #+#             */
/*   Updated: 2025/09/23 16:14:40 by penpalac         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

// Memory cleaning and errors, not part of the basic libft, added for bigger projects

#include "libft.h"

void	free_matrix(char **mtx)
{
	int i = 0;

	while(mtx[i])
	{
		free(mtx[i]);
		i++;
	}
	free(mtx);
}