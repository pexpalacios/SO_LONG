/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_convert.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: penpalac <penpalac@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/22 16:52:24 by penpalac          #+#    #+#             */
/*   Updated: 2025/09/22 19:34:42 by penpalac         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

// Converts an integer to lowercase
int	ft_tolower(int c)
{
	if (c >= 65 && c <= 90)
		return (c + 32);
	else
		return (c);
}

// Converts an integer to uppercase
int	ft_toupper(int c)
{
	if (c >= 97 && c <= 122)
		return (c - 32);
	else
		return (c);
}

// Converts a char* to integer. Skips spaces and takes one sign into consideration
int	ft_atoi(const char *nptr)
{
	int	result = 0;
	int	sign = 1;
	int	i = 0;

	while (nptr[i] == ' ' || ((nptr[i] >= 9) && (nptr[i] <= 13)))
		i++;
	if (nptr[i] == '+' || nptr[i] == '-')
	{
		if (nptr[i] == '-')
			sign *= -1;
		i++;
	}
	while (nptr[i] && (nptr[i] >= 48 && nptr[i] <= 57))
	{
		result = (result * 10) + (nptr[i] - 48);
		i++;
	}
	return (result * sign);
}

// Converts an integer to a string (char*)
int get_length(int n);

char	*ft_itoa(int n)
{
	int		sign = 1;
	int		len = get_length(n);
	char	*nbr = (char *)malloc((len + 1) * sizeof(char));
	if (!nbr)
		return (NULL);

	if(n < 0)
	{
		sign = -1;
		n *= -1;
		len++;
	}
	nbr[0] = '-';
	nbr[len] = '\0';
	while ((len - 1) >= 0)
	{
		nbr[len - 1] = (n % 10) + '0';
		n /= 10;
		len--;
	}
	return (nbr);
}

int		get_length(int n)
{
	int i;

	if (n == 0)
		return (1);
	i = 0;
	while (n != 0)
	{
		n /= 10;
		i++;
	}
	return (i);
}
