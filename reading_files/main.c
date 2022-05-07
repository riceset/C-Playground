/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tkomeno <tkomeno@student.42tokyo.jp>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/07 08:06:27 by tkomeno           #+#    #+#             */
/*   Updated: 2022/05/07 10:23:18 by tkomeno          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "reading.h"

#define FILE_NAME "short.txt"

int	main(void)
{
	char	*buf;
	int		fd;

	fd = open(FILE_NAME, O_RDONLY);
	buf = reading_test(fd);
	return (0);
}
