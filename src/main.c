/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nivergne <nivergne@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/12/23 16:44:36 by nivergne          #+#    #+#             */
/*   Updated: 2019/01/08 19:44:24 by nivergne         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/ft_printf.h"

#include <stdio.h>

int		main(int __unused ac, char __unused **av)
{
	int		test_int;
	char	test_char;
	char	*test_string;

	test_int = 42;
	test_char = 'c';
	test_string = "here for the long run";

	//ft_printf("%s");
	ft_printf("%+s");
	//ft_printf("%-s");
	//ft_printf("%#s");
	//ft_printf("% s");
	//ft_printf("%0s");


	//ft_printf("Testons donc cette fonction, %d\n%c\n%s\n", test_int, test_char, test_string);
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
