/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   big_int.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nivergne <nivergne@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/02/02 03:02:36 by nivergne          #+#    #+#             */
/*   Updated: 2019/02/02 20:27:24 by nivergne         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

//#include "ft_printf.h"
#include "../include/ft_printf.h" 

/*

L'idée serait de faire une fonction qui récupère l'exponent en binaire et parcours chaqun de ses bits:
à chaque fois qu'il y a un 1, on ajoute au resultat (qui vaut initialement 0) la puissance de 2 
associé à l'index du bit, sachant qu'il faut faire des opérations sur des chaines de caractères.


char *big_int <- FCT: powertwo_to_string <- int bit (1of63 bits)
char *big_int <- FCT: powertwo_add_string <- char *big_int1, char *big_int2

*/

char	*exponent_bigint(t_info *options)
{
	int					i;
	char				result[10000];
	unsigned long long	exponent;

	i = 0;
	ft_bzero(result, 10000);
	exponent = options->f.exponent;
	while (i < 15)
	{
		if (exponent & (1ULL << i))
			// call function
		i++;
	}
}

//PENSER AU BIT EXPLICITE

// uint32_t carry=0;
// for(i=0; i<len; i++) {
//     uint64_t tmp = n*(uint64_t)big[i] + carry;
//     big[i] = tmp;
//     carry = tmp >> 32;
// }
// if (carry) big[len++] = carry;

/*
long long power_two(long long nb, long long power)
{
    long long result;
    
    result = 1;
    while (power > 0) 
    {
        if (power % 2 == 0)
        {
            power = power / 2; 
            nb = nb * nb;
        }
        else
        {

            power = power - 1;
            result = result * nb;
            power = power / 2;
            nb = nb * nb;
        }
    }
    return (result);
}

int multiply(int x, char *res, int res_size)
{
    int i;
    int mult;
    int carry;
    
    i = 0;
    mult = 0;
    carry = 0;
    while (i < res_size) 
    { 
        mult = res[i] * x + carry; 
        i++;
    }
    res[i] = mult % 10; 
    carry = mult / 10; 
    while (carry)
    {
        res[res_size] = carry % 10; 
        carry = carry / 10; 
        res_size++; 
    }
    return (res_size); 
}
 
void power(int x, int n)
{
    int i;
    int tmp;
    int res_size;
    char res[10000];
    
    i = 2;
    tmp = x; 
    res_size = 0; 
    if(n == 0)
    {
        res[0] = '1';
        res_size = 1;
        return ;
    }
    while (tmp != 0)
    {
        res[res_size] = tmp % 10 + '0'; 
        tmp = tmp / 10;
        res_size++;
    }
    while (i <= n)
    {
        res_size = multiply(x, res, res_size); 
        i++;
    }
    i = res_size - 1;
    while (i >= 0) 
    {
        ft_putchar(res[i]); 
        i--;
    }
}

// char    *big_int(t_info *options)
// {
//     int                     i;
//     unsigned long long      exponent;
//     unsigned long long      result;
    
//     exponent = options->f.exponent;
//     return (result);
// }

*/