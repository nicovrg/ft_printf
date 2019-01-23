/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   width_diou.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nivergne <nivergne@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/01/11 22:11:15 by nivergne          #+#    #+#             */
/*   Updated: 2019/01/23 16:04:46 by nivergne         ###   ########.fr       */
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

int     width_size_x(t_info *options, char *cast_ap)
{
    int width;
    int size_nb;

    width = options->width;
    size_nb = ft_strlen(cast_ap) + options->hashtag == 1 ? 2 : 0;
    width = width - (options->accuracy > size_nb ? options->accuracy : size_nb);
    options->accuracy = options->accuracy - size_nb;
    return (width);
}