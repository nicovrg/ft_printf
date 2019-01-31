/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   itoa_base.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jquivogn <jquivogn@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/01/07 20:00:21 by nivergne          #+#    #+#             */
/*   Updated: 2019/01/31 19:24:37 by jquivogn         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

//#include "ft_printf.h"
#include "../include/ft_printf.h"

unsigned long long	get_size(unsigned long long value, int base)
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

char			*ft_itoa_base(unsigned long long value, int base, int l)
{
	int					i;
	unsigned long long	uns;
	char				*base_arr;
	char				*base_res;

	uns = value;
	i = get_size(uns, base);
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
	free(base_arr);
	return (base_res);
}