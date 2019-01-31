/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_x.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jquivogn <jquivogn@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/01/04 21:51:28 by nivergne          #+#    #+#             */
/*   Updated: 2019/01/31 21:11:27 by jquivogn         ###   ########.fr       */
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
		cast = (options->type == 3 ? ft_itoa_base((unsigned char)(va_arg(ap, unsigned int)), 16, 1) : cast);	
		cast = (options->type == 1 ? ft_itoa_base((unsigned short)(va_arg(ap, unsigned int)), 16, 1) : cast);
		cast = (options->type == 2 ? ft_itoa_base(va_arg(ap, unsigned long), 16, 1) : cast);
		cast = (options->type == 4 ? ft_itoa_base(va_arg(ap, unsigned long long), 16, 1) : cast);
		if (cast[0] == '0')
			hex_for_null(options);
		else
			ft_addhexmin(cast, options);
	}
	else if (options->conversion == 8)
	{
		cast = (options->type == 0 ? ft_itoa_base(va_arg(ap, unsigned int), 16, 0) : 0);
		cast = (options->type == 3 ? ft_itoa_base((unsigned char)(va_arg(ap, unsigned int)), 16, 0) : cast);
		cast = (options->type == 1 ? ft_itoa_base((unsigned short)(va_arg(ap, unsigned int)), 16, 0) : cast);
		cast = (options->type == 2 ? ft_itoa_base(va_arg(ap, unsigned long), 16, 0) : cast);
		cast = (options->type == 4 ? ft_itoa_base(va_arg(ap, unsigned long long), 16, 0) : cast);
		if (cast[0] == '0')
			hex_for_null(options);
		else
			ft_addhexmaj(cast, options);
	}
}

void	ft_addhexmin(char *cast_ap, t_info *options)
{
	int			size;

	size = width_size_x(options, cast_ap);
	options->minus == 1 && options->hashtag == 2 ? addbuff("0x", options) : 0;
	options->accuracy > 0 && options->minus ? ft_accuracy(options) : 0;
	options->minus == 1 ? addbuff(cast_ap, options) : 0;
	if (options->zero && options->accuracy == -1)
		options->minus == 0 && options->hashtag == 2 ? addbuff("0x", options) : 0;
	if (options->width >= 0 && size > 0)
		while (size--)
			append_to_buff(options->zero && !options->minus &&
				options->accuracy < 0 ? '0' : ' ', 0, options);
	if (!(options->zero && options->accuracy == -1))
		options->minus == 0 && options->hashtag == 2 ? addbuff("0x", options) : 0;
	options->accuracy > 0 && !options->minus ? ft_accuracy(options) : 0;
	options->minus == 0 ? addbuff(cast_ap, options) : 0;
	free(cast_ap);
}

void	ft_addhexmaj(char *cast_ap, t_info *options)
{
	int			size;

	size = width_size_x(options, cast_ap);
	options->minus == 1 && options->hashtag == 2 ? addbuff("0X", options) : 0;
	options->accuracy > 0 && options->minus ? ft_accuracy(options) : 0;
	options->minus == 1 ? addbuff(cast_ap, options) : 0;
	if (options->zero && options->accuracy == -1)
		options->minus == 0 && options->hashtag == 2 ? addbuff("0X", options) : 0;
	if (options->width >= 0 && size > 0)
		while (size--)
			append_to_buff(options->zero && !options->minus &&
				options->accuracy < 0 ? '0' : ' ', 0, options);
	if (!(options->zero && options->accuracy == -1))
		options->minus == 0 && options->hashtag == 2 ? addbuff("0X", options) : 0;
	options->accuracy > 0 && !options->minus ? ft_accuracy(options) : 0;
	options->minus == 0 ? addbuff(cast_ap, options) : 0;
	free(cast_ap);
}

void	hex_for_null(t_info *options)
{
	options->accuracy > 0 && options->minus ? ft_accuracy(options) : 0;
	options->minus && options->accuracy < 0 ? ft_addnbr_core(0, options) : 0;
	if (options->accuracy > 1)
		options->width = options->width - (options->accuracy >= 1 ?
			options->accuracy : 1);
	else if (options->accuracy == 1)
		options->width = options->width - (options->accuracy >= 1 ?
			options->accuracy : 1);
	else if (options->accuracy < 0)
		options->width--;
	while (options->width-- > 0)
		append_to_buff(options->zero && !options->minus &&
				options->accuracy < 0 ? '0' : ' ', 0, options);
	options->accuracy > 0 && !options->minus ? ft_accuracy(options) : 0;
	!options->minus && options->accuracy < 0 ? ft_addnbr_core(0, options) : 0;
}
