/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   broken.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nivergne <nivergne@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/01/26 21:19:05 by nivergne          #+#    #+#             */
/*   Updated: 2019/01/31 02:03:05 by nivergne         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/*

//#include "ft_printf.h"
#include "../include/ft_printf.h"

typedef struct	s_float
{
	int		i;
	int		sign;
	int		power_two[15];
	char	exponent[15];
	char	mantis[64];

}				t_float;

//print_f.c
void			ft_addfloat(va_list ap, t_info *options);

//print_ff.c
int				ft_initfloat(t_info *options);
int				ft_signfloat(long double cast_ap, t_info *options);
int				ft_expofloat(long double cast_ap, t_info *options);
int				ft_mantfloat(long double cast_ap, t_info *options);
int				ft_printfbin(long double __unused cast_ap, t_info *options);


void	ft_addfloat(va_list ap, t_info *options)
{
	long double		cast_ap;

	cast_ap = va_arg(ap, long double);
	ft_initfloat(options);
	ft_signfloat(cast_ap, options);
	ft_expofloat(cast_ap, options);
	ft_mantfloat(cast_ap, options);
	ft_printfbin(cast_ap, options);

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

int		ft_signfloat(long double cast_ap, t_info *options)
{
	if (cast_ap & 1 << 7)
		options->f.sign = -1;
	else
		options->f.sign = 1;
	return (0);
}

int		ft_expofloat(long double cast_ap, t_info *options)
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

int		ft_mantfloat(long double cast_ap, t_info *options)
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

int		ft_printfbin(long double __unused cast_ap, t_info *options)
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

15-23-31-39-47-55-63-71-79 (+8)
00000000 00000000 10000000 00111111 - 00000000 00000000 10000000 00111111 -- 00000000 |0|0000000
options->f.power_two = {1, 2, 4, 8, 16, 32, 64, 128, 256, 512, 1024, 2048, 4096, 8192, 16384};
00000000 00000000 10000000 00111111 - 00000000 00000000 10000000 00111111 -- 00000000 |0|0000000 


	convertir expo en base 10 et puissance de 2 et enlever ce qu il faut si besoin 
	
	
	
	
	ft_addnbr(((exponent)) * sign, options);
	append_to_buff('.', 0, options);
	ft_addmantis(cast_ap);
}

void	ft_addmantis(double cast_ap)
{
	int					i;
	unsigned long		mantis;

	i = 0;
	mantis = 0;
	while (i < 31)
	{
		if ((uint32_t)cast_ap & 1 << (23 - i))
			mantis = mantis + mantis * 10 ^ -i;
		i++;
	}
	printf("mantis = %lu\n", mantis);
}

15-23-31-39-47-55-63-71-79 (+8)

0
00011000
11101110110011000011101
 01000010 00101001 10110010 01101100

MANTIS  = |0|0|0|0|0|0|0|0||0|0|0|0|0|0|0|0||0|0|0|0|0|0|0| 
			10-1
https:/ /www.youtube.com/watch?v=4DfXdJdaNYs

// level 1 : if ((uint32_t)cast_ap & (uint32_t)SIGN_BIT_MASK) // propreté modularite
// level 2 : faire une fonction qui check chaque truc et qui fait un seul taf
// level 3 : faire une fonction qui appelle les sous fonctions

EXPONENT = 255: as neg or pos - 127 must be applied to the exponent
|128|64| |32|16| |8|4| |2|1|
|0|0|    |1|0|   |0|1| |0|0|

SIGN = |1| -> NEGATIF

RADICANT = |0|0| |0|0| |0|0| |0|0|

MANTISSA = |0|0| |0|0| |0|0| |0|0| |0|0| |0|0| |0|0| |0|0| |0|0| |0|0| |0|0| |0|0| |0|0| |0|0| |0|0| |0|0| |0|0| |0|0| |0|0| |0|0| |0|0| |0|0| |0|0|  
*/