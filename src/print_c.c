/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_c.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nivergne <nivergne@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/01/17 23:27:03 by nivergne          #+#    #+#             */
/*   Updated: 2019/02/02 07:22:14 by nivergne         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

//#include "ft_printf.h"
#include "../include/ft_printf.h"

void	ft_addchar(va_list ap, t_info *options)
{	
	int		cast_ap;

	if (options->type == 2 || options->conversion == 12)
	{
		ft_addwchar(ap, options);
		return ;
	}
	cast_ap = va_arg(ap, int);
	/*if (cast_ap < 32 && cast_ap >= 0)
	{
		if (options->minus == 1)
			char_null(cast_ap, options);
		addwidth_char(options->width, options);
		if (options->minus == 0)
			char_null(cast_ap, options);
	}
	else
	{*/
		if (options->minus == 1)
			append_to_buff(' ' + cast_ap - 32, 0, options);
		addwidth_char(options->width, options);
		if (options->minus == 0)
			append_to_buff(' ' + cast_ap - 32, 0, options);
	//}
}

void	ft_addwchar(va_list ap, t_info *options)
{
	wchar_t	cast_ap;

	cast_ap = va_arg(ap, wchar_t);
	if (options->minus == 1)
	{
		append_to_buff(0, 1, options);
		ft_putwchar(cast_ap, options);
		options->ret++;
	}
	addwidth_char(options->width, options);
	if (options->minus == 0)
	{
		append_to_buff(0, 1, options);
		ft_putwchar(cast_ap, options);
		options->ret++;
	}
}

void	ft_putwchar(wchar_t c, t_info *options)
{
	if (c <= 0x7F)
		ft_putchar(c);
	else if (c <= 0x7FF)
	{
		ft_putchar((c >> 6) | 0xC0);
		ft_putchar((c & 0x3F) | 0x80);
		options->ret++;
	}
	else if (c <= 0xFFFF)
	{
		ft_putchar((c >> 12) | 0xE0);
		ft_putchar(((c >> 6) & 0x3F) | 0x80);
		ft_putchar((c & 0x3F) | 0x80);
		options->ret ++;
	}
	else if (c <= 0x10FFFF)
	{
		ft_putchar((c >> 18) | 0xF0);
		ft_putchar(((c >> 12) & 0x3F) | 0x80);
		ft_putchar(((c >> 6) & 0x3F) | 0x80);
		ft_putchar((c & 0x3F) | 0x80);
		options->ret ++;
	}
}
