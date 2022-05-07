/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   reading.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tkomeno <tkomeno@student.42tokyo.jp>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/07 08:05:14 by tkomeno           #+#    #+#             */
/*   Updated: 2022/05/07 10:41:33 by tkomeno          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "reading.h"

#define BUFFER_SIZE 6

static int	newline_index(char *string);
static char	*ft_strncpy(char *dst, char *src, unsigned int n);

char	*reading_test(int fd)
{
	char	*str;
	char	*line;
	int		head;
	int		tail;

	str = "a\nb\nc";
	while (*str != '\0')
	{
		tail = newline_index(str);
		if (tail == -1)
			break ;
		line = ft_strncpy(line, str, tail);
		printf("%s", str);
		str += tail;
	}
	return (line);
}

static int	newline_index(char *string)
{
	int	i;

	i = 0;
	while (string[i] != '\0')
	{
		if (string[i] == '\n')
			return (i + 1);
		i++;
	}
	return (-1);
}

static char	*ft_strncpy(char *dst, char *src, unsigned int n)
{
	unsigned int	i;

	i = 0;
	while (src[i] != '\0' && i < n)
	{
		dst[i] = src[i];
		i++;
	}
	while (i < n)
	{
		dst[i] = '\0';
	}
	return (dst);
}
