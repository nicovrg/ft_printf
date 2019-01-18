/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   itoa_base.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nivergne <nivergne@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/01/07 20:00:21 by nivergne          #+#    #+#             */
/*   Updated: 2019/01/18 20:14:34 by nivergne         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

//#include "ft_printf.h"
#include "../include/ft_printf.h"

long long	abs_value(long long value)
{
	return (value < 0 ? -value : value);
}

long long	get_size(long long value, int base)
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

char			*neg_int(long long value)
{
	char	*res;
	int		i;
	
	i = get_size(value, 10) + 1;
	if (!(res = (char *)malloc(sizeof(char) * i)))
		return (NULL);
	res[i] = '\0';
	res[0] = '-';
	i--;
	while (i > 0)
	{
		res[i] = (value % 10) * -1 + '0';
		value = value / 10;
		i--;
	}
	return (res);
}

char			*ft_itoa_base(long long value, int base, int l)
{
	int					i;
	unsigned long long	uns;
	char				*base_arr;
	char				*base_res;

	uns = abs_value(value);
	i = get_size(uns, base);
	if (value < 0 && base == 10)
	{
		base_res = neg_int(value);
		return (base_res);
	}
	if (!(base_arr = fill_base(base, l)))
		return (NULL);
	if (!(base_res = (char *)malloc(sizeof(char) * (i + 1))))
		return (NULL);
	base_res[i] = '\0';
	i--;
	while (i >= 0)
	{ 
		base_res[i] = base_arr[uns % (unsigned long long)base];
		uns = uns / (unsigned long long)base;
		i--;
	}
	return (base_res);
}