/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   witdth.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nivergne <nivergne@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/01/11 22:11:13 by nivergne          #+#    #+#             */
/*   Updated: 2019/01/16 01:06:11 by nivergne         ###   ########.fr       */
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

void        addwidth_string(int nb)
{


}
