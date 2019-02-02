/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   big_int.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nivergne <nivergne@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/02/02 03:02:36 by nivergne          #+#    #+#             */
/*   Updated: 2019/02/02 09:41:33 by nivergne         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

//#include "ft_printf.h"
#include "../include/ft_printf.h" 

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