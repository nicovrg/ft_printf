/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nivergne <nivergne@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/12/23 16:44:36 by nivergne          #+#    #+#             */
/*   Updated: 2018/12/28 02:53:33 by nivergne         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/ft_printf.h"

#include <stdio.h>

int		main(int ac, char **av)
{
	int		test_int;
	char	test_char;
	char	*test_string;

	test_int = 42;
	test_char = 'c';
	test_string = "here for the long run";


	printf("Testons donc cette fonction, %d\n%c\n%s\n", test_int, test_char, test_string);
	printf("que % se passe t il quand j'écris des %\n");	
	//ft_printf("Testons donc cette fonction, %d\n%c\n%s\n", test_int, test_char, test_string);
	return (0);
}

/*
Consignes:
Makefile libftprintf.a
Affichage: int, char, string, address, float
Conversions: csp, diouxX (flags: h, hh, 1, 11), f (flags: l, L)
Autres: Gestion de - '%%' '#' '0' '+' '-' ' ' - ainsi que la taille de champ et la précision.

Bonus: couleur, binaire, char non imprimables, conversions étendues, multi fd ...

Question:
Si printf segfault, doit on segfault aussi?
*/