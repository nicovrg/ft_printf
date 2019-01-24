/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_o.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nivergne <nivergne@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/01/17 23:33:38 by nivergne          #+#    #+#             */
/*   Updated: 2019/01/24 21:43:46 by nivergne         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

//#include "ft_printf.h"
#include "../include/ft_printf.h"

void	ft_oct(va_list ap, t_info *options)
{
	long long   cast;

	cast = (options->type == 0 ? ft_atoi(ft_itoa_base(va_arg(ap, int), 8, 0)) : 0);
	cast = (options->type == 3 ? ft_atoi(ft_itoa_base(va_arg(ap, int), 8, 0)) : cast);
	cast = (options->type == 1 ? ft_atoi(ft_itoa_base(va_arg(ap, int), 8, 0)) : cast);
	cast = (options->type == 2 ? ft_atoi(ft_itoa_base(va_arg(ap, long), 8, 0)) : cast);
	cast = (options->type == 4 ? ft_atoi(ft_itoa_base(va_arg(ap, long long), 8, 0)) : cast);
	if (cast == 0 && options->accuracy == 0)
	{
		width_for_null(options);
		return ;
	}
	ft_addoct(cast, options);
}

void	ft_addoct(long long cast_ap, t_info *options)
{
	int 		size;
	
	size = width_size_o(options, cast_ap);
	options->accuracy > 0 && options->minus ? ft_accuracy(options) : 0;
	options->minus == 1 && options->hashtag == 1 ? ft_addnbr_core(0, options) : 0;
	options->minus == 1 ? ft_addnbr_core(cast_ap, options) : 0;
	if (options->width >= 0 && size > 0)
		while (size--)
			append_to_buff(options->zero && !options->minus && options->accuracy < 0 ? '0' : ' ', 0, options);
	options->accuracy > 0 && !options->minus ? ft_accuracy(options) : 0;
	options->minus == 0 && options->hashtag == 1 ? ft_addnbr_core(0, options) : 0;
	options->minus == 0 ? ft_addnbr_core(cast_ap, options) : 0;
}
