/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_u.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nivergne <nivergne@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/01/17 23:27:52 by nivergne          #+#    #+#             */
/*   Updated: 2019/01/17 23:36:44 by nivergne         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

//#include "ft_printf.h"
#include "../include/ft_printf.h"

void    ft_adduns(va_list ap, t_info *options)
{
	unsigned long long		cast_ap;
	
	cast_ap = va_arg(ap, unsigned long long);
    ft_adduns_core(cast_ap, options);
}

void    ft_adduns_core(unsigned long long nb, t_info *options)
{
	if (nb >= 10)
	{
		ft_adduns_core(nb / 10, options);
		append_to_buff(nb % 10 + '0', 0);
	}
	else
		append_to_buff(nb % 10 + '0', 0);
}
