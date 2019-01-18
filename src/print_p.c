/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_p.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nivergne <nivergne@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/01/17 23:29:11 by nivergne          #+#    #+#             */
/*   Updated: 2019/01/17 23:36:39 by nivergne         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

//#include "ft_printf.h"
#include "../include/ft_printf.h"

void    ft_addaddr(va_list ap, t_info *options)
{
	unsigned long long	cast_ap;
	
	cast_ap = va_arg(ap, unsigned long long);
	if (options->width > 0)
	{
		if (options->minus == 1)
		{
			addbuff("0x", options);	
			addbuff(ft_itoa_base(cast_ap, 16, 32), options);
			addwidth_pointer(options->width, (char *)cast_ap);
		}
		else 
		{
			addwidth_pointer(options->width, (char *)cast_ap);
			addbuff("0x", options);	
			addbuff(ft_itoa_base(cast_ap, 16, 32), options);
		}
	}
	else if (options->width == -1)
	{
		addbuff("0x", options);	
		addbuff(ft_itoa_base(cast_ap, 16, 32), options);
	}
}
