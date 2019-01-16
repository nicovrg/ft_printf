/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   else.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nivergne <nivergne@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/01/08 22:16:08 by nivergne          #+#    #+#             */
/*   Updated: 2019/01/16 00:06:27 by nivergne         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/ft_printf.h"

int     t_info_init(t_info *options)
{
    options->zero = 0;
    options->plus = 0;
    options->minus = 0;
    options->space = 0;
    options->hashtag = 0;
    options->percent = 0;
    options->width = 0;
    options->accuracy = 0;
    options->type = 0;
    options->conversion = 0;
    //ft_bzero(options, sizeof(options));
    return (0);
}

void    usage()
{
    ft_putstr("ft_printf usage:\n");
    ft_putstr("write usage\n");
}

// void	ft_putstr(char const *s)
// {
// 	if (s != NULL)
// 		write(1, s, ft_strlen(s));
// }
