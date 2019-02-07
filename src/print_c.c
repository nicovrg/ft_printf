/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_c.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nivergne <nivergne@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/01/17 23:27:03 by nivergne          #+#    #+#             */
/*   Updated: 2019/02/07 21:32:39 by nivergne         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

//#include "ft_printf.h"
#include "../include/ft_printf.h"

void			ft_addchar(va_list ap, t_info *o)
{
	int	cast_ap;

	if (o->type == 2 || o->conversion == 12)
	{
		ft_addwchar(ap, o);
		return ;
	}
	cast_ap = va_arg(ap, int);
	if (cast_ap < 32 && cast_ap >= 0)
	{
		char_null(cast_ap, o);
	}
	else
	{
		if (o->minus == 1)
			append_to_buff(' ' + cast_ap - 32, 0, o);
		addwidth_char(o->width, o);
		if (o->minus == 0)
			append_to_buff(' ' + cast_ap - 32, 0, o);
	}
}

void			ft_addwchar(va_list ap, t_info *o)
{
	wchar_t	cast_ap;

	cast_ap = va_arg(ap, wchar_t);
	if (o->minus == 1)
	{
		append_to_buff(0, 1, o);
		ft_putwchar(cast_ap, o);
		o->ret++;
	}
	addwidth_wchar(cast_ap, o->width, o);
	if (o->minus == 0)
	{
		append_to_buff(0, 1, o);
		ft_putwchar(cast_ap, o);
		o->ret++;
	}
}

void			ft_putwchar(wchar_t c, t_info *o)
{
	if (c <= 0x7F)
		ft_putchar(c);
	else if (c <= 0x7FF)
	{
		ft_putchar((c >> 6) | 0xC0);
		ft_putchar((c & 0x3F) | 0x80);
		o->ret++;
	}
	else if (c <= 0xFFFF)
	{
		ft_putchar((c >> 12) | 0xE0);
		ft_putchar(((c >> 6) & 0x3F) | 0x80);
		ft_putchar((c & 0x3F) | 0x80);
		o->ret += 2;
	}
	else if (c <= 0x10FFFF)
	{
		ft_putchar((c >> 18) | 0xF0);
		ft_putchar(((c >> 12) & 0x3F) | 0x80);
		ft_putchar(((c >> 6) & 0x3F) | 0x80);
		ft_putchar((c & 0x3F) | 0x80);
		o->ret += 3;
	}
}

void			addwidth_wchar(wchar_t c, int nb, t_info *o)
{
	if (c <= 0x7F)
		nb--;
	else if (c <= 0x7FF)
		nb -= 2;
	else if (c <= 0xFFFF)
		nb -= 3;
	else if (c <= 0x10FFFF)
		nb -= 4;
	while (nb > 0)
	{
		append_to_buff(o->zero && !o->minus && o->accuracy < 0
		? '0' : ' ', 0, o);
		nb--;
	}
}
