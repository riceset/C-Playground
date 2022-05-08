/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tkomeno <tkomeno@student.42tokyo.jp>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/07 08:06:27 by tkomeno           #+#    #+#             */
/*   Updated: 2022/05/08 18:15:16 by tkomeno          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "reading.h"

#define FILE_NAME "long.txt"

int	main(void)
{
	char	*buf;
	char	*buf2;
	char	*buf3;
	char	*buf4;
	char	*buf5;
	int		fd;

	fd = open(FILE_NAME, O_RDONLY);
	buf = reading_test(fd);
	buf2 = reading_test(fd);
	// buf3 = reading_test(fd);
	// buf4 = reading_test(fd);
	// buf5 = reading_test(fd);

	printf("%s", buf);
	printf("%s", buf2);
	// printf("%s", buf3);
	// printf("%s", buf4);
	// printf("%s", buf5);
	return (0);
}
