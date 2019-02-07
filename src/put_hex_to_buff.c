/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   put_hex_to_buff.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nivergne <nivergne@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/01/27 14:47:08 by julesqvgn         #+#    #+#             */
/*   Updated: 2019/02/07 19:35:27 by nivergne         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

//#include "ft_printf.h"
#include "../include/ft_printf.h"

long long		abs_value(long long value)
{
	return (value < 0 ? -value : value);
}

long long		get_size(long long value, int base)
{
	int		size;

	size = 0;
	if (value == 0)
		return (1);
	while (value)
	{
		value = value / (long long)base;
		size++;
	}
	return (size);
}

char			*fill_base(int base, int l)
{
	int		i;
	char	*base_arr;

	i = 0;
	if (!(base_arr = (char *)malloc(sizeof(char) * (base + 1))))
		return (NULL);
	while (i <= 9 && i < base)
	{
		base_arr[i] = i + '0';
		i++;
		while (i > 9 && i < base)
		{
			base_arr[i] = i - 10 + (l == 0 ? 'A' : 'a');
			i++;
		}
	}
	base_arr[i] = '\0';
	return (base_arr);
}

void			ft_itoa_base(long long value, int base, int l, t_info *opts)
{
	int					i;
	unsigned long long	uns;
	char				*base_arr;

	uns = abs_value(value);
	i = get_size(uns, base);
	if (!(base_arr = fill_base(base, l)))
		return (NULL);
	i--;
	while (i >= 0)
	{
		opts->buff[opts->index++] = base_arr[uns % (unsigned long long)base];
		if (opts->index == BUFF_SIZE)
			append_to_buff(0, 1, opts);
		uns = uns / (unsigned long long)base;
		i--;
	}
	free(base_arr);
}
