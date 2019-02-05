/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_ff.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nivergne <nivergne@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/01/26 21:19:05 by nivergne          #+#    #+#             */
/*   Updated: 2019/02/05 01:23:36 by nivergne         ###   ########.fr       */
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
	ft_bzero(options->f.big_expo, 10000);
	ft_bzero(options->f.big_mant, 10000);

}

void	ft_extract_sign(unsigned char *char_ap, t_info *options)
{
	if (char_ap[9] & (1 << 7))
		options->f.sign = -1;
	else
		options->f.sign = 1;
}

void	ft_extract_expo(unsigned char *char_ap, t_info *options)
{
	int mask;
	// int mask2;

	mask = 0b01111111;
	// mask2 = 0b11111111;
	options->f.exponent |= ((char_ap[9] & mask) << 8);
	options->f.exponent |= char_ap[8];
	// options->f.exponent |= ((char_ap[8] & mask2));
}



void		ft_extract_mant(unsigned char *char_ap, t_info *options)
{
	int i;

	i = 7;
	while (i >= 0)
	{
		options->f.mantis |= ((unsigned long long)(char_ap[i]) << ((unsigned long long)i * 8ULL));
		i--;
	}
}

/*

15-23-31-39-47-55-63-71-79 (+8)
00000000 00000000 10000000 00111111 - 00000000 00000000 10000000 00111111 -- 00000000 |0|0000000

void	ft_extract_expo(unsigned char *char_ap, t_info *options)
{
	int mask1;
	int mask2;

	mask1 = 0b01111111;
	mask2 = 0b11111111;
	options->f.exponent |= ((char_ap[9] & mask1) << 8);
	options->f.exponent |= ((char_ap[8] & mask2));
}

void		ft_extract_mant(unsigned char *char_ap, t_info *options)
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
}

*/