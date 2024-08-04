/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lroman-p <lroman-p@student.42madrid.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/30 11:47:21 by lroman-p          #+#    #+#             */
/*   Updated: 2024/08/03 12:44:48 by lroman-p         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

char	*ft_strchr(const char *str, int c)
{
	while (*str)
	{
		if (*str == c)
			return ((char *)str);
		str++;
	}
	if (c == '\0')
		return ((char *)str);
	return (0);
}

size_t	ft_strlen(const char *s)
{
	int	i;

	i = 0;
	if (!s)
		return (0);
	while (s[i] != '\0')
		i++;
	return (i);
}

char	*ft_strjoin(const char *s1, char const *s2)
{
	int		size_s1;
	int		size_2;
	char	*str;
	int		i;
	int		j;

	size_s1 = ft_strlen(s1);
	size_2 = ft_strlen(s2);
	str = malloc(size_s1 + size_2 +1);
	if (str == NULL)
		return (NULL);
	i = 0;
	j = 0;
	while (i < size_s1)
		str[i++] = s1[j++];
	j = 0;
	while (j < size_2)
		str[i++] = s2[j++];
	str[i] = '\0';
	return (str);
}

void	*ft_calloc(size_t count, size_t size)
{
	unsigned char	*p;
	size_t			i;

	p = NULL;
	if (!count || (count && SIZE_MAX / count > size))
	{
		p = malloc(count * size);
		if (p != NULL)
		{
			i = 0;
			while (i < count * size)
				*(p + i++) = '\0';
		}
	}
	return (p);
}

void	ft_free_strs(char **str, char **str1, char **str2)
{
	if (str && *str)
	{
		free(*str);
		*str = NULL;
	}
	if (str1 && *str1)
	{
		free(*str1);
		*str1 = NULL;
	}
	if (str2 && *str2)
	{
		free(*str2);
		*str2 = NULL;
	}
}
