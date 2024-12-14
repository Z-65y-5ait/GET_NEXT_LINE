/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: azaimi <azaimi@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/19 22:03:20 by azaimi            #+#    #+#             */
/*   Updated: 2024/11/25 23:11:29 by azaimi           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

size_t	ft_strlen(const char *str)
{
	size_t	i;

	i = 0;
	if (str == NULL)
		return (0);
	while (str[i])
		i++;
	return (i);
}

char	*ft_strcpy(const char *src, char *dst)
{
	while (*src)
		*dst++ = *src++;
	return (dst);
}

char	*ft_strdup(char *s, size_t len)
{
	size_t	i;
	char	*str;

	if (!s)
		return (NULL);
	str = malloc(len + 1);
	if (!str)
		return (NULL);
	i = 0;
	while (i < len)
	{
		str[i] = s[i];
		i++;
	}
	str[i] = '\0';
	return (str);
}

char	*ft_strjoin(char *s1, char *s2)
{
	int		len;
	char	*ptr;
	char	*dst;

	if (!s1 && !s2)
		return (ft_strdup("", 0));
	if (!s2)
		return (ft_strdup(s1, ft_strlen(s1)));
	if (!s1)
		return (ft_strdup(s2, ft_strlen(s2)));
	len = ft_strlen(s1) + ft_strlen(s2);
	dst = (char *)malloc(len + 1);
	if (!dst)
		return (NULL);
	ptr = dst;
	if (s1)
		dst = ft_strcpy(s1, dst);
	if (s2)
		dst = ft_strcpy(s2, dst);
	*dst = '\0';
	free(s1);
	return (ptr);
}

char	*ft_strchr(const char *s, int c)
{
	int	i;

	i = 0;
	if (s == NULL)
		return (NULL);
	while (s[i] != '\0')
	{
		if (s[i] == (unsigned char)c)
			return ((char *)&s[i]);
		i++;
	}
	if ((unsigned char)c == '\0')
		return ((char *)&s[i]);
	return (NULL);
}
