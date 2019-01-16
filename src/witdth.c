/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   witdth.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nivergne <nivergne@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/01/11 22:11:13 by nivergne          #+#    #+#             */
/*   Updated: 2019/01/16 02:06:56 by nivergne         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/ft_printf.h"

void        addwidth_char(int nb)
{
    while (nb > 1)
    {
        append_to_buff(' ', 0);
        nb--;
    }
}

void        addwidth_string(int nb, char *cast_ap)
{
    int len;

    len = nb - ft_strlen(cast_ap);
    while (len > 0)
    {
        append_to_buff(' ', 0);
        len--;
    }
}
