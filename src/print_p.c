/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_p.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: julesqvgn <julesqvgn@student.42.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/01/17 23:29:11 by nivergne          #+#    #+#             */
/*   Updated: 2019/02/07 15:22:47 by julesqvgn        ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

//#include "ft_printf.h"
#include "../include/ft_printf.h"

void	ft_addaddr(va_list ap, t_info *options)
{
	void *cast;
	char *tmp;

	cast = ft_itoa_base(va_arg(ap, unsigned long long), 16, 1);
	tmp = ft_strjoin("0x", cast);
	free(cast);
	cast = tmp;
	if (options->hashtag == 1)
		options->hashtag = 0;
	ft_addhexmin(cast, options);
}
