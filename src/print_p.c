/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_p.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jquivogn <jquivogn@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/01/17 23:29:11 by nivergne          #+#    #+#             */
/*   Updated: 2019/02/04 15:57:25 by jquivogn         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

//#include "ft_printf.h"
#include "../include/ft_printf.h"

void	ft_addaddr(va_list ap, t_info *options)
{
	void *cast;
	char *tmp;

	cast = (options->type == 0 ? ft_itoa_base(va_arg(ap, unsigned int), 16, 1) : 0);
	cast = (options->type == 3 ? ft_itoa_base((unsigned char)(va_arg(ap, unsigned int)), 16, 1) : cast);	
	cast = (options->type == 1 ? ft_itoa_base((unsigned short)(va_arg(ap, unsigned int)), 16, 1) : cast);
	cast = (options->type == 2 ? ft_itoa_base(va_arg(ap, unsigned long), 16, 1) : cast);
	cast = (options->type == 4 ? ft_itoa_base(va_arg(ap, unsigned long long), 16, 1) : cast);
	tmp = ft_strjoin("0x", cast);
	free(cast);
	cast = tmp;
	if (options->hashtag == 1)
		options->hashtag = 0;
	ft_addhexmin(cast, options);
}
