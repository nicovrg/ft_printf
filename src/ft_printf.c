/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nivergne <nivergne@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/12/23 16:58:54 by nivergne          #+#    #+#             */
/*   Updated: 2019/01/04 21:57:53 by nivergne         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/ft_printf.h"

int		check_flag(char c)
{
	if (c == ' ' || c == '-' || c == '+' || c == '#' || c == '0')
		return (1);
	return (0);
}

int		parse_str(char *str)
{
	int		shift;

	shift = 1;
	while (str[shift] == ' ')
	{
		shift++;
	}
	return (shift);
}

int		append_to_buff(char c)
{
	static int		index = 0;
	static char		*buff = NULL;

	if (!buff)
	{
		if (!(buff = ft_memalloc(4096)))
			return (NULL);
	}
	buff[index] = c;
	index++;
}

int		ft_printf(char *str)
{
	int		i;

	i = 0;

	while (str[i])
	{
		if (str[i] == '%')
			i = i + parse_str(str + i);
		else
			append_to_buff(str[i]);
		i++;
	}
	return (0);
}


/*
%c	ft_putchar
%s	ft_putstr
%p	ft_putaddr
%d	ft_putnbr
%i	ft_putnbr
%o	ft_putoct
%u	ft_putuns
%x	ft_puthexmin
%X	ft_puthexmaj
%f	ft_putfloat
*/