/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   else.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nivergne <nivergne@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/01/08 22:16:08 by nivergne          #+#    #+#             */
/*   Updated: 2019/01/17 01:38:29 by nivergne         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

//#include "ft_printf.h"
#include "../include/ft_printf.h"

int     t_info_init(t_info *options)
{
    options->zero = 0;
    options->plus = 0;
    options->minus = 0;
    options->space = 0;
    options->hashtag = 0;
    options->percent = 0;
    options->width = -1;
    options->accuracy = -1;
    options->type = 0;
    options->conversion = 0;
    return (0);
}

int     width_size(t_info *options, long long cast_ap)
{
    int width;
    int size_nb;

    size_nb = 0;
    width = options->width;
    if (cast_ap < 0)
    {
        size_nb++;
        cast_ap *= -1;
    }
    while (cast_ap > 0)
    {
        cast_ap /= 10;
        size_nb++;
    }
    width = width - (options->accuracy > size_nb ? options->accuracy : size_nb)
        - (options->plus == 1 ? 1 : 0);
    options->accuracy = options->accuracy - size_nb;
    return (width);
}

int     ft_accuracy(t_info *options)
{
    while(options->accuracy--)
        append_to_buff('0', 0);
    return (0);
}

void    usage()
{
    ft_putstr("ft_printf usage:\n");
    ft_putstr("write usage\n");
}
