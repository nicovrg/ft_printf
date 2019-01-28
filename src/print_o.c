/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_o.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jquivogn <jquivogn@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/01/17 23:33:38 by nivergne          #+#    #+#             */
/*   Updated: 2019/01/28 19:59:28 by jquivogn         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

//#include "ft_printf.h"
#include "../include/ft_printf.h"

void	ft_oct(va_list ap, t_info *options)
{
	unsigned long long	cast;

	if (options->type == 0)
		options->type = 2;
	cast = (options->type == 0 ? (unsigned int)itooct(va_arg(ap, unsigned int)) : 0);
	cast = (options->type == 3 ? (unsigned char)itooct(va_arg(ap, unsigned int)) : cast);
	cast = (options->type == 1 ? (unsigned short)itooct(va_arg(ap, unsigned int)) : cast);
	cast = (options->type == 2 ? itooct(va_arg(ap, unsigned long)) : cast);
	cast = (options->type == 4 ? itooct(va_arg(ap, unsigned long long)) : cast);
	if (cast == 0 && options->accuracy == 0)
	{
		width_for_null(options);
		return ;
	}
	ft_addoct(cast, options);
}

void	ft_addoct(unsigned long long cast_ap, t_info *options)
{
	int 		size;
	
	size = width_size_o(options, cast_ap);
	options->accuracy > 0 && options->minus ? ft_accuracy(options) : 0;
	options->minus == 1 && options->hashtag == 1 ? append_to_buff('0', 0, options) : 0;
	options->minus == 1 ? ft_adduns_core(cast_ap, options) : 0;
	if (options->width >= 0 && size > 0)
		while (size--)
			append_to_buff(options->zero && !options->minus &&
				options->accuracy < 0 ? '0' : ' ', 0, options);
	options->accuracy > 0 && !options->minus ? ft_accuracy(options) : 0;
	options->minus == 0 && options->hashtag == 1 ? append_to_buff('0', 0, options) : 0;
	options->minus == 0 ? ft_adduns_core(cast_ap, options) : 0;
}
