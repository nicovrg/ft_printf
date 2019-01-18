/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_%.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nivergne <nivergne@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/01/17 23:30:14 by nivergne          #+#    #+#             */
/*   Updated: 2019/01/17 23:36:21 by nivergne         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

//#include "ft_printf.h"
#include "../include/ft_printf.h"

void	ft_addpercent(va_list __unused ap, t_info *options)
{
	int		i;

	if (options->minus == 1)
		append_to_buff('%', 0);
	i = options->width;
	while (i-- > 1)
		append_to_buff(options->zero == 0 ? ' ' : '0', 0);
	if (options->minus == 0)
		append_to_buff('%', 0);
}
