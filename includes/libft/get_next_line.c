/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: penpalac <penpalac@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/22 18:53:50 by penpalac          #+#    #+#             */
/*   Updated: 2025/09/22 19:38:32 by penpalac         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*readfd(int fd, char *static_var);
char	*next_line(char *static_var);
char	*gnl_strjoin(char *s1, char *s2);
char	*ft_free(char **str);

// Reads a file line by line using a static char* to keep track of the fd between calls
char	*get_next_line(int fd)
{
	static char	*static_var[1024];
	char		*line;
	char		*temp;

	if (fd < 0 || BUFFER_SIZE <= 0)
		return (NULL);

	if (!static_var[fd] || (static_var[fd] && !ft_strchr(static_var[fd], '\n')))
		static_var[fd] = readfd(fd, static_var[fd]);
	if (!static_var[fd])
		return (NULL);

	temp = ft_strchr(static_var[fd], '\n');
	line = ft_substr(static_var[fd], 0, (temp - static_var[fd]) + 1);
	if (!line)
		return (ft_free(&static_var[fd]));
	static_var[fd] = next_line(static_var[fd]);
	return (line);
}

// Reads the fd and puts it into the static
char	*readfd(int fd, char *static_var)
{
	char *buffer = malloc(sizeof(char) * (BUFFER_SIZE + 1));
	if (!buffer)
		return (ft_free(&static_var));

	buffer[0] = '\0';
	int	readbytes = 1;
	while (readbytes > 0 && !ft_strchr(buffer, '\n'))
	{
		readbytes = read (fd, buffer, BUFFER_SIZE);
		if (readbytes > 0)
		{
			buffer[readbytes] = '\0';
			static_var = gnl_strjoin(static_var, buffer);
		}
	}
	free(buffer);
	if (readbytes == -1)
		return (ft_free(&static_var));
	return (static_var);
}

// Gets the next line after eliminating
char	*next_line(char *static_var)
{
	char *temp = ft_strchr(static_var, '\n');
	if (!temp)
		return (ft_free(&static_var));

	int length = (temp - static_var) + 1;
	if (!static_var[length])
		return (ft_free(&static_var));
	char *next = ft_substr(static_var, length, ft_strlen(static_var) - length);
	ft_free(&static_var);
	if (!next)
		return (NULL);
	return (next);
}

// Concatenates two strings and returns the result. I sdifferent from ft_strjoin in
// the sense that it manages gnl's memory
char	*gnl_strjoin(char *s1, char *s2)
{
	if (!s1)
	{
		s1 = malloc(sizeof(char) + 1);
		if (!s1)
			return (0);
		s1[0] = 0;
	}

	char *s3 = ft_calloc(ft_strlen(s1) + ft_strlen(s2) + 1, sizeof(char));
	if (!s3)
		return (ft_free(&s1));
	int i = 0;
	while (s1[i])
	{
		s3[i] = s1[i];
		i++;
	}
	int j = 0;
	while (s2[j])
	{
		s3[i + j] = s2[j];
		j++;
	}
	free(s1);
	return (s3);
}

// A free for a matrix
char	*ft_free(char **str)
{
	free(*str);
	*str = NULL;
	return (NULL);
}
