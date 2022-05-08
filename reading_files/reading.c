/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   reading.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tkomeno <tkomeno@student.42tokyo.jp>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/07 08:05:14 by tkomeno           #+#    #+#             */
/*   Updated: 2022/05/08 18:22:57 by tkomeno          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "reading.h"

#define BUFFER_SIZE 5

typedef enum e_bool
{
	false,
	true
}		t_bool;

t_bool	contains_newline(char *buffer)
{
	int	i;

	i = 0;
	while (i < BUFFER_SIZE)
	{
		if (buffer[i] == '\n')
			return (true);
		i++;
	}
	return (false);
}

char	*reading_test(int fd)
{
	static char	*save;
	int			line_len;
	char		*line;
	char		*buffer;
	t_bool		flag;

	save = NULL;
	if (fd < 0 || BUFFER_SIZE <= 0)
		return (0);
	if (!save)
	{
		save = ft_strdup("");
		if (!save)
			return (NULL);
	}
	flag = false;
	line = ft_strdup("");
	if (!line)
		return (NULL);
	buffer = ft_calloc(BUFFER_SIZE, sizeof(char));
	if (!buffer)
		return (NULL);
	while (!flag)
	{
		read(fd, buffer, BUFFER_SIZE);
		flag = contains_newline(buffer);
		save = ft_strjoin(save, buffer);
		line_len = 0;
		while (line_len < BUFFER_SIZE && save[line_len] != '\n')
			line_len++;
		if (save[line_len] == '\n')
			line_len++;
		line = ft_strjoin(line, ft_strndup(save, line_len));
		if (!line)
			return (NULL);
		save += line_len;
		ft_bzero(buffer, line_len);
	}
	ft_memmove(save + line_len, save, BUFFER_SIZE - line_len);
	return (line);
}
