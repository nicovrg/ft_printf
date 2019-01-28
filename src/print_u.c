/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_u.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jquivogn <jquivogn@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/01/17 23:27:52 by nivergne          #+#    #+#             */
/*   Updated: 2019/01/28 18:50:21 by jquivogn         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

//#include "ft_printf.h"
#include "../include/ft_printf.h"

void	ft_uns(va_list ap, t_info *options)
{
	unsigned long long	cast_ap;

	cast_ap = (options->type == 0 ? va_arg(ap, unsigned int) : 0);
	cast_ap = (options->type == 1 ? (unsigned short)va_arg(ap, unsigned int) : cast_ap);
	cast_ap = (options->type == 3 ? (unsigned char)va_arg(ap, unsigned int) : cast_ap);
	cast_ap = (options->type == 2 ? va_arg(ap, unsigned long) : cast_ap);
	cast_ap = (options->type == 4 ? va_arg(ap, unsigned long long) : cast_ap);
	ft_adduns(cast_ap, options);
}

void	ft_adduns(long long cast_ap, t_info *options)
{
	int 		size;
	
	size = width_size_diou(options, cast_ap, 10);
	options->accuracy > 0 && options->minus ? ft_accuracy(options) : 0;
	if (options->minus == 1)
		ft_adduns_core(cast_ap, options);
	if (options->width >= 0 && size > 0)
		while (size--)
			append_to_buff(options->zero && !options->minus &&
				options->accuracy < 0 ? '0' : ' ', 0, options);
	options->accuracy > 0 && !options->minus ? ft_accuracy(options) : 0;
	if (options->minus == 0)
		ft_adduns_core(cast_ap, options);
}

void    ft_adduns_core(unsigned long long nb, t_info *options)
{
	if (nb >= 10)
	{
		ft_adduns_core(nb / 10, options);
		append_to_buff(nb % 10 + '0', 0, options);
	}
	else
		append_to_buff(nb % 10 + '0', 0, options);
}
