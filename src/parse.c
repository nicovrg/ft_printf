/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jquivogn <jquivogn@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/01/07 19:01:31 by nivergne          #+#    #+#             */
/*   Updated: 2019/01/24 18:55:47 by jquivogn         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

//#include "ft_printf.h"
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
		if (options->width == -1)
			options->width = c - '0';
		else
			options->width = options->width * 10 + c - '0';
		return (1);
	}
	return (0);
}

int		check_accuracy_one(char c, t_info *options)
{
	if (c == '.')
	{
		options->accuracy = 0;
		return (1);
	}
	return (0);
}

int		check_accuracy_two(char c, t_info *options)
{
	if (c >= '0' && c <= '9')
	{
		options->accuracy = options->accuracy * 10 + c - '0';
		return (1);
	}
	return (0);
}

int		check_type(char c, t_info *options)
{
	if (c == 'h')
	{
		if (options->type == 1)
			options->type = 3;
		else
			options->type = 1;
		return (1);
	}
	else if (c == 'l')
	{
		if (options->type == 2)
			options->type = 4;
		else
			options->type = 2;
		return (1);
	}
	else if (c == 'j' || c == 'z')
	{
		options->type = 4;
		return (1);
	}
	else if (c == 'q')
		return (1);
	return (0);
}

int		check_conversion(char c, t_info *options)
{
	int		i;
	char	*str;

	i = 0;
	str = "cspdiouxXb%";
	while (str[i])
	{
		if (c == str[i])
		{
			options->conversion = i;
			return (1);
		}
		i++;
	}
	return (0);
}
