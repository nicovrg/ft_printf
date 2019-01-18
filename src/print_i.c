/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_d.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nivergne <nivergne@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/01/11 03:18:33 by nivergne          #+#    #+#             */
/*   Updated: 2019/01/17 23:36:31 by nivergne         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

//#include "ft_printf.h"
#include "../include/ft_printf.h"

void	ft_nbr(va_list ap, t_info *options)
{
	long long	cast_ap;

	cast_ap = (options->type == 0 ? va_arg(ap, int) : 0);
	cast_ap = (options->type == 3 ? va_arg(ap, int) : cast_ap);
	cast_ap = (options->type == 1 ? va_arg(ap, int) : cast_ap);
	cast_ap = (options->type == 2 ? va_arg(ap, long) : cast_ap);
	cast_ap = (options->type == 4 ? va_arg(ap, long long) : cast_ap);
	ft_addnbr(cast_ap, options);
}

void	ft_addnbr(long long cast_ap, t_info *options)
{
	int 		size;
	
	size = width_size(options, cast_ap, 10);

	options->plus && options->minus && cast_ap >= 0 ? append_to_buff('+', 0) : 0;
	//options->space && options->minus && !options->plus ? append_to_buff(' ', 0) : 0;
	options->accuracy > 0 && options->minus ? ft_accuracy(options) : 0;
	if (options->minus == 1)
		ft_addnbr_core(cast_ap, options);
	if (options->width >= 0 && size > 0)
		while (size--)
			append_to_buff(options->zero && !options->minus ? '0' : ' ', 0);
	options->plus && !options->minus && cast_ap >= 0 ? append_to_buff('+', 0) : 0;
	//options->space && !options->minus && !options->plus ? append_to_buff(' ', 0) : 0;
	options->accuracy > 0 && !options->minus ? ft_accuracy(options) : 0;
	if (options->minus == 0)
		ft_addnbr_core(cast_ap, options);
}

void	ft_addnbr_core(long long nb, t_info *options)
{
	if (nb < 0)
	{
		append_to_buff('-', 0);
		nb = -nb;
	}
	if (nb >= 10)
	{
		ft_addnbr_core(nb / 10, options);
		append_to_buff(nb % 10 + '0', 0);
	}
	else
		append_to_buff(nb % 10 + '0', 0);
}
