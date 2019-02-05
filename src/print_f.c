/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_f.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nivergne <nivergne@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/01/26 21:19:05 by nivergne          #+#    #+#             */
/*   Updated: 2019/02/05 16:57:14 by nivergne         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

//#include "ft_printf.h"
#include "../include/ft_printf.h"
#include <limits.h>

void	ft_add_fsign(t_info *options)
{
	if (options->f.sign == -1)
		append_to_buff('-', 0, options);
}

void	ft_add_fexpo(t_info *options)
{
	int exponent;
	//mettre exponent -> buff
	exponent = (int)options->f.exponent;
	exponent -= 16383;
}

void	ft_add_fmant(t_info *options)
{
	int mantis;
	//mettre mantis -> buff 
	mantis = (int)options->f.mantis;
	mantis -= 0/*big*/;
}


void	ft_addfloat(va_list ap, t_info *options)
{
	long double			cast_ap;
	unsigned char		*char_ap;
	
	cast_ap = (long double)va_arg(ap, double);
	// cast_ap = __LDBL_MAX__;
	char_ap = (unsigned char *)&cast_ap;

	ft_initfloat(options);
	//read & store bin from float
	ft_extract_sign(char_ap, options);
	ft_extract_expo(char_ap, options);
	ft_extract_mant(char_ap, options);
	//show bin for debug
	show_float_test(char_ap, options);
	//compute bigint value of expo & mant
	exponent_bigint(options);

	//add float to buff
	ft_add_fsign(options);
	ft_add_fexpo(options);
	ft_add_fmant(options);

}


/*

00000000 00000000 00000000 00000000 00000000 00000000 00000000 11000000 11111111 00111111

	00000000 00000000 10000000 00111111 - 00000000 00000000 10000000 00111111 -- 		00000000 |0|0000000 
	ft_addnbr(((exponent)) * sign, options);
	append_to_buff('.', 0, options);
	ft_addmantis(cast_ap);

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