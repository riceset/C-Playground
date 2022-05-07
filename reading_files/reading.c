/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   reading.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tkomeno <tkomeno@student.42tokyo.jp>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/07 08:05:14 by tkomeno           #+#    #+#             */
/*   Updated: 2022/05/07 16:31:19 by tkomeno          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "reading.h"

#define BUFFER_SIZE 6

char	*ft_strncpy(char *dst, char *src, unsigned int n);

char	*reading_test(int fd)
{
	int			line_len;
	char		*line;
	static char	*pile;

	pile = malloc(BUFFER_SIZE * sizeof(char));
	read(fd, pile, BUFFER_SIZE);
	line_len = 0;
	while (pile[line_len] != '\n' && pile[line_len] != '\0')
		line_len++;
	line_len++;
	line = malloc((line_len + 1) * sizeof(char));
	line = ft_strncpy(line, pile, line_len);
	pile += line_len;
	return (line);
}

char	*ft_strncpy(char *dst, char *src, unsigned int n)
{
	unsigned int	i;

	i = 0;
	while (i < n && src[i] != '\0')
	{
		dst[i] = src[i];
		i++;
	}
	while (i < n)
	{
		dst[i] = '\0';
		i++;
	}
	return (dst);
}
