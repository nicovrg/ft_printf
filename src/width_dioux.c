/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   width_dioux.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jquivogn <jquivogn@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/01/11 22:11:15 by nivergne          #+#    #+#             */
/*   Updated: 2019/01/31 21:08:49 by jquivogn         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

//#include "ft_printf.h"
#include "../include/ft_printf.h"

int		width_size_diou(t_info *options, long long cast_ap, int base)
{
	int width;
	int size_nb;

	size_nb = cast_ap == 0 ? 1 : 0;
	width = options->width;
	if (cast_ap < 0)
	{
		cast_ap *= -1;
		size_nb++;
	}
	while (cast_ap > 0)
	{
		cast_ap /= base;
		size_nb++;
	}
	width = width - (options->accuracy > size_nb ? options->accuracy : size_nb)
		- (options->plus && !options->neg ? 1 : 0) - (options->neg ? 1 : 0) -
		(options->space == 1 && !options->plus && !options->neg ? 1 : 0);
	if (options->accuracy != -1)
	{
		if (options->accuracy - size_nb < 0)
			options->accuracy = 0;
		else
		{
			options->accuracy = options->accuracy - size_nb;
		}
	}
	return (width);
}

int		width_size_x(t_info *options, char *cast_ap)
{
	int width;
	int accuracy;
	int size_ap;

	width = options->width;
	accuracy = options->accuracy;
	size_ap = ft_strlen(cast_ap);
	if (options->hashtag == 1)
		options->hashtag = 2;
	width = width - (accuracy > size_ap ? accuracy : size_ap) - options->hashtag;
	if (options->accuracy != -1)
	{
		if (options->accuracy - size_ap < 0)
			options->accuracy = 0;
		else
		{
			options->accuracy = options->accuracy - size_ap;
		}
	}
	return (width);
}

int		width_size_o(t_info *options, unsigned long long cast_ap)
{
	int width;
	int size_nb;

	cast_ap = itooct(cast_ap);
	size_nb = cast_ap == 0 ? 1 : 0;
	width = options->width;
	while (cast_ap > 0)
	{
		cast_ap /= 10;
		size_nb++;
	}
	width = width - (options->accuracy > size_nb + options->hashtag ? options->accuracy : size_nb + options->hashtag);
	if (options->accuracy != -1)
	{
		if (options->accuracy - size_nb - (options->hashtag == 1 ? 1 : 0) < 0)
			options->accuracy = 0;
		else
		{
			options->accuracy = options->accuracy - size_nb - (options->hashtag == 1 ? 1 : 0);
		}
	}
	return (width);
}

void	width_for_null(t_info *options)
{
	if (options->minus)
	{
		options->plus && !options->neg ? append_to_buff('+', 0, options) : 0;
		options->space && !options->plus && !options->neg ? append_to_buff(' ', 0, options) : 0;
	}
	while (options->width--)
		append_to_buff(' ', 0, options);
	if (!options->minus)
	{
		options->plus && !options->neg ? append_to_buff('+', 0, options) : 0;
		options->space && !options->plus && !options->neg ? append_to_buff(' ', 0, options) : 0;
	}
}

unsigned long long	itooct(unsigned long long nb)
{
	unsigned long long	octnbr;
	unsigned long long	i;

	octnbr = 0;
	i = 1;
	while (nb > 0)
	{
		octnbr += (nb % 8) * i;
		nb /= 8;
		i *= 10;
	}
	return (octnbr);
}

int		width_bin(t_info *options)
{
	int		width;
	int		size_nb;

	size_nb = 8;
	width = options->width;
	width -= (options->accuracy > size_nb ? options->accuracy : size_nb) - options->space;
	if (options->accuracy != -1)
	{
		if (options->accuracy - size_nb < 0)
			options->accuracy = 0;
		else
		{
			options->accuracy = options->accuracy - size_nb;
		}
	}
	return (width);
}