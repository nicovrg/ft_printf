/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_x.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nivergne <nivergne@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/01/04 21:51:28 by nivergne          #+#    #+#             */
/*   Updated: 2019/01/18 20:35:23 by nivergne         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

//#include "ft_printf.h"
#include "../include/ft_printf.h"

void	ft_hex(va_list ap, t_info *options)
{
    char *cast;

	if (options->conversion == 7)
	{
		cast = (options->type == 0 ? ft_itoa_base(va_arg(ap, int), 16, 1) : 0);
		cast = (options->type == 3 ? ft_itoa_base(va_arg(ap, int), 16, 1) : cast);	
		cast = (options->type == 1 ? ft_itoa_base(va_arg(ap, long ), 16, 1) : cast);
		cast = (options->type == 2 ? ft_itoa_base(va_arg(ap, long long), 16, 1) : cast);
		cast = (options->type == 4 ? ft_itoa_base(va_arg(ap, long long), 16, 1) : cast);
		ft_addhexmin(cast, options);
	}
	else if (options->conversion == 8)
	{
		cast = (options->type == 0 ? ft_itoa_base(va_arg(ap, int), 16, 0) : 0);
		cast = (options->type == 3 ? ft_itoa_base(va_arg(ap, int), 16, 0) : cast);
		cast = (options->type == 1 ? ft_itoa_base(va_arg(ap, long ), 16, 0) : cast);
		cast = (options->type == 2 ? ft_itoa_base(va_arg(ap, long long), 16, 0) : cast);
		cast = (options->type == 4 ? ft_itoa_base(va_arg(ap, long long), 16, 0) : cast);
		ft_addhexmaj(cast, options);
	}
}

void    ft_addhexmin(char *cast_ap, t_info *options)
{
    int 		size_nb;
	int			size_space;
	int			size_space_two;


	size_nb = ft_strlen(cast_ap);
	size_space = options->width - size_nb;
	size_space_two = options->width - options->accuracy - size_nb;
	if (options->width >= 0 && options->accuracy == -1 && size_space > 0)
		while (size_space--)
			append_to_buff(options->zero && !options->minus ? '0' : ' ', 0);
	else if (options->width >= 0 && options->accuracy >= 0 && size_space > 0)
		while (size_space_two--)
			append_to_buff(options->zero && !options->minus ? '0' : ' ', 0);
	
	//options->plus && options->minus && cast_ap >= 0 ? append_to_buff('+', 0) : 0;
	//options->accuracy > 0 && options->minus ? ft_accuracy(options) : 0;
	//if (options->width >= 0 && size > 0)
	//	while (size--)
	//		append_to_buff(options->zero && !options->minus ? '0' : ' ', 0);
	//options->plus && !options->minus && cast_ap >= 0 ? append_to_buff('+', 0) : 0;
	//options->accuracy > 0 && !options->minus ? ft_accuracy(options) : 0;
	addbuff(cast_ap, options);
}

void    ft_addhexmaj(char *cast_ap, t_info *options)
{
    int 		size;
	
	size = ft_strlen(cast_ap);
	options->plus && options->minus && cast_ap >= 0 ? append_to_buff('+', 0) : 0;
	options->accuracy > 0 && options->minus ? ft_accuracy(options) : 0;
	if (options->width >= 0 && size > 0)
		while (size--)
			append_to_buff(options->zero && !options->minus ? '0' : ' ', 0);
	options->plus && !options->minus && cast_ap >= 0 ? append_to_buff('+', 0) : 0;
	options->accuracy > 0 && !options->minus ? ft_accuracy(options) : 0;
	addbuff(cast_ap, options);
}