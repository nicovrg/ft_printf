/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nivergne <nivergne@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/12/23 16:48:36 by nivergne          #+#    #+#             */
/*   Updated: 2019/01/17 02:01:35 by nivergne         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H

# include <unistd.h>
# include <stdarg.h>
//# include <string.h>
# include "libft.h"

typedef struct  s_info
{
    int         zero;
    int         plus;
    int         minus;
    int         space;
    int         hashtag;
    int         percent;
    int         width;
    int         accuracy;
    int         type;
    int         conversion;
}               t_info;

//main.c

//test.c
void            ft_put_info(t_info *info);

//else.c
int             t_info_init(t_info *options);
int             width_size(t_info *options, long long cast_ap);
int             ft_accuracy(t_info *options);
void            usage();

//mem.c
void            ft_bzero(void *s, size_t n);
void            *ft_memset(void *b, int c, size_t len);
void            *ft_memalloc(size_t size);
void            ft_putchar(char c);
void            ft_putstr(char const *s);
void            ft_putnbr(int n);
size_t          ft_strlen(const char *s);

//itoa_base.c
long long       ft_abs(long long value);
long long       res_size(long long value, int base);
char			*fill_base(int base, int l);
char			*neg_int(long long value);
char			*ft_itoa_base(long long value, int base, int l);

//print_csp.c
void            ft_addchar(va_list ap, t_info *options);
void            ft_addstr(va_list ap, t_info *options);
void            ft_addaddr(va_list ap, t_info *options);
void            ft_addpercent(va_list ap, t_info *options);

//print_ui.c
void            ft_addnbr_core(long long nb, t_info *options);
void            ft_addnbr(long long cast_ap, t_info *options);
void            ft_adduns_core(unsigned long long nb, t_info *options);
void            ft_adduns(va_list ap, t_info *options);
void	        ft_nbr(va_list ap, t_info *options);

//print_base.c
void            ft_addbin(va_list ap, t_info *options);
void            ft_addoct(va_list ap, t_info *options);
void            ft_addhexmin(va_list ap, t_info *options);
void            ft_addhexmaj(va_list ap, t_info *options);
void            ft_addfloat(va_list ap, t_info *options);

//width_csp.c
void            addwidth_char(int nb);
void            addwidth_string(int nb, char *cast_ap);
void            addwidth_pointer(int nb, char * __unused cast_ap);

//width_ui.c


//parse.c
int		        check_flag(char c, t_info *options);
int		        check_width(char c, t_info *options);
int		        check_accuracy(char c, t_info *options);
int		        check_type(char c, t_info *options);
int		        check_conversion(char c, t_info *options);

//ft_printf.c
void            (*funptr[11])(va_list, t_info *);
void	        addbuff(char *str, t_info *options);
int		        parse_str(char *buff, t_info *options);
int		        append_to_buff(char c, int print);
int		        ft_printf(char *buff, ...); 

// mettre attribute __attribute__ ((format (printf, 1, 2))) 

#endif


//# include <stdlib.h>
//# include <ctype.h>
//# include <sys/types.h>
//# include <sys/stat.h>
//# include <fcntl.h>
//# include <stdio.h>


//gcc -Wall -Werror -Wextra print_base.c print_csp.c print_ui.c ft_printf.c itoa_base.c main.c mem.c parse.c else.c test.c width_csp.c width_ui.c -o test && ./test | cat -e