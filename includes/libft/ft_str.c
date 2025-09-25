/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_str.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: penpalac <penpalac@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/22 17:16:34 by penpalac          #+#    #+#             */
/*   Updated: 2025/09/22 19:37:43 by penpalac         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

// Functions that manage strings

#include "libft.h"

// Gets the length of a passed string
size_t	ft_strlen(const char *s)
{
	size_t	i = 0;

	while (s[i])
		i++;
	return (i);
}

// Compares two strings and returns a positive value if s1 is bigger, a negative value if s2 is bigger or 0 if they are the same
int	ft_strncmp(char *s1, char *s2, size_t n)
{
	size_t	i = 0;

	while (i < n)
	{
		if (s1[i] != s2[i])
			return (s1[i] - s2[i]);
		if (s1[i] == '\0' || s2[i] == '\0')
			i = n + 1;
		i++;
	}
	return (0);
}

// Copies a string 'src' into a string 'dst' for 'size' bytes and returns the length of the copy
size_t	ft_strlcpy(char *dst, const char *src, size_t size)
{
	size_t	srcsize = 0;

	while (src[srcsize] != '\0')
		srcsize++;
	if (srcsize + 1 < size)
		ft_memcpy(dst, src, srcsize + 1);
	else if (size)
	{
		ft_memcpy(dst, src, size - 1);
		dst[size - 1] = 0;
	}
	return (srcsize);
}

// Copies a string and returns the duplicate
char	*ft_strdup(char *src)
{
	char	*	dup = (char *) malloc(ft_strlen(src) + 1);
	if (!dup)
		return (NULL);

	size_t	i = 0;
	while (src[i] != '\0')
	{
		dup[i] = src[i];
		i++;
	}
	dup[i] = '\0';
	return (dup);
}

// Concatenates two strings for 'size' bytes and returns the length of the new string
size_t	ft_strlcat(char *dst, const char *src, size_t size)
{
	unsigned int dest_size = 0;
	while (dst[dest_size] != '\0')
		dest_size++;

	unsigned int src_size = 0;
	while (src[src_size] != '\0')
		src_size++;

	if (dest_size > size)
		return (size + src_size);

	unsigned int i = 0;
	while ((src[i] != '\0') && (dest_size + 1 < size))
	{
		dst[dest_size] = src[i];
		i++;
		dest_size++;
	}
	dst[dest_size] = '\0';
	return (dest_size + src_size);
}

// Concatenates two strings and actually returns the new string made
char	*ft_strjoin(char const *s1, char const *s2)
{
	char	*s3 = (char *)malloc (ft_strlen(s1) + ft_strlen(s2) + 1);
	if (s3 == NULL)
		return (NULL);

	int	i = 0;
	while (*s1)
	{
		s3[i] = *s1;
		i++;
		s1++;
	}
	while (*s2)
	{
		s3[i] = *s2;
		i++;
		s2++;
	}
	s3[i] = '\0';
	return (s3);
}

// Creates a new string from within another string using start and len as starting and ending points
char	*ft_substr(char const *s, unsigned int start, size_t len)
{
	size_t	i = 0;
	size_t	strlen = ft_strlen(s);

	if (start >= strlen)
		return ((char *)ft_calloc(1, sizeof(char)));
	if (len > (strlen - start))
		len = strlen - start;

	char	*mem = (char *)malloc(len + 1);
	if (!mem)
		return (NULL);
	while (i < len)
	{
		mem[i] = s[start + i];
		i++;
	}
	mem[i] = '\0';
	return (mem);
}

// Trims a string by cutting characters that are part of 'set' from the beginning and end of the string
static int	inset(char c, char const *set);
char	*ft_strtrim(char const *s1, char const *set)
{
	int	lenstr = ft_strlen(s1);
	int	end = lenstr - 1;
	int	start = 0;

	while (s1[start] && inset(s1[start], set))
		start++;
	while (end >= start && inset(s1[end], set))
		end--;

	char *cut = (char *)malloc((end - start + 1) + 1);
	if (!cut)
		return (NULL);
	int i = 0;
	while (start <= end)
	{
		cut[i] = s1[start];
		i++;
		start++;
	}
	cut[i] = '\0';
	return (cut);
}

static int	inset(char c, char const *set)
{
	while (*set)
	{
		if (c == *set)
			return (1);
		set++;
	}
	return (0);
}

// Finds the first ocurrence of 'c' within 's' and returns a pointer to it
char	*ft_strchr(char *s, int c)
{
	int i = 0;

	c = (char)c;
	while (s[i] != '\0')
	{
		if (s[i] == c)
			return (&s[i]);
		i++;
	}
	if (s[i] == c)
		return (&s[i]);
	return (NULL);
}

// Finds the last ocurrence of 'c' within 's' and returns a pointer to it
char	*ft_strrchr(char *s, int c)
{
	char	*ch = NULL;
	int i = 0;
	
	c = (char)c;
	while (s[i] != '\0')
	{
		if (s[i] == c)
			ch = &s[i];
		i++;
	}
	if (s[i] == c)
		ch = &s[i];
	return (ch);
}

// Finds a string 'little' within a string 'big' and returns a pointer to it
char	*ft_strnstr(char *big, char *little, size_t len)
{
	size_t	i = 0;

	if (*little == '\0')
		return (big);
	while (big[i] && i < len)
	{
		size_t j = 0;
		while (big[i + j] == little[j] && i + j < len)
		{
			if (little[j] == '\0')
				return (&big[i]);
			j++;
		}
		if (little[j] == '\0')
			return (&big[i]);
		i++;
	}
	return (NULL);
}

// Iterates a function 'f' through every character in a string
void	ft_striteri(char *s, void (*f)(unsigned int, char*))
{
	unsigned int i = 0;

	while (s[i] != '\0')
	{
		(*f)(i, &s[i]);
		i++;
	}
}

// Creates a new string by iterating a function 'f' through every characer in a string
char	*ft_strmapi(char const *s, char (*f)(unsigned int, char))
{
	char *newstr = (char *)malloc ((ft_strlen(s) + 1) * sizeof(char));
	if (!newstr)
		return (NULL);

	int	 i = 0;
	while (s[i] != '\0')
	{
		newstr[i] = f(i, s[i]);
		i++;
	}
	newstr[i] = '\0';
	return (newstr);
}















