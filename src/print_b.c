/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_b.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jquivogn <jquivogn@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/01/17 23:32:12 by nivergne          #+#    #+#             */
/*   Updated: 2019/01/28 16:09:21 by jquivogn         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

//#include "ft_printf.h"
#include "../include/ft_printf.h"

void	ft_put_bit_to_buff(char cast_ap, t_info *options)
{
	int i;

	i = 256;
	while (i >>= 1)
		append_to_buff((cast_ap & i) ? '1' : '0', 0, options);
}

void	ft_addbin(va_list ap, t_info *options)
{
	char	cast_ap;
	int		size;

	cast_ap = (signed char)va_arg(ap, int);
	size = width_bin(options);
	if (options->minus)
	{
		options->space ? append_to_buff(' ', 0, options) : 0;
		options->accuracy > 0 ? ft_accuracy(options) : 0;
		ft_put_bit_to_buff(cast_ap, options);
	}
	if (options->width >= 0 && size > 0)
		while (size--)
			append_to_buff(options->zero && !options->minus &&
				options->accuracy < 0 ? '0' : ' ', 0, options);
	if (!options->minus)
	{
		options->space ? append_to_buff(' ', 0, options) : 0;
		options->accuracy > 0 ? ft_accuracy(options) : 0;
		ft_put_bit_to_buff(cast_ap, options);
	}
}
