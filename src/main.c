/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nivergne <nivergne@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/12/23 16:44:36 by nivergne          #+#    #+#             */
/*   Updated: 2019/01/16 01:05:37 by nivergne         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/ft_printf.h"

#include <stdio.h>

int		main(int __unused ac, char __unused **av)
{
	int				t_int;
	int				t_int2;
	char			t_char;
	char			*t_string;
	long long		t_uns;
	long long		t_oct;
	long long		t_hexmin;
	long long		t_hexmax;

	t_int = 42;
	t_int2 = 42;
	t_char = 'z';
	t_string = "here for the long run";
	t_uns = 42;
	t_oct = 42;
	t_hexmin = 42;
	t_hexmax = 42;
	
	//TEST: flag behaviour
	
	//TEST: flag char
	//gestion du '-' et width
	//ft_printf("printf1%-42c\n", t_char);
	//printf("printf2%-42c\n", t_char);

	//TEST: flag string
	//gestion du '-' et width
	ft_printf("%25s\n", t_string);
	printf("%25s\n", t_string);
	
	//TEST: cspdiouxX
	//ft_printf("hello\nchar\t\t\t:\t\t%c\nstring\t\t\t:\t\t%s\naddress\t\t\t:\t\t%p\ninteger\t\t\t:\t\t%d\ninteger\t\t\t:\t\t%i\noctal\t\t\t:\t\t%o\nunsigned integer\t:\t\t%u\nhexamin\t\t\t:\t\t%x\nhexamaj\t\t\t:\t\t%X\n\n", t_char, t_string, t_string, t_int, t_int2, t_oct, t_uns, t_hexmin, t_hexmax);
	//printf("\n\n\n\nhello\nchar\t\t\t:\t\t%c\nstring\t\t\t:\t\t%s\naddress\t\t\t:\t\t%p\ninteger\t\t\t:\t\t%d\ninteger\t\t\t:\t\t%i\noctal\t\t\t:\t\t%llo\nunsigned integer\t:\t\t%llu\nhexamin\t\t\t:\t\t%llx\nhexamaj\t\t\t:\t\t%llX\n\n", t_char, t_string, t_string, t_int, t_int2, t_oct, t_uns, t_hexmin, t_hexmax);
	// ft_printf("%o%u\n", t_oct, t_uns);
	// printf("%o%u\n", t_oct, t_uns);
	//ft_printf("%%",'c');
	//printf("%%",'c');

	//TEST: 0+- #%%
	//ft_printf("bonjour\n%+-#- 0+12.1234hhhhs\n%00d%%\n", t_string, t_int);
	//printf("bonjour\n%+-#- 0+12.1234hhs\n%00d%%\n", t_string, t_int);
	//printf("flagexplorer%c\n", t_char);
	//printf("bonjour\n%+-#- 0+12.1234hhs\n%00d%%\n", t_string, t_int);
	
	//TEST-MEDHI
	// printf("%5%-\n");
	// printf("%5q-\n");
	// printf("%-5q-\n");
	// printf("%5c-\n", 'y');
	// printf("%-5c-\n", 'y');
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

