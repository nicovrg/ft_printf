/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_ff.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nivergne <nivergne@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/01/26 21:19:05 by nivergne          #+#    #+#             */
/*   Updated: 2019/01/30 01:11:15 by nivergne         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

//#include "ft_printf.h"
#include "../include/ft_printf.h"

int		ft_initfloat(t_info *options)
{
	int i;

	i = 1;
	options->f.i = 1;
	ft_bzero(options->f.exponent, 15);
	ft_bzero(options->f.mantis, 64);
	ft_bzero(options->f.power_two, 15);
	options->f.power_two[0] = 1;
	while (i < 14)
	{
		options->f.power_two[i] = options->f.power_two[i - 1] * 2;
		i++;
	}
	options->f.power_two[i] = options->f.power_two[i - 1] * 2;
	return (0);
}

int		ft_signfloat(unsigned long long cast_ap, t_info *options)
{
	if (cast_ap & 1UL << 7)
		options->f.sign = -1;
	else
		options->f.sign = 1;
	return (0);
}

int		ft_expofloat(unsigned long long cast_ap, t_info *options)
{
	int i;
	int j;

	i = 0;
	j = 0;
	while (i < 7)
	{
		if (cast_ap & (1UL << (6 - i)))
			options->f.exponent[i] = '1';
		else
			options->f.exponent[i] = '0';
		i++;
	}
	while (i < 15)
	{
		if (cast_ap & (1UL << (15 - j)))
			options->f.exponent[i] = '1';
		else
			options->f.exponent[i] = '0';
		i++;
		j++;
	}
	return (0);
}

int		ft_mantfloat(unsigned long long cast_ap, t_info *options)
{
	int i;
	int add;

	add = 0;
	while (add < 64)
	{
		i = 0;
		while (i < 8)
		{
			if (cast_ap & (1UL << (15 + add - i)))
				options->f.mantis[i + add] = '1';
			else
				options->f.mantis[i + add] = '0';
			i++;
		}
		add += 8;
	}
	return (0);
}

int		ft_printfbin(unsigned long long __unused cast_ap, t_info *options)
{
	int i;

	i = 0;
	printf("\n");
	printf("power_two = \t");
	while (i < 14)
	{
		printf("%d", options->f.power_two[i]);
		printf(" ");
		i++;
	}
	printf("%d", options->f.power_two[i]);
	printf("\n");
	printf("sign = \t\t%d", options->f.sign);
	printf("\n");
	i = 0;
	printf("exponent = \t");
	while (i < 15)
	{
		printf("%c", options->f.exponent[i]);
		i++;
	}
	printf("\n");
	printf("mantis = \t");
	i = 0;
	while (i < 64)
	{
		printf("%c", options->f.mantis[i]);
		i++;
	}
	printf("\n");
	return (0);
}

// 15-23-31-39-47-55-63-71-79 (+8)
// 00000000 00000000 10000000 00111111 - 00000000 00000000 10000000 00111111 -- 00000000 |0|0000000
//options->f.power_two = {1, 2, 4, 8, 16, 32, 64, 128, 256, 512, 1024, 2048, 4096, 8192, 16384};