/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   play_realloc.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tkomeno <tkomeno@student.42tokyo.jp>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/07 21:51:00 by tkomeno           #+#    #+#             */
/*   Updated: 2022/04/07 21:51:02 by tkomeno          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include <stdio.h>

#define SIZE1 2
#define SIZE2 100000

int	main(void)
{
	int	i;
	int	*ptr;

	ptr = (int *) malloc(sizeof(int) * SIZE1);
	if (!ptr)
		return (1);
	i = 0;
	while (i < SIZE1)
	{
		ptr[i] = i + 1;
		i++;
	}
	i = 0;
	while (i < SIZE1)
	{
		printf("ptr[%d] is %d\n", i, ptr[i]);
		i++;
	}
	puts("");
	ptr = (int *) realloc(ptr, sizeof(int) * SIZE2);
	if (!ptr)
		return (1);
	i = 0;
	while (i < SIZE2)
	{
		ptr[i] = i + 1;
		i++;
	}
	i = 0;
	while (i < SIZE2)
	{
		printf("ptr[%d] is %d\n", i, ptr[i]);
		i++;
	}
	free(ptr);
}
