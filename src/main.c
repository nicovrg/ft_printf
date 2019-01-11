/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nivergne <nivergne@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/12/23 16:44:36 by nivergne          #+#    #+#             */
/*   Updated: 2019/01/11 22:39:23 by nivergne         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/ft_printf.h"

#include <stdio.h>

int		main(int __unused ac, char __unused **av)
{
	int				t_int;
	int				t_int2;
	char			t_char;
	unsigned int	t_uns;
	char			*t_string;
	int				t_oct;
	long long		t_hexmin;
	long long		t_hexmax;

	t_int = 42;
	t_int2 = 43;
	t_char = 'c';
	t_string = "here for the long run";
	t_uns = 44;
	t_oct = 45;
	t_hexmin = 45;
	t_hexmax = 45;
	
	ft_printf("hello\nchar\t\t\t:\t\t%c\nstring\t\t\t:\t\t%s\naddress\t\t\t:\t\t%p\ninteger\t\t\t:\t\t%d\ninteger\t\t\t:\t\t%i\noctal\t\t\t:\t\t%o\nunsigned integer\t:\t\t%u\nhexamin\t\t\t:\t\t%x\nhexamaj\t\t\t:\t\t%X\n\n", t_char, t_string, t_string, t_int, t_int2, t_oct, t_uns, t_hexmin, t_hexmax);
	printf("\n\n\n\nhello\nchar\t\t\t:\t\t%c\nstring\t\t\t:\t\t%s\naddress\t\t\t:\t\t%p\ninteger\t\t\t:\t\t%d\ninteger\t\t\t:\t\t%i\noctal\t\t\t:\t\t%o\nunsigned integer\t:\t\t%u\nhexamin\t\t\t:\t\t%x\nhexamaj\t\t\t:\t\t%X\n\n", t_char, t_string, t_string, t_int, t_int2, t_oct, t_uns, t_hexmin, t_hexmax);
	//ft_printf("bonjour\n%+-#- 0+12.1234hhs\n%00d\n", t_string, t_int);
	//FIRST TEST
	//ft_printf("Testons donc cette fonction, %d\n%c\n%s\n", t_int, t_char, t_string);
	return (0);
}

/*
Consignes:
Makefile libftprintf.a
Conversions: csp, diouxX (flags: h, hh, l, ll), f (flags: l, L)
Autres: Gestion de - '%%' '#' '0' '+' '-' ' ' - ainsi que la taille de champ et la précision.

Bonus: gestion de buffer, couleur, multi fd (write(fd, ..., ...)), %* (padding sur le 1er arg), binaire etc ...

Question:
Si printf segfault, doit on segfault aussi? oOui
*/

/*
printf(NULL);
printf("Testons donc cette fonction, %d\n%c\n%s\n", test_int, test_char, test_string);
printf("que % se passe t il quand j'écris des %\n");
*/

