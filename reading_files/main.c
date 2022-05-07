/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tkomeno <tkomeno@student.42tokyo.jp>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/07 08:06:27 by tkomeno           #+#    #+#             */
/*   Updated: 2022/05/07 08:41:09 by tkomeno          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "reading.h"

#define FILE_NAME "short.txt"

int	main(void)
{
	unsigned char	*buf;
	int				fd;

	fd = open(FILE_NAME, O_RDONLY);
	buf = reading_test(fd);
	printf("%s", buf);
	return (0);
}
