/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_i.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nivergne <nivergne@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/01/11 03:18:33 by nivergne          #+#    #+#             */
/*   Updated: 2019/01/27 19:54:36 by nivergne         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

//#include "ft_printf.h"
#include "../include/ft_printf.h"

void	ft_nbr(va_list ap, t_info *options)
{
	long long	cast_ap;

	cast_ap = (options->type == 0 ? va_arg(ap, int) : 0);
	cast_ap = (options->type == 1 ? (short)va_arg(ap, int) : cast_ap);
	cast_ap = (options->type == 3 ? (signed char)va_arg(ap, int) : cast_ap);
	cast_ap = (options->type == 2 ? va_arg(ap, long) : cast_ap);
	cast_ap = (options->type == 4 ? va_arg(ap, long long) : cast_ap);
	if (cast_ap == 0 && options->accuracy == 0)
	{
		width_for_null(options);
		return ;
	}
	if (cast_ap < 0)
	{
		if (options->type == 4 && (cast_ap <= -9223372036854775807 && cast_ap > 9223372036854775807))
		{
			cast_ap = -922337203685477580;
			options->llmin = 1;
		}
		cast_ap *= -1;
		options->neg = 1;
	}
	ft_addnbr(cast_ap, options);
}

void	ft_nbrsign(t_info *options)
{
	options->plus && !options->minus && !options->neg ? append_to_buff('+', 0, options) : 0;
	options->space && !options->minus && !options->plus && !options->neg ? append_to_buff(' ', 0, options) : 0;
	options->neg && !options->minus ? append_to_buff('-', 0, options) : 0;
}

void	ft_addnbr(long long cast_ap, t_info *options)
{
	int 		size;
	
	size = width_size_diou(options, cast_ap, 10);
	options->plus && options->minus && !options->neg ? append_to_buff('+', 0, options) : 0;
	!options->plus && options->minus && !options->neg && options->space ? append_to_buff(' ', 0, options) : 0;
	options->neg && options->minus ? append_to_buff('-', 0, options) : 0;
	options->accuracy > 0 && options->minus ? ft_accuracy(options) : 0;
	options->minus == 1 ? ft_addnbr_core(cast_ap, options) : 0;
	options->minus == 1 && options->llmin == 1 ? ft_addnbr_core(8, options) : 0;
	if (options->zero)
		ft_nbrsign(options);
	if (options->width >= 0 && size > 0)
		while (size--)
			append_to_buff(options->zero && !options->minus && options->accuracy <= 0 ? '0' : ' ', 0, options);
	if (!options->zero)
		ft_nbrsign(options);
	options->accuracy > 0 && !options->minus ? ft_accuracy(options) : 0;
	options->minus == 0 ? ft_addnbr_core(cast_ap, options) : 0;
	options->minus == 0 && options->llmin == 1 ? ft_addnbr_core(8, options) : 0;
}

void	ft_addnbr_core(long long nb, t_info *options)
{
	if (nb < 0)
	{
		append_to_buff('-', 0, options);
		nb = -nb;
	}
	if (nb >= 10)
	{
		ft_addnbr_core(nb / 10, options);
		append_to_buff(nb % 10 + '0', 0, options);
	}
	else
		append_to_buff(nb % 10 + '0', 0, options);
}
