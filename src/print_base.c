/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_base.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nivergne <nivergne@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/01/04 21:51:28 by nivergne          #+#    #+#             */
/*   Updated: 2019/01/17 04:28:54 by nivergne         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

//#include "ft_printf.h"
#include "../include/ft_printf.h"

void    ft_addbin(va_list ap, t_info *options)
{
    unsigned long long cast_ap;

    cast_ap = va_arg(ap, unsigned long long);
    addbuff(ft_itoa_base(cast_ap, 2, 0), options);
}

void	ft_oct(va_list ap, t_info *options)
{
	long long   cast;

	cast = (options->type == 0 ? atoi(ft_itoa_base(va_arg(ap, int), 8, 0)) : 0); //libft pour atoi!!!!!!!!!!!!!!!!!!!!!!!!!!
	cast = (options->type == 3 ? atoi(ft_itoa_base(va_arg(ap, int), 8, 0)) : cast);
	cast = (options->type == 1 ? atoi(ft_itoa_base(va_arg(ap, int), 8, 0)) : cast);
	cast = (options->type == 2 ? atoi(ft_itoa_base(va_arg(ap, long), 8, 0)) : cast);
	cast = (options->type == 4 ? atoi(ft_itoa_base(va_arg(ap, long long), 8, 0)) : cast);
	ft_addoct(cast, options);
}

void    ft_addoct(long long cast_ap, t_info *options)
{
    int 		size;
	
	size = width_size(options, cast_ap, 8);
	options->accuracy > 0 && options->minus ? ft_accuracy(options) : 0;
    options->hashtag && options->minus ? append_to_buff('0', 0) : 0;
	if (options->minus == 1)
		ft_addnbr_core(cast_ap, options);
	if (options->width >= 0 && size > 0)
		while (size--)
			append_to_buff(options->zero && !options->minus ? '0' : ' ', 0);
	options->accuracy > 0 && !options->minus ? ft_accuracy(options) : 0;
    options->hashtag && !options->minus ? append_to_buff('0', 0) : 0;
	if (options->minus == 0)
		ft_addnbr_core(cast_ap, options);
}

void    ft_addhexmin(va_list ap, t_info *options)
{
    unsigned long long cast_ap;

    cast_ap = va_arg(ap, unsigned long long);
    addbuff(ft_itoa_base(cast_ap, 16, 1), options);
}

void    ft_addhexmaj(va_list ap, t_info *options)
{
    unsigned long long cast_ap;

    cast_ap = va_arg(ap, unsigned long long);
    addbuff(ft_itoa_base(cast_ap, 16, 0), options);
}
