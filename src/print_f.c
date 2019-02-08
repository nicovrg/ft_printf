/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_f.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jquivogn <jquivogn@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/01/26 21:19:05 by nivergne          #+#    #+#             */
/*   Updated: 2019/02/08 16:18:16 by jquivogn         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	ft_addfloat(va_list ap, t_info *o)
{
	long double			cast_ap;

	cast_ap = (long double)va_arg(ap, double);
	(void)o;
}
