/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_x.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nivergne <nivergne@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/01/04 21:51:28 by nivergne          #+#    #+#             */
/*   Updated: 2019/01/23 16:42:40 by nivergne         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

//#include "ft_printf.h"
#include "../include/ft_printf.h"

void	ft_hex(va_list ap, t_info *options)
{
    char *cast;

	if (options->conversion == 7)
	{
		cast = (options->type == 0 ? ft_itoa_base(va_arg(ap, unsigned int), 16, 1) : 0);
		cast = (options->type == 3 ? ft_itoa_base(va_arg(ap, unsigned int), 16, 1) : cast);	
		cast = (options->type == 1 ? ft_itoa_base(va_arg(ap, unsigned int), 16, 1) : cast);
		cast = (options->type == 2 ? ft_itoa_base(va_arg(ap, unsigned long), 16, 1) : cast);
		cast = (options->type == 4 ? ft_itoa_base(va_arg(ap, unsigned long long), 16, 1) : cast);
		ft_addhexmin(cast, options);
	}
	else if (options->conversion == 8)
	{
		cast = (options->type == 0 ? ft_itoa_base(va_arg(ap, unsigned int), 16, 0) : 0);
		cast = (options->type == 3 ? ft_itoa_base(va_arg(ap, unsigned int), 16, 0) : cast);
		cast = (options->type == 1 ? ft_itoa_base(va_arg(ap, unsigned int), 16, 0) : cast);
		cast = (options->type == 2 ? ft_itoa_base(va_arg(ap, unsigned long), 16, 0) : cast);
		cast = (options->type == 4 ? ft_itoa_base(va_arg(ap, unsigned long long), 16, 0) : cast);
		ft_addhexmaj(cast, options);
	}
}

void    ft_addhexmin(char *cast_ap, t_info *options)
{
	int			count;
	
	count = width_size_x(options, cast_ap);
	printf("count = %d\n", count);
	if (options->hashtag == 1)
		addbuff("0x", options);
	if (options->minus == 1)
	{
		if (options->accuracy > -1)
			while (options->accuracy--)
				append_to_buff(' ', 0);
		addbuff(cast_ap, options);
	}		
	while (options->width-- > 0)
	{
			if (options->minus == 0 && options->width > count)
				append_to_buff(options->zero ? '0' : ' ', 0);
			else
				append_to_buff(' ', 0);
	}
	if (options->accuracy >= 0 && options->accuracy > count)
		options->accuracy -= count;
	//while (options->accuracy-- > 0)
	//		append_to_buff('0', 0);
	options->minus == 1 ? 0 : addbuff(cast_ap, options);
}

void    ft_addhexmaj(char *cast_ap, t_info *options)
{
    int 		size;
	
	size = width_size_x(options, cast_ap);
	options->plus && options->minus && cast_ap >= 0 ? append_to_buff('+', 0) : 0;
	options->accuracy > 0 && options->minus ? ft_accuracy(options) : 0;
	if (options->width >= 0 && size > 0)
		while (size--)
			append_to_buff(options->zero && !options->minus ? '0' : ' ', 0);
	options->plus && !options->minus && cast_ap >= 0 ? append_to_buff('+', 0) : 0;
	options->accuracy > 0 && !options->minus ? ft_accuracy(options) : 0;
	addbuff(cast_ap, options);
}