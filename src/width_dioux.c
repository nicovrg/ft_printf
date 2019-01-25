/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   width_dioux.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: julesqvgn <julesqvgn@student.42.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/01/11 22:11:15 by nivergne          #+#    #+#             */
/*   Updated: 2019/01/26 00:13:03 by julesqvgn        ###   ########.fr       */
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
		- (options->plus == 1 && options->neg == 0 ? 1 : 0) - (options->neg == 1 ? 1 : 0) - (options->space == 1 ? 1 : 0);
	options->accuracy = options->accuracy - size_nb;
	//if (options->accuracy < -1)
	//	options->accuracy = 0;
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
	width = width - (accuracy > size_ap ? accuracy : size_ap) - (options->hashtag == 1 ? 2 : 0);
	options->accuracy = options->accuracy - size_ap;
	return (width);
}

int		width_size_o(t_info *options, unsigned long long cast_ap)
{
	int width;
	int size_nb;

	size_nb = cast_ap == 0 ? 1 : 0;
	width = options->width;
	while (cast_ap > 0)
	{
		cast_ap /= 10;
		size_nb++;
	}
	width = width - (options->accuracy > size_nb ? options->accuracy : size_nb) - (options->hashtag == 1 ? 1 : 0);
	options->accuracy = options->accuracy - size_nb - (options->hashtag == 1 ? 1 : 0);
	return (width);
}

void	width_for_null(t_info *options)
{
	options->minus == 1 && options->hashtag == 1 && options->conversion == 5 ? ft_addnbr_core(0, options) : 0;
	options->conversion == 5 && options->hashtag == 1 ? options->width-- : 0;
	while (options->width-- > 0)
		append_to_buff(' ', 0, options);
	options->minus == 0 && options->hashtag == 1 && options->conversion == 5 ? ft_addnbr_core(0, options) : 0;
}
