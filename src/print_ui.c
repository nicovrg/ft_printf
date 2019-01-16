/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_ui.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nivergne <nivergne@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/01/11 03:18:33 by nivergne          #+#    #+#             */
/*   Updated: 2019/01/15 18:56:26 by nivergne         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/ft_printf.h"

void	ft_addnbr_core(long long nb, t_info *options)
{
	if (nb < 0)
	{
		append_to_buff('-', 0);
		nb = -nb;
	}
	if (nb >= 10)
	{
		ft_addnbr_core(nb / 10, options);
		append_to_buff(nb % 10 + '0', 0);
	}
	else
		append_to_buff(nb % 10 + '0', 0);
}

void	ft_addnbr(va_list ap, t_info *options)
{
	long long 	cast_ap;
	
	cast_ap = va_arg(ap, long long);
	ft_addnbr_core(cast_ap, options);
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

void    ft_adduns(va_list ap, t_info *options)
{
	unsigned long long		cast_ap;
	
	cast_ap = va_arg(ap, unsigned long long);
    ft_adduns_core(cast_ap, options);
}