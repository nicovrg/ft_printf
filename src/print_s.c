/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_s.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nivergne <nivergne@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/12/28 02:16:02 by nivergne          #+#    #+#             */
/*   Updated: 2019/01/24 22:43:05 by nivergne         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

//#include "ft_printf.h"
#include "../include/ft_printf.h"

void	ft_addstr(va_list ap, t_info *options)
{	
	char	*cast_ap;
	char	*tmp;

	cast_ap = va_arg(ap, char *);
	if (!cast_ap)
		cast_ap = "(null)";
	tmp = cast_ap;
	if (options->accuracy > 0)
		cast_ap[options->accuracy] = '\0';
	if (options->width > 0)
	{
		options->minus == 1 ? addbuff(cast_ap, options) : 0;
		addwidth_string(options->width, tmp, options);				
		options->minus == 0 ? addbuff(cast_ap, options) : 0;
	}
	else if (options->width == -1)
		addbuff(cast_ap, options);
}
