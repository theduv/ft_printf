/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_per.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tduval <tduval@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/28 14:05:17 by tduval            #+#    #+#             */
/*   Updated: 2018/11/28 14:14:47 by tduval           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>
#include "libftprintf.h"

int    print_per(va_list ap, t_flags elem)
{
    char    c;
    int     i;
    int     j;
    int     h;

    i = 0;
    while (i < elem.width - 1 && !ft_strchr(elem.options, '-'))
    {
        ft_putchar(' ');
        i++;
    }
    c = '%';
    i += (int)write(1, &c, 1);
    j = 0;
    while (j < elem.width - 1 && ft_strchr(elem.options, '-'))
    {
        ft_putchar(' ');
        i++;
        j++;
    }
    return (i);
}