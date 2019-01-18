/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_h.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nivergne <nivergne@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/01/04 21:51:28 by nivergne          #+#    #+#             */
/*   Updated: 2019/01/17 23:34:49 by nivergne         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

//#include "ft_printf.h"
#include "../include/ft_printf.h"

void    ft_addhexmin(va_list ap, t_info *options)
{
    unsigned long long cast_ap;

    cast_ap = va_arg(ap, unsigned long long);
    addbuff(ft_itoa_base(cast_ap, 16, 1), options);
}

void    ft_addhexmaj(va_list ap, t_info *options)
{
    unsigned long long cast_ap;

    cast_ap = va_arg(ap, unsigned long long);
    addbuff(ft_itoa_base(cast_ap, 16, 0), options);
}
