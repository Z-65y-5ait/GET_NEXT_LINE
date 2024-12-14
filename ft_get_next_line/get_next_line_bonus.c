/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_bonus.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: azaimi <azaimi@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/24 17:49:50 by azaimi            #+#    #+#             */
/*   Updated: 2024/11/27 19:22:55 by azaimi           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line_bonus.h"

static void	read_file(ssize_t *count, char	**ptr, int fd)
{
	char	*buff;

	buff = (char *)malloc((size_t)BUFFER_SIZE + 1);
	if (!buff)
		return ;
	*count = read(fd, buff, BUFFER_SIZE);
	if (*count < 0)
	{
		free(buff);
		if (*ptr)
		{
			free(*ptr);
			*ptr = NULL;
		}
		return ;
	}
	while (*count > 0)
	{
		buff[*count] = '\0';
		*ptr = ft_strjoin(*ptr, buff);
		if (ft_strchr(*ptr, '\n'))
			break ;
		*count = read(fd, buff, BUFFER_SIZE);
	}
	free(buff);
}

static char	*check_line(char **ptr)
{
	char	*newline;
	char	*temp;
	char	*line;

	if (!ptr || !*ptr)
		return (NULL);
	newline = ft_strchr(*ptr, '\n');
	if (newline)
	{
		line = ft_strdup(*ptr, newline - *ptr + 1);
		temp = ft_strdup(newline + 1, ft_strlen(newline + 1));
		free(*ptr);
		*ptr = temp;
	}
	else
	{
		line = ft_strdup(*ptr, ft_strlen(*ptr));
		free(*ptr);
		*ptr = NULL;
	}
	return (line);
}

char	*get_next_line(int fd)
{
	static char	*ptr[OPEN_MAX];
	ssize_t		count;
	char		*line;

	if (fd < 0 || fd > OPEN_MAX || BUFFER_SIZE <= 0 || BUFFER_SIZE > INT_MAX)
		return (NULL);
	read_file(&count, &ptr[fd], fd);
	if (count < 0 || (count == 0 && (!ptr[fd] || ptr[fd][0] == '\0')))
	{
		free(ptr[fd]);
		ptr[fd] = NULL;
		return (NULL);
	}
	line = check_line(&ptr[fd]);
	return (line);
}
