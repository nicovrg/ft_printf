/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_u.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nivergne <nivergne@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/01/17 23:27:52 by nivergne          #+#    #+#             */
/*   Updated: 2019/01/18 03:10:02 by nivergne         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

//#include "ft_printf.h"
#include "../include/ft_printf.h"

void	ft_uns(va_list ap, t_info *options)
{
	long long	cast_ap;

	cast_ap = (options->type == 0 ? va_arg(ap, int) : 0);
	cast_ap = (options->type == 3 ? va_arg(ap, int) : cast_ap);
	cast_ap = (options->type == 1 ? va_arg(ap, int) : cast_ap);
	cast_ap = (options->type == 2 ? va_arg(ap, long) : cast_ap);
	cast_ap = (options->type == 4 ? va_arg(ap, long long) : cast_ap);
	ft_adduns(cast_ap, options);
}

void    ft_adduns(long long cast_ap, t_info *options)
{
	int 		size;
	
	size = width_size(options, cast_ap, 10);

	options->plus && options->minus && cast_ap >= 0 ? append_to_buff('+', 0) : 0;
	//options->space && options->minus && !options->plus ? append_to_buff(' ', 0) : 0;
	options->accuracy > 0 && options->minus ? ft_accuracy(options) : 0;
	if (options->minus == 1)
		ft_adduns_core(cast_ap, options);
	if (options->width >= 0 && size > 0)
		while (size--)
			append_to_buff(options->zero && !options->minus ? '0' : ' ', 0);
	options->plus && !options->minus && cast_ap >= 0 ? append_to_buff('+', 0) : 0;
	//options->space && !options->minus && !options->plus ? append_to_buff(' ', 0) : 0;
	options->accuracy > 0 && !options->minus ? ft_accuracy(options) : 0;
	if (options->minus == 0)
		ft_adduns_core(cast_ap, options);
}

void    ft_adduns_core(unsigned long long nb, t_info *options)
{
	if (nb >= 10)
	{
		ft_adduns_core(nb / 10, options);
		append_to_buff(nb % 10 + '0', 0);
	}
	else
		append_to_buff(nb % 10 + '0', 0);
}
