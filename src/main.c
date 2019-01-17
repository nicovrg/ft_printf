/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nivergne <nivergne@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/12/23 16:44:36 by nivergne          #+#    #+#             */
/*   Updated: 2019/01/17 04:40:22 by nivergne         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

//#include "ft_printf.h"
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

	t_int = 50;
	t_int2 = 42;
	t_char = 'z';
	t_string = "string";
	t_uns = 42;
	t_oct = 420;
	t_hexmin = 42;
	t_hexmax = 42;

	//TEST: BEHAVIOUR
	ft_printf("mine :% d\n", 42);
	printf("true :% d\n", 42);
	//printf("true :% 05d\n", t_int);



	//TEST: CHAR
	//gestion du '-' et width
	//-------------------------------------------
	//ft_printf("%42c\n", t_char);
	//printf("%42c\n", t_char);
	//-------------------------------------------
	//ft_printf("%-42c\n", t_char);
	//printf("%-42c\n", t_char);
	//-------------------------------------------
	
	
	
	//TEST: STRING
	//gestion du '-' et width
	//-------------------------------------------	
	//ft_printf("%42s\n", t_string);
	//printf("%42s\n", t_string);
	//-------------------------------------------
	//ft_printf("%-42s\n", t_string);
	//printf("%-42s\n", t_string);
	//-------------------------------------------



	//TEST: POINTER
	//gestion du '-' et width
	//-------------------------------------------	
	//ft_printf("%42p\n", t_string);
	//printf("%42p\n", t_string);
	//-------------------------------------------
	//ft_printf("%-42p\n", t_string);
	//printf("%-42p\n", t_string);
	//-------------------------------------------



	//TEST: INTEGER
	//gestion de '0', ' ', '+', '-' 
	//-------------------------------------------
	//ft_printf("%-42d\n", t_int);
	//printf("%-42d\n", t_int);
	//-------------------------------------------
	//ft_printf("%+10.55d\n", t_int);
	//printf("%+10.55d\n", t_int);
	//-------------------------------------------
	//ft_printf("%+d\n", t_int);
	//printf("%+d\n", t_int);
	//-------------------------------------------
	//-------------------------------------------
	//-------------------------------------------
	//ft_printf("% +-042d\n", t_int);
	//printf("% +-042d\n", t_int);
	//-------------------------------------------
	
	//ft_printf("%-42d\n", t_int);
	//printf("%-42d\n", t_int);

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
Bonus: gestion de buffer, couleur, multi fd (write(fd, ..., ...)), %* (padding sur le 1er arg), binaire etc ...
Gestion: printf(NULL);
gcc -Wall -Werror -Wextra print_base.c print_csp.c print_ui.c ft_printf.c itoa_base.c main.c mem.c parse.c else.c test.c width_csp.c width_ui.c -o test && ./test | cat -e
*/

