/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: penpalac <penpalac@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/22 18:54:02 by penpalac          #+#    #+#             */
/*   Updated: 2025/09/22 18:54:05 by penpalac         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_putchar(char c, int counter);
int	ft_putstr(char *s, int counter);
int	ft_putnbr(signed int n, int counter);
int	ft_putunsnbr(unsigned int n, int counter);
int	ft_puthex(unsigned int nbr, char *base, int counter);
int	ft_putptr(unsigned long long n, char *base, int counter, int flag);

// Main body of the printf function. Determines what character is after the percentage to know what value to put in its place
// Subject only asked to do %c(char) %s(string) %d(digit) %i(int) %u(unsigned int) %p(void pointer) %x(hexadecimal in lowercase)
// %X(hexadecimal in uppercase) and %%
int	ft_printf(const char *format, ...)
{
	va_list	arg;
	int	counter = 0;
	int	i = 0;

	va_start(arg, format);
	while (format[i])
	{
		if (format[i] == '%' && format[i + 1] != '\0')
		{
			i++;
			if (format[i] == 'd' || format[i] == 'i')
				counter = ft_putnbr(va_arg(arg, int), counter);
			else if (format[i] == 'u')
				counter = ft_putunsnbr(va_arg(arg, int), counter);
			else if (format[i] == 'c')
				counter = ft_putchar(va_arg(arg, int), counter);
			else if (format[i] == 's')
				counter = ft_putstr(va_arg(arg, char *), counter);
			else if (format[i] == 'p')
				counter = ft_putptr(va_arg(arg, unsigned long), "0123456789abcdef",
						counter, 1);
			else if (format[i] == 'x')
				counter = ft_puthex(va_arg(arg, unsigned int), "0123456789abcdef",
						counter);
			else if (format[i] == 'X')
				counter = ft_puthex(va_arg(arg, int), "0123456789ABCDEF", counter);
			else if (format[i] == '%')
				counter = ft_putchar('%', counter);
		}
		else
			counter = ft_putchar(format[i], counter);
		i++;
	}
	va_end(arg);
	return (counter);
}

// This put functions differentiate themselves from the put_fd ones because of the counter they have
int	ft_putchar(char c, int counter)
{
	write (1, &c, 1);
	counter++;
	return (counter);
}

int	ft_putstr(char *s, int counter)
{
	if (!s)
	{
		counter = ft_putstr("(null)", counter);
		return (counter);
	}

	int i = 0;
	while (s[i])
	{
		write (1, &s[i], 1);
		i++;
		counter++;
	}
	return (counter);
}

int	ft_putnbr(signed int n, int counter)
{
	char	c;

	if (n == -2147483648)
		counter = ft_putstr("-2147483648", counter);
	else
	{
		if (n < 0)
		{
			counter = ft_putchar ('-', counter);
			n *= -1;
			counter = ft_putnbr (n, counter);
		}
		else if (n > 9)
		{
			counter = ft_putnbr (n / 10, counter);
			counter = ft_putnbr (n % 10, counter);
		}
		else
		{
			c = '0' + n;
			write (1, &c, 1);
			counter++;
		}
	}
	return (counter);
}

int	ft_putunsnbr(unsigned int n, int counter)
{
	char	c;

	if (n > 9)
	{
		counter = ft_putnbr (n / 10, counter);
		counter = ft_putnbr (n % 10, counter);
	}
	else
	{
		c = '0' + n;
		write (1, &c, 1);
		counter++;
	}
	return (counter);
}

//This function works with a base so it could technically write numbers in more bases than hex
int	ft_puthex(unsigned int nbr, char *base, int counter)
{
	long	size = ft_strlen(base);
	long	num = nbr;

	if (num >= size)
		counter = ft_puthex (num / size, base, counter);
	write(1, &base[num % size], 1);
	counter++;
	return (counter);
}

int	ft_putptr(unsigned long long n, char *base, int counter, int flag)
{
	if (!n)
	{
		counter = ft_putstr ("(nil)", counter);
		return (counter);
	}

	unsigned long long num = n;
	unsigned long long size = ft_strlen (base);
	if (flag)
		counter = ft_putstr ("0x", counter);
	if (num < 0)
		num *= -1;
	if (num >= size)
		counter = ft_putptr (n / size, base, counter, 0);
	write(1, &base[num % size], 1);
	counter++;
	return (counter);
}