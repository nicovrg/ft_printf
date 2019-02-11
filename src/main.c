/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jquivogn <jquivogn@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/12/23 16:44:36 by nivergne          #+#    #+#             */
/*   Updated: 2019/02/11 17:43:54 by jquivogn         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */


#include "../include/ft_printf.h"
#include <locale.h>

int		main(int __unused ac, char ** __unused av)
{
	int				t_int;
	int				t_int2;
	char			t_char;
	char			*t_string;
	float			t_float;
	float			t_float2;
	long long		t_uns;
	long long		t_oct;
	long long		t_hexmin;
	long long		t_hexmax;

	t_int = 42;
	t_int2 = 42;
	t_char = 'z';
	t_string = "string";
	t_uns = 42;
	t_oct = 420;
	t_hexmin = 42;
	t_hexmax = 42;
	t_float = 1.5;
	t_float2 = -42.424242424242f;

	void *nb = 42;
	//double nb = 12.5f;
	//double nb = 0.0f;
	//double nb = 12389123798;
	//double nb = 45.123456789f;
	// int i = 0;
	// int t_dolphin = 129297;
	// while (i++ < 45)
	// 	ft_printf("%lc %lc ", t_dolphin, 127817);
	// ft_printf("\n\n");

	// setlocale(LC_ALL, "");
	// printf("\nmine : %d\n", ft_printf("%f", t_float2));
	// printf("\ntrue : %d\n", printf("%f", t_float2));
	// fflush(stdout);
	printf("\n\n===============================================\n\n");

	printf("\nmine : %d\n", ft_printf("%#016.0p", t_hexmin));
	printf("\ntrue : %d\n", printf("%#016.0p", t_hexmin));
	printf("\n\n===============================================\n\n");
	/*printf("\n\n===============================================\n\n");

	printf("\nmine : %d\n", ft_printf("space:% .1f|", nb));
	printf("\ntrue : %d\n", printf("space:% .1f|", nb));
	printf("\n\n===============================================\n\n");

	printf("\nmine : %d\n", ft_printf("plus:%+f|", nb));
    printf("\ntrue : %d\n", printf("plus:%+f|", nb));
	printf("\n\n===============================================\n\n");

	printf("\nmine : %d\n", ft_printf("hash:%#f|", nb));
    printf("\ntrue : %d\n", printf("hash:%#f|", nb));
	printf("\n\n===============================================\n\n");

	printf("\nmine : %d\n", ft_printf("precision:%.2f|", nb));
    printf("\ntrue : %d\n", printf("precision:%.2f|", nb));
	printf("\n\n===============================================\n\n");

	printf("\nmine : %d\n", ft_printf("precision + hash:%#.0f|", nb));
    printf("\ntrue : %d\n", printf("precision + hash:%#.0f|", nb));
	printf("\n\n===============================================\n\n");

	printf("\nmine : %d\n", ft_printf("space + prec:% .5f|", nb));
    printf("\ntrue : %d\n", printf("space + prec:% .5f|", nb));
	printf("\n\n===============================================\n\n");

	printf("\nmine : %d\n", ft_printf("space + prec + hash:%# .0f|", nb));
    printf("\ntrue : %d\n", printf("space + prec + hash:%# .0f|", nb));
	printf("\n\n===============================================\n\n");

	printf("\nmine : %d\n", ft_printf("space + prec + hash:% #.0f|", nb));
    printf("\ntrue : %d\n", printf("space + prec + hash:% #.0f|", nb));
	printf("\n\n===============================================\n\n");

	printf("\nmine : %d\n", ft_printf("Plus + prec / grande:%+.5f|", nb));
    printf("\ntrue : %d\n", printf("Plus + prec / grande:%+.5f|", nb));
	printf("\n\n===============================================\n\n");

	printf("\nmine : %d\n", ft_printf("Plus + prec / petite:%+.0f|", nb));
    printf("\ntrue : %d\n", printf("Plus + prec / petite:%+.0f|", nb));
	printf("\n\n===============================================\n\n");

	printf("\nmine : %d\n", ft_printf("Plus + prec + hash:%#+.0f|", nb));
    printf("\ntrue : %d\n", printf("Plus + prec + hash:%#+.0f|", nb));
	printf("\n\n===============================================\n\n");

	printf("\nmine : %d\n", ft_printf("Prec + 0:%0.5f|", nb));
    printf("\ntrue : %d\n", printf("Prec + 0:%0.5f|", nb));
	printf("\n\n===============================================\n\n");

	printf("\nmine : %d\n", ft_printf("Prec + minus:%-.5f|", nb));
    printf("\ntrue : %d\n", printf("Prec + minus:%-.5f|", nb));
	printf("\n\n===============================================\n\n");

	printf("\nmine : %d\n", ft_printf("size:%5f|", nb));
    printf("\ntrue : %d\n", printf("size:%5f|", nb));
	printf("\n\n===============================================\n\n");

	printf("\nmine : %d\n", ft_printf("size + space:% 5f|", nb));
    printf("\ntrue : %d\n", printf("size + space:% 5f|", nb));
	printf("\n\n===============================================\n\n");

	printf("\nmine : %d\n", ft_printf("size + plus:%+5f|", nb));
    printf("\ntrue : %d\n", printf("size + plus:%+5f|", nb));
	printf("\n\n===============================================\n\n");

	printf("\nmine : %d\n", ft_printf("size + space:%# 5f|", nb));
    printf("\ntrue : %d\n", printf("size + space:%# 5f|", nb));
	printf("\n\n===============================================\n\n");

	printf("\nmine : %d\n", ft_printf("size + plus:%#+5f|", nb));
    printf("\ntrue : %d\n", printf("size + plus:%#+5f|", nb));
	printf("\n\n===============================================\n\n");

	printf("\nmine : %d\n", ft_printf("size + minus:%-5f|", nb));
    printf("\ntrue : %d\n", printf("size + minus:%-5f|", nb));
	printf("\n\n===============================================\n\n");

	printf("\nmine : %d\n", ft_printf("size + 0:%05f|", nb));
    printf("\ntrue : %d\n", printf("size + 0:%05f|", nb));
	printf("\n\n===============================================\n\n");

	printf("\nmine : %d\n", ft_printf("size + 0 + plus:%+05f|", nb));
    printf("\ntrue : %d\n", printf("size + 0 + plus:%+05f|", nb));
	printf("\n\n===============================================\n\n");

	printf("\nmine : %d\n", ft_printf("size + 0 + plus:%0+5f|", nb));
    printf("\ntrue : %d\n", printf("size + 0 + plus:%0+5f|", nb));
	printf("\n\n===============================================\n\n");

	printf("\nmine : %d\n", ft_printf("size + 0 + prec:%05.3f|", nb));
    printf("\ntrue : %d\n", printf("size + 0 + prec:%05.3f|", nb));
	printf("\n\n===============================================\n\n");

	printf("\nmine : %d\n", ft_printf("size + 0 + prec + hash:%0#5.0f|", nb));
    printf("\ntrue : %d\n", printf("size + 0 + prec + hash:%0#5.0f|", nb));
	printf("\n\n===============================================\n\n");

	printf("\nmine : %d\n", ft_printf("size + minus + prec:%-5.3f|", nb));
    printf("\ntrue : %d\n", printf("size + minus + prec:%-5.3f|", nb));
	printf("\n\n===============================================\n\n");

	printf("\nmine : %d\n", ft_printf("size + minus + prec + hash:%-#5.0f|", nb));
    printf("\ntrue : %d\n", printf("size + minus + prec + hash:%-#5.0f|", nb));
	printf("\n\n===============================================\n\n");

	printf("\nmine : %d\n", ft_printf("size + plus + 0 + prec:%+05.3f|", nb));
    printf("\ntrue : %d\n", printf("size + plus + 0 + prec:%+05.3f|", nb));
	printf("\n\n===============================================\n\n");

	printf("\nmine : %d\n", ft_printf("size + plus + 0 + prec + hash:%0+#5.0f|", nb));
    printf("\ntrue : %d\n", printf("size + plus + 0 + prec + hash:%0+#5.0f|", nb));
	printf("\n\n===============================================\n\n");

	printf("\nmine : %d\n", ft_printf("size + espace + zero + prec:%0 5.3f|", nb));
    printf("\ntrue : %d\n", printf("size + espace + zero + prec:%0 5.3f|", nb));
	printf("\n\n===============================================\n\n");

	printf("\nmine : %d\n", ft_printf("size + espace + zero + prec:% 05.3f|", nb));
    printf("\ntrue : %d\n", printf("size + espace + zero + prec:% 05.3f|", nb));
	printf("\n\n===============================================\n\n");

	printf("\nmine : %d\n", ft_printf("size + espace + zero + prec + hash:%#0 5.0f|", nb));
    printf("\ntrue : %d\n", printf("size + espace + zero + prec + hash:%#0 5.0f|", nb));
	printf("\n\n===============================================\n\n");

	printf("\nmine : %d\n", ft_printf("size + minus + plus + prec:%-+5.3f|", nb));
    printf("\ntrue : %d\n", printf("size + minus + plus + prec:%-+5.3f|", nb));
	printf("\n\n===============================================\n\n");

	printf("\nmine : %d\n", ft_printf("size + minus + plus + prec + hash:%-#+5.1f|", nb));
    printf("\ntrue : %d\n", printf("size + minus + plus + prec + hash:%-#+5.1f|", nb));
	printf("\n\n===============================================\n\n");*/
	// ft_printf("\n\n");
	// i = 0;
	// while (i++ < 45)
	// 	ft_printf("%lc %lc ", t_dolphin, 127817);
	// ft_printf("\n");

	// printf("%lc\n", 128150);
	// fflush(stdout);
	// ft_printf("-->%lc\n", 128150);
	// printf("\n\n===============================================\n\n");
	// ft_printf("%X %12o %5s %x %d qdaze %c\n", -123, -432, "okqsd", 5643, 123654, 'S');
	// printf("%X %12o %5s %x %d qdaze %c\n", -123, -432, "okqsd", 5643, 123654, 'S');
	// printf("\n\n===============================================\n\n");
	// ft_printf("%X %o %s %x %d qdaze %c \n %c\n", 1233, 123432, "okdsq qsqsd", 6542, -123654, 'U', 'W');
	// printf("%X %o %s %x %d qdaze %c \n %c\n", 1233, 123432, "okdsq qsqsd", 6542, -123654, 'U', 'W');
	// printf("\n\n===============================================\n\n");
	// ft_printf("%X %o %s %x %d qdaze %c \n %c\n", 1233, 123432, "okdsq qsqsd", 6542, -123654, 'U', 'W');
	// printf("%X %o %s %x %d qdaze %c \n %c", 1233, 123432, "okdsq qsqsd", 6542, -123654, 'U', 'W');
	// printf("\n\n===============================================\n\n");
	// ft_printf("%X %o %s %5x %d qdaze %5c \n %c %X %o %s %x %d qdaze %c \n %c\n", 1233, 123432, "okdsq qsqsd", 6542, -123654, 'U', 'W', 1233, 123432, "okdsq qsqsd", 6542, -123654, 'U', 'W');
	// printf("%X %o %s %5x %d qdaze %5c \n %c %X %o %s %x %d qdaze %c \n %c\n", 1233, 123432, "okdsq qsqsd", 6542, -123654, 'U', 'W', 1233, 123432, "okdsq qsqsd", 6542, -123654, 'U', 'W');
	// printf("\n\n===============================================\n\n");
	// TEST: CHAR
	// gestion du '-' et width
	// printf("----------------\n");
	// -------------------------------------------
	// ft_printf("%42c\n", t_char);
	// printf("%42c\n", t_char);
	// fflush(stdout);
	// -------------------------------------------
	// ft_printf("%-42c\n", t_char);
	// printf("%-42c\n", t_char);
	// fflush(stdout);
	// -------------------------------------------



	// TEST: STRING
	// gestion du '-' et width
	// -------------------------------------------
	// ft_printf("%42s\n", t_string);
	// printf("%42s\n", t_string);
	// fflush(stdout);
	// -------------------------------------------
	// ft_printf("%-42s\n", t_string);
	// printf("%-42s\n", t_string);
	// fflush(stdout);
	// -------------------------------------------



	// TEST: POINTER
	// gestion du '-' et width
	// -------------------------------------------
	// ft_printf("%42p\n", t_string);
	// printf("%42p\n", t_string);
	// fflush(stdout);
	// -------------------------------------------
	// ft_printf("%-42p\n", t_string);
	// printf("%-42p\n", t_string);
	// fflush(stdout);
	// -------------------------------------------



	// TEST: INTEGER
	// gestion de '0', ' ', '+', '-'
	// -------------------------------------------
	// ft_printf("%-42d\n", t_int);
	// printf("%-42d\n", t_int);
	// fflush(stdout);
	// -------------------------------------------
	// ft_printf("%+10.55d\n", t_int);
	// printf("%+10.55d\n", t_int);
	// fflush(stdout);
	// -------------------------------------------
	// ft_printf("%+d\n", t_int);
	// printf("%+d\n", t_int);
	// fflush(stdout);
	// -------------------------------------------
	// ft_printf("%+-42d\n", t_int);
	// printf("%+-42d\n", t_int);
	// fflush(stdout);
	// -------------------------------------------
	// ft_printf("%-42d\n", t_int);
	// printf("%-42d\n", t_int);
	// fflush(stdout);
	// -------------------------------------------


	// TEST: UNSIGNED INTEGER
	// gestion de
	// -------------------------------------------
	// ft_printf("%-42u\n", t_int);
	// printf("%-42u\n", t_int);
	// fflush(stdout);
	// -------------------------------------------
	// ft_printf("%+10.55d\n", t_int);
	// printf("%+10.55d\n", t_int);
	// fflush(stdout);
	// -------------------------------------------
	// ft_printf("%0u\n", t_int);
	// printf("%0u\n", t_int);
	// fflush(stdout);
	// -------------------------------------------
	// ft_printf("%+-42d\n", t_int);
	// printf("%+-42d\n", t_int);
	// fflush(stdout);
	// -------------------------------------------
	// ft_printf("%-42d\n", t_int);
	// printf("%-42d\n", t_int);
	// fflush(stdout);
	// -------------------------------------------



	// TEST: OCTAL
	// gestion de
	// -------------------------------------------
	// ft_printf("%-42o\n", t_int);
	// printf("%-42o\n", t_int);
	// fflush(stdout);
	// -------------------------------------------
	// ft_printf("%010.55o\n", t_int);
	// printf("%010.55o\n", t_int);
	// fflush(stdout);
	// -------------------------------------------
	// ft_printf("%#o\n", t_int);
	// printf("%#o\n", t_int);
	// fflush(stdout);
	// -------------------------------------------
	// ft_printf("%42o\n", t_int);
	// printf("%42o\n", t_int);
	// fflush(stdout);
	// -------------------------------------------
	// ft_printf("% .42o\n", t_int);
	// printf("% .42o\n", t_int);
	// fflush(stdout);
	// -------------------------------------------
	// ft_printf("%ll42o\n", t_int);
	// printf("%ll42o\n", t_int);
	// fflush(stdout);



	// TEST: Hexa
	// gestion de
	//ft_printf("%010x\n", 542);
	//printf("%010x\n", 542);
	//fflush(stdout);
	// -------------------------------------------
	// ft_printf("%x\n", t_int);
	// printf("%x\n", t_int);
	// fflush(stdout);
	// //-------------------------------------------
	// ft_printf("%X\n", t_int);
	// printf("%X\n", t_int);
	// fflush(stdout);
	// //-------------------------------------------
	// ft_printf("%42x\n", t_int);
	// printf("%42x\n", t_int);
	// fflush(stdout);
	// -------------------------------------------
	// ft_printf("%c\n", 42);
	// printf("%c\n", 42);
	// -------------------------------------------
	// ft_printf("%#x\n", t_int);
	// printf("%#x\n", t_int);
	// fflush(stdout);
	// -------------------------------------------
	// ft_printf("%42x\n", t_int);
	// fflush(stdout);
	// printf("%42x\n", t_int);
	// -------------------------------------------
	// ft_printf("% .42x\n", t_int);
	// printf("% .42x\n", t_int);
	// fflush(stdout);
	// -------------------------------------------
	// ft_printf("%ll42x\n", t_int);
	// printf("%ll42x\n", t_int);
	// fflush(stdout);




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

// gcc -Wall -Wextra print_b.c print_c.c print_i.c print_u.c print_s.c print_p.c print_o.c print_x.c print_%.c print_f.c print_ff.c big_int.c ft_printf.c itoa_base.c main.c mem.c parse.c else.c test.c width_csp.c width_dioux.c -o test && ./test | cat -e


Bonus: gestion de buffer, couleur, multi fd (write(fd, ..., ...)), %* (padding sur le 1er arg), binaire etc ...
Gestion: printf(NULL);
// long long      ft_convert_base(long long value, int base)
// {
//     long long ret;

//     ret = 0;
//     while (value)
//     {
//         if (ret % 10 >= base)
//         {
//             ret /= 10;
//             ret++;
//             ret *= 10;
//         }
//         ret++;
//         value--;
//     }
//     return (ret);
//}
*/