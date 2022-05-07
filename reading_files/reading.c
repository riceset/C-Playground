/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   reading.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tkomeno <tkomeno@student.42tokyo.jp>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/07 08:05:14 by tkomeno           #+#    #+#             */
/*   Updated: 2022/05/07 08:59:34 by tkomeno          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "reading.h"

#define BUFFER_SIZE 6

unsigned char	*reading_test(int fd)
{
	unsigned char	*buf;
	unsigned int	head;
	unsigned int	tail;
	unsigned char	*line;
	int				i;

	head = 0;
	tail = 0;
	buf = malloc(BUFFER_SIZE * sizeof(char));
	read(fd, buf, BUFFER_SIZE);
	while (buf[tail] != '\n')
		tail++;
	tail++;
	line = malloc(((tail - head) + 1) * sizeof(char));
	i = 0;
	while (i < (tail - head))
	{
		line[i] = buf[head + i];
		i++;
	}
	line[i] = '\0';
	return (line);
}
