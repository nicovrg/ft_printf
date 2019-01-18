/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_c.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nivergne <nivergne@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/01/17 23:27:03 by nivergne          #+#    #+#             */
/*   Updated: 2019/01/17 23:36:27 by nivergne         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

//#include "ft_printf.h"
#include "../include/ft_printf.h"

void	ft_addchar(va_list ap, t_info *options)
{	
	char	cast_ap;

	cast_ap = va_arg(ap, int);
	if (options->width > 0)
	{
		if (options->minus == 1)
		{
			append_to_buff(cast_ap, 0);
			addwidth_char(options->width);
		}
		else
		{
			addwidth_char(options->width);
			append_to_buff(cast_ap, 0);
		}
	}
	else if (options->width == 0)
		append_to_buff(cast_ap, 0);
}
