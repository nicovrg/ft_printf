/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   else.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nivergne <nivergne@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/01/08 22:16:08 by nivergne          #+#    #+#             */
/*   Updated: 2019/01/18 20:18:59 by nivergne         ###   ########.fr       */
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
    exit(-1);
}
