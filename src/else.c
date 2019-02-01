/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   else.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: julesqvgn <julesqvgn@student.42.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/01/08 22:16:08 by nivergne          #+#    #+#             */
/*   Updated: 2019/02/01 01:24:54 by julesqvgn        ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

//#include "ft_printf.h"
#include "../include/ft_printf.h"

int		t_info_init(t_info *options, int i)
{
	options->zero = 0;
	options->plus = 0;
	options->minus = 0;
	options->space = 0;
	options->hashtag = 0;
	options->percent = 0;
	options->neg = 0;
	options->width = -1;
	options->accuracy = -1;
	options->type = 0;
	options->conversion = -1;
	options->llmin = 0;
	if (i == 0)
	{
		options->ret = 0;
		options->index = 0;
		ft_bzero(&options->buff, BUFF_SIZE);
	}
	return (0);
}

int		ft_accuracy(t_info *options)
{
	int accu;

	accu = options->accuracy;
	while(accu-- > 0)
		append_to_buff('0', 0, options);
	return (0);
}

void	usage()
{
	ft_putstr("ft_printf usage:\n");
	ft_putstr("write usage\n");
	exit(-1);
}
