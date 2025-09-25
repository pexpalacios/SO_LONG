/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_put.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: penpalac <penpalac@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/22 17:15:35 by penpalac          #+#    #+#             */
/*   Updated: 2025/09/22 19:22:39 by penpalac         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

// Functions that write in a passed file descriptor

#include "libft.h"

// Writes a character in a file descriptor
void	ft_putchar_fd(char c, int fd)
{
	write (fd, &c, 1);
}

// Writes a string in a file descriptor
void	ft_putstr_fd(char *s, int fd)
{
	int	i = 0;

	while (s[i])
	{
		write (fd, &s[i], 1);
		i++;
	}
}

// Writes a string in a file descriptor and ends in with a new line
void	ft_putendl_fd(char *s, int fd)
{
	int	i = 0;

	while (s[i])
	{
		write (fd, &s[i], 1);
		i++;
	}
	write (fd, "\n", 1);
}

// Writes a number in a file descriptor
void	ft_putnbr_fd(int n, int fd)
{
	char	c;

	if (n == -2147483648)
		write(fd, "-2147483648", 11);
	else
	{
		if (n < 0)
		{
			write (fd, "-", 1);
			n *= -1;
			ft_putnbr_fd(n, fd);
		}
		else if (n > 9)
		{
			ft_putnbr_fd (n / 10, fd);
			ft_putnbr_fd (n % 10, fd);
		}
		else
		{
			c = '0' + n;
			write (fd, &c, 1);
		}
	}
}