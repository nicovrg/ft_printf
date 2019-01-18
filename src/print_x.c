/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_x.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nivergne <nivergne@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/01/04 21:51:28 by nivergne          #+#    #+#             */
/*   Updated: 2019/01/18 03:57:36 by nivergne         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

//#include "ft_printf.h"
#include "../include/ft_printf.h"

void	ft_hex(va_list ap, t_info *options)
{
    long long	cast_ap;

	cast_ap = (options->type == 0 ? va_arg(ap, int) : 0);
	cast_ap = (options->type == 3 ? va_arg(ap, int) : cast_ap);
	cast_ap = (options->type == 1 ? va_arg(ap, int) : cast_ap);
	cast_ap = (options->type == 2 ? va_arg(ap, long) : cast_ap);
	cast_ap = (options->type == 4 ? va_arg(ap, long long) : cast_ap);
	if (options->conversion == 'x')
        ft_addhexmin(cast_ap, options);
	else if (options->conversion == 'X')
       ft_addhexmaj(cast_ap, options);
}

void    ft_addhexmin(long long cast_ap, t_info *options)
{
    int 		size;
	
	size = width_size(options, cast_ap, 16);

	options->plus && options->minus && cast_ap >= 0 ? append_to_buff('+', 0) : 0;
	//options->space && options->minus && !options->plus ? append_to_buff(' ', 0) : 0;
	options->accuracy > 0 && options->minus ? ft_accuracy(options) : 0;
	if (options->width >= 0 && size > 0)
		while (size--)
			append_to_buff(options->zero && !options->minus ? '0' : ' ', 0);
	options->plus && !options->minus && cast_ap >= 0 ? append_to_buff('+', 0) : 0;
	//options->space && !options->minus && !options->plus ? append_to_buff(' ', 0) : 0;
	options->accuracy > 0 && !options->minus ? ft_accuracy(options) : 0;
}

void    ft_addhexmaj(long long cast_ap, t_info *options)
{
    int 		size;
	
	size = width_size(options, cast_ap, 16);

	options->plus && options->minus && cast_ap >= 0 ? append_to_buff('+', 0) : 0;
	//options->space && options->minus && !options->plus ? append_to_buff(' ', 0) : 0;
	options->accuracy > 0 && options->minus ? ft_accuracy(options) : 0;
	if (options->width >= 0 && size > 0)
		while (size--)
			append_to_buff(options->zero && !options->minus ? '0' : ' ', 0);
	options->plus && !options->minus && cast_ap >= 0 ? append_to_buff('+', 0) : 0;
	//options->space && !options->minus && !options->plus ? append_to_buff(' ', 0) : 0;
	options->accuracy > 0 && !options->minus ? ft_accuracy(options) : 0;
}