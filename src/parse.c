/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nivergne <nivergne@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/01/07 19:01:31 by nivergne          #+#    #+#             */
/*   Updated: 2019/02/07 21:23:33 by nivergne         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

//#include "ft_printf.h"
#include "../include/ft_printf.h"

int		check_flag(char c, t_info *o)
{
	if (c == '0')
		o->zero = 1;
	else if (c == '+')
		o->plus = 1;
	else if (c == '-')
		o->minus = 1;
	else if (c == ' ')
		o->space = 1;
	else if (c == '#')
		o->hashtag = 1;
	if (c == ' ' || c == '-' || c == '+' || c == '#' || c == '0')
		return (1);
	return (0);
}

int		check_width(char c, t_info *o)
{
	if (c >= '0' && c <= '9')
	{
		if (o->width == -1)
			o->width = c - '0';
		else
			o->width = o->width * 10 + c - '0';
		return (1);
	}
	return (0);
}

int		check_accuracy_one(char c, t_info *o)
{
	if (c == '.')
	{
		o->accuracy = 0;
		return (1);
	}
	return (0);
}

int		check_accuracy_two(char c, t_info *o)
{
	if (c >= '0' && c <= '9')
	{
		o->accuracy = o->accuracy * 10 + c - '0';
		return (1);
	}
	return (0);
}

int		check_conversion(char c, t_info *o)
{
	int		i;
	char	*str;

	i = 0;
	str = "cspdiouxXbf%CSPDIOU";
	while (str[i])
	{
		if (c == str[i])
		{
			i > 11 ? o->type = 4 : 0;
			o->conversion = i;
			return (1);
		}
		i++;
	}
	return (0);
}
