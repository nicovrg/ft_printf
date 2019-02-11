/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_f.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: julesqvgn <julesqvgn@student.42.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/01/26 21:19:05 by nivergne          #+#    #+#             */
/*   Updated: 2019/02/11 02:28:30 by julesqvgn        ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	ft_padding(t_info *o)
{
	o->plus && !o->neg
	? append_to_buff('+', 0, o) : 0;
	!o->plus && !o->neg && o->space
	? append_to_buff(' ', 0, o) : 0;
}

void	ft_mantis(t_info *o, long double cast_ap, int flag, long long left)
{
	long long tmp;

	tmp = 0;
	if (o->accuracy == 0)
	{
		cast_ap *= 10;
		left = 0;
		left += ((int)cast_ap % 10);
		if (left >= 5)
			o->hashtag ? o->buff[o->index - 2]++ : o->buff[o->index - 1]++;
	}
	while (o->accuracy > 0 && cast_ap)
	{
		if (tmp > 2147483647)
		{
			ft_addnbr_core(tmp, o);
			cast_ap -= tmp;
			tmp = 0;
		}
		else
		{
			cast_ap *= 10;
			if ((int)cast_ap == 0)
			{
				while ((int)cast_ap == 0 && o->accuracy > 0)
				{
					append_to_buff('0', 0, o);
					cast_ap *= 10;
					o->accuracy--;
				}
			}
			else
			{
			tmp *= 10;
			tmp += ((long long)cast_ap % 10);
			o->accuracy--;
			}
		}
	}
	while (o->accuracy-- > 1)
		append_to_buff('0', 0, o);
	cast_ap *= 10;
	left = 0;
	left += ((int)cast_ap % 10);
	if (left >= 5)
		tmp++;
	if (!flag)
		ft_addnbr_core(tmp, o);
}

void	ft_addfloat(va_list ap, t_info *o)
{
	long long	left;
	long double	cast_ap;
	int			flag;
	int			size;

	flag = 0;
	cast_ap = o->type != 4 ? (double)va_arg(ap, double) : 0;
	cast_ap = o->type == 4 ? (long double)va_arg(ap, long double) : cast_ap;
	left = (long long)cast_ap;
	size = width_size_float(o, left);
	cast_ap = cast_ap - left;
	if (cast_ap < 0)
	{
		o->neg = 1;
		cast_ap *= -1;
	}
	if (o->accuracy == 0 && left != 0)
	{
		flag = 1;
		if ((int)(cast_ap * 10) % 10 >= 5)
			left = left >= 0 ? left++ : left--;
	}
	if (o->accuracy == -1)
		o->accuracy = 6;
	if (o->width >= 0 && size > 0)
		while (size-- > 0)
			append_to_buff(o->zero && !o->minus
			&& o->accuracy < 0 ? '0' : ' ', 0, o);
	ft_padding(o);
	ft_addnbr_core(left, o);
	if (!(!o->hashtag && o->accuracy == 0))
		append_to_buff('.', 0, o);
	ft_mantis(o, cast_ap, flag, left);
}

int			width_size_float(t_info *o, long long cast_ap)
{
	int width;
	int size_nb;

	size_nb = cast_ap == 0 ? 1 : 0;
	width = o->width;
	cast_ap < 0 ? size_nb++ : 0;
	size_nb += 1 + o->accuracy;
	cast_ap < 0 ? cast_ap *= -1 : 0;
	while (cast_ap > 0)
	{
		cast_ap /= 10;
		size_nb++;
	}
	width = width - (o->accuracy > size_nb ? o->accuracy : size_nb)
		- (o->plus && !o->neg ? 1 : 0) - (o->neg ? 1 : 0)
		- (o->space == 1 && !o->plus && !o->neg ? 1 : 0);
	return (width);
}
