/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   big_int.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nivergne <nivergne@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/02/02 03:02:36 by nivergne          #+#    #+#             */
/*   Updated: 2019/02/02 05:25:10 by nivergne         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

//#include "ft_printf.h"
#include "../include/ft_printf.h" 

int multiply(int x, char *res, int res_size)
{
    int i;
    int prod;
    int carry;
    
    i = 0;
    prod = 0;
    carry = 0; 
    while (i < res_size) 
    { 
        prod = res[i] * x + carry; 
        i++;
    }
    res[i] = prod % 10; 
    carry = prod / 10; 
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
//     int                 i;
//     unsigned char       *exponent;
//     unsigned char       *result;
    
//     i = 0;
//     exponent = options->f.exponent;
//     while (exponent[i])
//     {

//     }
//     return (result);
// }