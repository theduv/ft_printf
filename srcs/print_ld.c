/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_ld.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tduval <tduval@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/26 22:35:58 by tduval            #+#    #+#             */
/*   Updated: 2018/12/12 21:13:27 by tduval           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include "libftprintf.h"

static int	geti(long n)
{
	int		i;

	i = 0;
	if (n < 0)
	{
		n *= -1;
		i++;
	}
	while (n > 9)
	{
		n /= 10;
		i++;
	}
	return (i);
}

int			print_ld(va_list ap, t_flags elem)
{
	long	n;
	int		i;

	i = 1;
	if (elem.width == -1)
		elem.width = va_arg(ap, int);
	n = va_arg(ap, long);
	if (n == -9223372036854775807 - 1)
		i = 20;
	else
		i += geti(n);
	return (n == 0 && elem.accuracy == 0 ?
			padding_d((long long)n, 0, elem) : i +
			padding_d((long long)n, i, elem));
}
