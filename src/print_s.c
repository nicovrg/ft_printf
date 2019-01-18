/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_s.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nivergne <nivergne@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/12/28 02:16:02 by nivergne          #+#    #+#             */
/*   Updated: 2019/01/17 23:36:42 by nivergne         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

//#include "ft_printf.h"
#include "../include/ft_printf.h"

void	ft_addstr(va_list ap, t_info *options)
{	
	char	*cast_ap;

	cast_ap = va_arg(ap, char *);
	if (options->width > 0)
	{
		if (options->minus == 1)
		{
			addbuff(cast_ap, options);
			addwidth_string(options->width, cast_ap);		
		}
		else
		{
			addwidth_string(options->width, cast_ap);		
			addbuff(cast_ap, options);
		}
	}
	else if (options->width == -1)
		addbuff(cast_ap, options);		
}
