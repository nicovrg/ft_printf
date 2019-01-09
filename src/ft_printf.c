/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nivergne <nivergne@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/12/23 16:58:54 by nivergne          #+#    #+#             */
/*   Updated: 2019/01/09 00:46:45 by nivergne         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/ft_printf.h"

int		parse_str(char *str, t_info *options)
{
	int		shift;

	shift = 0;
	while (check_flag(str[shift], options) == 1)
		shift++;
	while (check_width(str[shift], options) == 1)
		shift++;
	while (check_accuracy(str[shift], options) == 1)
		shift++;
	while (check_type(str[shift], options) == 1)
		shift++;
	while (check_conversion(str[shift], options) == 1)
		shift++;
	ft_put_info(options);
	return (shift);
}

int		append_to_buff(char c)
{
	static int		index = 0;
	static char		*buff = NULL;

	if (!buff)
	{
		if (!(buff = ft_memalloc(4096)))
			return (0);
	}
	buff[index] = c;
	index++;
	return (index);
}

int		ft_printf(char *str)
{
	int		i;
	t_info	options;

	i = 0;
	t_info_init(&options);
	while (str[i])
	{
		if (str[i] == '%')
			i = i + parse_str(str + i + 1, &options);
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