/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_c.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: julesqvgn <julesqvgn@student.42.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/01/17 23:27:03 by nivergne          #+#    #+#             */
/*   Updated: 2019/01/25 23:31:57 by julesqvgn        ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

//#include "ft_printf.h"
#include "../include/ft_printf.h"

void	ft_addchar(va_list ap, t_info *options)
{	
	char	cast_ap;

	cast_ap = va_arg(ap, int);
	if (cast_ap == 0)
	{
		if (options->minus == 1)
			char_null(options);
		addwidth_char(options->width, options);
		if (options->minus == 0)
			char_null(options);
	}
	else if (options->width > 0)
	{
		if (options->minus == 1)
			append_to_buff(cast_ap, 0, options);
		addwidth_char(options->width, options);
		if (options->minus == 0)
			append_to_buff(cast_ap, 0, options);
	}
	else if (options->width == 0)
		append_to_buff(cast_ap, 0, options);
}
