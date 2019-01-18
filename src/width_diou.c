/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   width_diou.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nivergne <nivergne@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/01/11 22:11:15 by nivergne          #+#    #+#             */
/*   Updated: 2019/01/18 20:14:41 by nivergne         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

//#include "ft_printf.h"
#include "../include/ft_printf.h"

int     width_size_diou(t_info *options, long long cast_ap, int base)
{
    int width;
    int size_nb;

    size_nb = 0;
    width = options->width;
    if (cast_ap < 0)
    {
        cast_ap *= -1;
        size_nb++;
    }
    while (cast_ap > 0)
    {
        cast_ap /= base;
        size_nb++;
    }
    width = width - (options->accuracy > size_nb ? options->accuracy : size_nb)
        - (options->plus == 1 ? 1 : 0);
    options->accuracy = options->accuracy - size_nb;
    return (width);
}
