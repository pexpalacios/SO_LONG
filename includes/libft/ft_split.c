/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: penpalac <penpalac@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/22 17:18:50 by penpalac          #+#    #+#             */
/*   Updated: 2025/09/23 16:05:10 by penpalac         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

// This function is too long, it's implemented in a separate file so the string one doesn't get too confusing

#include "libft.h"

static int	countwords(char const *s, char c);

// Splits a char* into a char** using char 'c' as the mark
char	**ft_split(char const *s, char c)
{
	char	**strs;
	int		words = countwords(s, c);
	int		start = 0;

	if (!s)
		return (NULL);
	strs = (char **)malloc ((words + 1) * sizeof(char *));
	if (!strs)
		return (NULL);
	int i = 0;
	int j = 0;
	while (s[i])
	{
		while (s[i] != '\0' && (s[i] == c)) //gets rid of nulls and the mark to get the star of a char*
			i++;
		start = i;
		while (s[i] != '\0' && !(s[i] == c)) //counts the length the char* will have
			i++;
		if (i > start) //fills strs[j] with the extracted char*
		{
			int k = 0;
			strs[j] = (char *)malloc(((i - start) + 1) * sizeof(char));
			if (!strs[j])
			{
				free_matrix(strs);
				return (NULL);
			}
			while (k < (i - start))
			{
				strs[j][k] = s[start + i];
				k++;
			}
			strs[j][k] = '\0';
		}
		j++;
	}
	strs[j] = NULL;
	return (strs);
}

// Helps count the amount of char* the new matrix will have
static int	countwords(char const *s, char c)
{
	int	i;
	int	count;

	i = 0;
	count = 0;
	while (s[i])
	{
		while (s[i] && s[i] == c)
			i++;
		if (s[i] && s[i] != c)
		{
			count++;
			while (s[i] && s[i] != c)
				i++;
		}
	}
	return (count);
}
