/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_ff.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nivergne <nivergne@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/01/26 21:19:05 by nivergne          #+#    #+#             */
/*   Updated: 2019/02/02 06:42:36 by nivergne         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

//#include "ft_printf.h"
#include "../include/ft_printf.h"

void	ft_initfloat(t_info *options)
{
	int i;

	i = 1;
	options->f.sign = 0;
	options->f.exponent = 0;
	options->f.mantis = 0;
}

void	ft_extract_sign(unsigned char *char_ap, t_info *options)
{
	if (char_ap[9] & (1 << 7))
		options->f.sign = -1;
	else
		options->f.sign = 1;
}

void	ft_extract_exponent(unsigned char *char_ap, t_info *options)
{
	int mask;

	mask = 0b01111111;
	options->f.exponent |= ((char_ap[9] & mask) << 8);
	options->f.exponent |= char_ap[8];
}

void	ft_put_binary2(unsigned long long byte)
{
	if (byte >= 2)
		ft_put_binary2(byte / 2);
	ft_putchar('0' + byte % 2);
}

void		ft_extract_mantis(unsigned char *char_ap, t_info *options)
{
	int i;

	i = 7;
	ft_put_binary2(options->f.mantis);
	while (i >= 0)
	{
		options->f.mantis |= ((unsigned long long)(char_ap[i]) << ((unsigned long long)i * 8ULL));
		printf("octet = %hhd\n", char_ap[i]);
		i--;
	}
	ft_putstr("coucou");
	ft_put_binary2(options->f.mantis);
}
	// int i;
	// int oct;
	// int index;

	// oct = 7;
	// index = 0;
	// while (oct >= 0)
	// {
	// 	i = 0;
	// 	while (i < 8)
	// 	{
	// 		if (char_ap[oct] & (1 << (7 - i)))
	// 			options->f.mantis[i + index] = '1';
	// 		else
	// 			options->f.mantis[i + index] = '0';
	// 		i++;
	// 	}
	// 	index = index + 8;
	// 	oct--;
	// }

int		ft_show_extracted(unsigned char __unused *char_ap, t_info *options)
{
	// ft_putstr("sign = ");
	// ft_putchar('\t');
	// ft_putchar('\t');
	printf("sign = %d\n", options->f.sign);
	// ft_putchar('\n');
	// ft_putstr("exponent = ");
	// ft_putchar('\t');
	printf("exponent = %llu\n", options->f.exponent);
	// ft_putstr("mantis = ");
	// ft_putchar('\t');
	printf("mantis = %llu\n", options->f.mantis);
	
	// ft_putchar('\n');
	// ft_putstr("mantis = ");
	// ft_putchar('\t');
	// i = 0;
	// while (i < 64)
	// {
	// 	ft_putchar(options->f.mantis[i]);
	// 	i++;
	// }
	// ft_putchar('\n');
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
