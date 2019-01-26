/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   width_csp.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nivergne <nivergne@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/01/11 22:11:13 by nivergne          #+#    #+#             */
/*   Updated: 2019/01/26 23:04:36 by nivergne         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

//#include "ft_printf.h"
#include "../include/ft_printf.h"

void		addwidth_char(int nb, t_info *options)
{
	while (nb > 1)
	{
		append_to_buff(options->zero && !options->minus && options->accuracy < 0 ? '0' : ' ', 0, options);
		nb--;
	}
}

void		addwidth_string(int nb, char *cast_ap, t_info *options)
{
	int len;

	len = nb - ft_strlen(cast_ap);
	while (len > 0)
	{
		append_to_buff(options->zero && !options->minus && options->accuracy < 0 ? '0' : ' ', 0, options);
		len--;
	}
}

void		addwidth_pointer(int nb, char * __unused cast_ap, t_info *options)
{
	int len;

	len = nb - 11;
	while (len > 0)
	{
		append_to_buff(' ', 0, options);
		len--;
	}
}

void		char_null(t_info *options)
{
	options->ret++;
	options->buff[options->index++] = '^';
	if (options->index == BUFF_SIZE)
		append_to_buff(0, 1, options);
	options->buff[options->index++] = '@';
}