/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nivergne <nivergne@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/12/23 16:58:54 by nivergne          #+#    #+#             */
/*   Updated: 2019/01/07 20:50:53 by nivergne         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/ft_printf.h"

int		check_flag(char c, t_info *options)
{
	if (c == '0')
		options->zero = 1;
	else if (c == '+')
		options->plus = 1;
	else if (c == '-')
		options->minus = 1;
	else if (c == ' ')
		options->space = 1;
	else if (c == '#')
		options->hashtag = 1;
	if (c == ' ' || c == '-' || c == '+' || c == '#' || c == '0')
		return (1);
	return (0);
}

int		check_width(char c, t_info *options)
{
	if (c >= '0' && c <= '9')
	{
		if (options->width == 0)
			options->width = c - '0';
		else
			options->width = options->width * 10 + c - '0';
	}
	if (c >= '0' && c <= '9')
		return (1);
	return (0);
}

int		check_accuracy(char c, t_info *options)
{
	static int check = 0;

	if (check == 0 && c == '.')
	{
		check = 1;
		return (1);
	}
	if (c >= '0' && c <= '9')
	{
		if (options->accuracy == 0)
			options->accuracy = c - '0';
		else
			options->accuracy = options->accuracy * 10 + c - '0';
	}
	if (c >= '0' && c <= '9')
		return (1);
}

int		check_type(char c, t_info *options)
{ 
	if (c == 'h')
	{
		if (options->type == 1)
			options->type = 3;
		else
			options->type = 1;
	}
	else if (c == 'l')
	{
		if (options->type == 2)
			options->type = 4;
		else
			options->type = 2;
	}
	//cas d erreur mal gere
	return (0);
}

int		check_conversion(char c, t_info *options)
{

}

int		parse_str(char *str, t_info *options)
{
	int		shift;

	shift = 1;
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
	t_info	options;

	i = 0;
	while (str[i])
	{
		if (str[i] == '%')
			i = i + parse_str(str + i, &options);
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