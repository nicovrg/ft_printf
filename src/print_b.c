/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_b.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nivergne <nivergne@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/01/17 23:32:12 by nivergne          #+#    #+#             */
/*   Updated: 2019/01/17 23:36:24 by nivergne         ###   ########.fr       */
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
