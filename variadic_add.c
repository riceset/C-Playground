/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   variadic_add.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tkomeno <tkomeno@student.42tokyo.jp>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/28 11:58:34 by tkomeno           #+#    #+#             */
/*   Updated: 2022/04/29 01:58:11 by tkomeno          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "playground.h"

int add(int args, ...)
{
	va_list ap;
	int sum;

	sum = 0;
	va_start(ap, args);
	for (int i = 0; i < args; i++)
		sum += va_arg(ap, int);
	va_end(ap);

	return (sum);
}