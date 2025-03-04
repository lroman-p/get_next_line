/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lroman-p <lroman-p@student.42madrid.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/30 12:26:30 by lroman-p          #+#    #+#             */
/*   Updated: 2024/08/03 13:19:53 by lroman-p         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

char	*get_line_start(const char *str)
{
	char	*res_memory;
	int		i;

	i = 0;
	while (str[i] != '\0' && str [i] != '\n')
		i++;
	if (str[i] != '\0' && str [i] == '\n')
		i++;
	res_memory = ft_calloc(i + 1, sizeof * res_memory);
	if (!res_memory)
		return (NULL);
	i = 0;
	while (str[i] != '\0' && str[i] != '\n')
	{
		res_memory[i] = str[i];
		i++;
	}
	if (str[i] == '\n')
	{
		res_memory[i] = str[i];
		i++;
	}
	return (res_memory);
}

char	*get_line_end(const char *str)
{
	char	*res_memory;
	int		i;
	int		j;

	i = 0;
	while (str[i] != '\0' && str[i] != '\n')
		i++;
	if (str[i] != '\0' && str[i] == '\n')
		i++;
	j = 0;
	while (str && str[j])
		j++;
	res_memory = ft_calloc((j - i) + 1, sizeof * res_memory);
	if (!res_memory)
		return (NULL);
	j = 0;
	while (str[i + j])
	{
		res_memory[j] = str[i + j];
		j++;
	}
	return (res_memory);
}

void	read_line(int fd, char **storage)
{
	char	*mem_reserve;
	char	*tempo;
	long	readed;

	mem_reserve = malloc(sizeof(char) * (BUFFER_SIZE +1));
	if (!mem_reserve)
		return ;
	readed = 1;
	while (readed > 0)
	{
		readed = read(fd, mem_reserve, BUFFER_SIZE);
		if (readed < 0)
		{
			ft_free_strs(&mem_reserve, storage, NULL);
			return ;
		}
		mem_reserve[readed] = '\0';
		tempo = *storage;
		*storage = ft_strjoin(*storage, mem_reserve);
		free(tempo);
		if (ft_strchr(*storage, '\n'))
			break ;
	}
	free (mem_reserve);
}

char	*process_current_line(char **storage)
{
	char	*line;
	char	*tempo;

	line = get_line_start(*storage);
	tempo = *storage;
	*storage = get_line_end(*storage);
	free (tempo);
	return (line);
}

char	*get_next_line(int fd)
{
	static char	*storage;
	char		*line;

	if (fd < 0 || BUFFER_SIZE < 0)
		return (NULL);
	line = NULL;
	read_line(fd, &storage);
	if (storage != NULL && *storage != '\0')
		line = process_current_line(&storage);
	if (!line || *line == '\0')
	{
		ft_free_strs(&storage, &line, NULL);
		if (!line)
			return (NULL);
	}
	return (line);
}
