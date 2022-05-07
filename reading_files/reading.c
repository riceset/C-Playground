/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   reading.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tkomeno <tkomeno@student.42tokyo.jp>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/07 08:05:14 by tkomeno           #+#    #+#             */
/*   Updated: 2022/05/07 16:05:46 by tkomeno          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "reading.h"

#define BUFFER_SIZE 6

char	*ft_strncpy(char *dst, char *src, unsigned int n);

char	*reading_test(int fd)
{
	char	*phrase;
	char	*line;
	int		i;

	phrase = "Hello World!\nI am here!\nThat's cool!";

	i = 0;
	while (phrase[i] != '\n' && phrase[i] != '\0')
		i++;
	i++;
	line = malloc(i * sizeof(char));
	line = ft_strncpy(line, phrase, i);
	printf("%s", line);
	phrase += i;
	i = 0;
	while (phrase[i] != '\n' && phrase[i] != '\0')
		i++;
	i++;
	line = malloc(i * sizeof(char));
	line = ft_strncpy(line, phrase, i);
	printf("%s", line);
	phrase += i;
	i = 0;
	while (phrase[i] != '\n' && phrase[i] != '\0')
		i++;
	i++;
	line = malloc(i * sizeof(char));
	line = ft_strncpy(line, phrase, i);
	printf("%s", line);
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
