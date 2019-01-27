/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_x.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: julesqvgn <julesqvgn@student.42.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/01/04 21:51:28 by nivergne          #+#    #+#             */
/*   Updated: 2019/01/27 13:48:41 by julesqvgn        ###   ########.fr       */
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
		if (cast[0] == '0' && options->accuracy == 0)
		{
			width_for_null(options);
			return ;
		}
		ft_addhexmin(cast, options);
	}
	else if (options->conversion == 8)
	{
		cast = (options->type == 0 ? ft_itoa_base(va_arg(ap, unsigned int), 16, 0) : 0);
		cast = (options->type == 3 ? ft_itoa_base(va_arg(ap, unsigned int), 16, 0) : cast);
		cast = (options->type == 1 ? ft_itoa_base(va_arg(ap, unsigned int), 16, 0) : cast);
		cast = (options->type == 2 ? ft_itoa_base(va_arg(ap, unsigned long), 16, 0) : cast);
		cast = (options->type == 4 ? ft_itoa_base(va_arg(ap, unsigned long long), 16, 0) : cast);
		if (cast[0] == '0' && options->accuracy == 0)
		{
			width_for_null(options);
			return ;
		}
		ft_addhexmaj(cast, options);
	}
}

void	ft_addhexmin(char *cast_ap, t_info *options)
{
	int			size;

	size = width_size_x(options, cast_ap);
	if (options->hashtag && options->accuracy < 0 && options->zero && size > 0)
	{
		addbuff("0x", options);
		options->hashtag = 0;
	}	
	if (options->minus)
	{
		options->hashtag && cast_ap[0] != '0' ? addbuff("0x", options) : 0;
		options->accuracy > 0 ? ft_accuracy(options) : 0;
		addbuff(cast_ap, options);
	}
	if (options->width >= 0 && size > 0)
		while (size--)
			append_to_buff(options->zero && !options->minus ? '0' : ' ', 0, options);
	if (!options->minus)
	{
		options->hashtag && cast_ap[0] != '0' ? addbuff("0x", options) : 0;
		options->accuracy > 0 ? ft_accuracy(options) : 0;
		addbuff(cast_ap, options);
	}
	free(cast_ap);
}

void	ft_addhexmaj(char *cast_ap, t_info *options)
{
	int			size;

	size = width_size_x(options, cast_ap);
	if (options->hashtag && options->accuracy < 0 && options->zero && size > 0)
	{
		addbuff("0X", options);
		options->hashtag = 0;
	}	
	if (options->minus == 1)
	{
		options->hashtag && cast_ap[0] != '0' ? addbuff("0X", options) : 0;
		options->accuracy > 0 ? ft_accuracy(options) : 0;
		addbuff(cast_ap, options);
	}
	if (options->width >= 0 && size > 0)
		while (size--)
			append_to_buff(options->zero && !options->minus ? '0' : ' ', 0, options);
	if (!options->minus)
	{
		options->hashtag && cast_ap[0] != '0' ? addbuff("0X", options) : 0;
		options->accuracy > 0 ? ft_accuracy(options) : 0;
		addbuff(cast_ap, options);
	}
	free(cast_ap);
}
