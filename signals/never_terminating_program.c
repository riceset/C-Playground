/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   never_terminating_program.c                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tkomeno <tkomeno@student.42tokyo.jp>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/04 08:14:05 by tkomeno           #+#    #+#             */
/*   Updated: 2022/05/04 08:34:02 by tkomeno          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>

typedef enum e_bool
{
	false,
	true
} t_bool;

void handler(int num)
{
	write(STDOUT_FILENO, "I won't die!\n", 13);
}

int main(void)
{
	signal(SIGINT, handler);
	signal(SIGTERM, handler);

	while (true)
	{
		printf("%d\n", getpid());
		sleep(1);
	}
}
