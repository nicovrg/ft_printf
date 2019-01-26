/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_f.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nivergne <nivergne@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/01/26 21:19:05 by nivergne          #+#    #+#             */
/*   Updated: 2019/01/27 00:01:39 by nivergne         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

//#include "ft_printf.h"
#include "../include/ft_printf.h"

void    ft_addfloat(float nb, t_info *options)
{
    int i;
    int tmp;

    i = 0;
    tmp = 0;
    if ((uint32_t)nb & 1 << 31)
        append_to_buff('-', 0, options);
    while ((uint32_t)nb & 1 << 23 + i)
    {
        if ((uint32_t)nb & 1 << 23 + i)
            ;
        i++;
    }

}