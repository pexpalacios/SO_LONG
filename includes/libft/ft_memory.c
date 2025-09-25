/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memory.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: penpalac <penpalac@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/22 16:21:08 by penpalac          #+#    #+#             */
/*   Updated: 2025/09/22 16:45:42 by penpalac         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

// Functions that help with memory management

#include "libft.h"

// Copies 'src' into 'dest' for 'n' bytes and returns the copy
void	*ft_memcpy(void *dest, const void *src, size_t n)
{
	char	*memdst = (char *)dest;
	char	*memsrc = (char *)src;
	size_t	i = 0;

	if (!memdst && !memsrc)
		return (memdst);
	while (i < n)
	{
		memdst[i] = memsrc[i];
		i++;
	}
	return (memdst);
}

//Finds the first instance of 'c' in the memory pointed to by 's' in 'n' bytes
void	*ft_memchr(const void *s, int c, size_t n)
{
	char	*ch = (char *)s;
	size_t	i = 0;
	c = (char)c;

	while (i < n)
	{
		if (ch[i] == c)
			return (&ch[i]);
		i++;
	}
	return (NULL);
}

//Compares two strings and returns a positive value if s1 is bigger, a negative is s2 is bigger or 0 if they are the same
int	ft_memcmp(const void *s1, const void *s2, size_t n)
{
	unsigned char	*new_s1 = (unsigned char *)s1;
	unsigned char	*new_s2 = (unsigned char *)s2;
	size_t			i = 0;

	while (i < n)
	{
		if (new_s1[i] != new_s2[i])
			return (new_s1[i] - new_s2[i]);
		i++;
	}
	return (0);
}

// Moves 'src' into 'dest' for 'n' bytes and returns a pointer to 'dest'. Handles overlapping memory
void	*ft_memmove(void *dest, const void *src, size_t n)
{
	char	*new_dest = (char *)dest;
	char	*new_src = (char *)src;

	if (!dest && !src)
		return (NULL);
	if (new_dest < new_src || new_dest >= new_src + n)
	{
		while (n--)
			*new_dest++ = *new_src++;
	}
	else
	{
		new_dest += n;
		new_src += n;
		while (n--)
			*(--new_dest) = *(--new_src);
	}
	return (dest);
}

// Fills the memory space pointed to by 's' with int c for 'n' bytes
void	*ft_memset(void *s, int c, size_t n)
{
	char	*cast = (char *)s;
	size_t	i = 0;

	while (i < n)
	{
		cast[i] = c;
		i++;
	}
	return (cast);
}

// Fills the memory space pointed to by 's' with 0 for 'n' bytes
void	ft_bzero(void *s, size_t n)
{
	char	*str = (char *)s;
	size_t	i = 0;

	while (i < n)
	{
		str[i] = 0;
		i++;
	}
}

// Creates a memory space of 'mem' amount of elements, which are as big as 'size', and fills them with 0
void	*ft_calloc(size_t mem, size_t size)
{
	unsigned char	*ptr = (unsigned char *)malloc(mem * size);
	size_t			i = 0;

	if (!ptr)
		return (NULL);
	while (i < (mem * size))
	{
		ptr[i] = 0;
		i++;
	}
	return (ptr);
}