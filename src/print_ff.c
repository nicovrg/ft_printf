/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_ff.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nivergne <nivergne@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/01/26 21:19:05 by nivergne          #+#    #+#             */
/*   Updated: 2019/02/02 05:18:12 by nivergne         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

//#include "ft_printf.h"
#include "../include/ft_printf.h"

int		ft_initfloat(t_info *options)
{
	int i;

	i = 1;
	options->f.i = 1;
	options->f.sign = 0;
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

int		ft_extract_sign(unsigned char *char_ap, t_info *options)
{
	if (char_ap[9] & (1 << 7))
		options->f.sign = -1;
	else
		options->f.sign = 1;
	return (0);
}

int		ft_extract_exponent(unsigned char *char_ap, t_info *options)
{
	int i;
	int j;

	i = 0;
	j = 0;

	while (i < 7)
	{
		if (char_ap[9] & (1 << (6 - i)))
			options->f.exponent[i] = '1';
		else
			options->f.exponent[i] = '0';
		i++;
	}
	while (i < 15)
	{
		if (char_ap[8] & (1 << (7 - j)))
			options->f.exponent[i] = '1';
		else
			options->f.exponent[i] = '0';
		i++;
		j++;
	}
	return (0);
}

int		ft_extract_mantis(unsigned char *char_ap, t_info *options)
{
	int i;
	int oct;
	int index;

	oct = 7;
	index = 0;
	while (oct >= 0)
	{
		i = 0;
		while (i < 8)
		{
			if (char_ap[oct] & (1 << (7 - i)))
				options->f.mantis[i + index] = '1';
			else
				options->f.mantis[i + index] = '0';
			i++;
		}
		index = index + 8;
		oct--;
	}
	return (0);
}

int		ft_show_extracted(unsigned char __unused *char_ap, t_info *options)
{
	int i;

	ft_putstr("sign = ");
	ft_putchar('\t');
	ft_putchar('\t');
	ft_putnbr(options->f.sign);
	ft_putchar('\n');
	ft_putstr("exponent = ");
	ft_putchar('\t');
	i = 0;
	while (i < 15)
	{
		ft_putchar(options->f.exponent[i]);
		i++;
	}
	ft_putchar('\n');
	ft_putstr("mantis = ");
	ft_putchar('\t');
	i = 0;
	while (i < 64)
	{
		ft_putchar(options->f.mantis[i]);
		i++;
	}
	ft_putchar('\n');
	return (0);
}

// 15-23-31-39-47-55-63-71-79 (+8)
// 00000000 00000000 10000000 00111111 - 00000000 00000000 10000000 00111111 -- 00000000 |0|0000000



//options->f.power_two = {1, 2, 4, 8, 16, 32, 64, 128, 256, 512, 1024, 2048, 4096, 8192, 16384};
// printf("\n");
// printf("power_two = \t");
// while (i < 14)
// {
// 	printf("%d", options->f.power_two[i]);
// 	printf(" ");
// 	i++;
// }
// printf("%d", options->f.power_two[i]);
// printf("\n");
// i = 0;
