/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_base.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nivergne <nivergne@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/01/04 21:51:28 by nivergne          #+#    #+#             */
/*   Updated: 2019/01/16 23:31:30 by nivergne         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

//#include "ft_printf.h"
#include "../include/ft_printf.h"

void    ft_addbin(va_list ap, t_info *options)
{
    unsigned long long cast_ap;

    cast_ap = va_arg(ap, unsigned long long);
    addbuff(ft_itoa_base(cast_ap, 2, 0), options);
}

void    ft_addoct(va_list ap, t_info *options)
{
    unsigned long long cast_ap;

    cast_ap = va_arg(ap, unsigned long long);
    addbuff(ft_itoa_base(cast_ap, 8, 0), options);
}

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
