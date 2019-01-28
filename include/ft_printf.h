/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: julesqvgn <julesqvgn@student.42.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/12/23 16:48:36 by nivergne          #+#    #+#             */
/*   Updated: 2019/01/28 00:40:29 by julesqvgn        ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H

# include <unistd.h>
# include <stdarg.h>
//# include <string.h>
# include "libft.h"

# define BUFF_SIZE 64

typedef struct	s_info
{
	int		zero;
	int		plus;
	int		minus;
	int		space;
	int		hashtag;
	int		percent;
	int		width;
	int		accuracy;
	int		type;
	int		conversion;
	int		neg;
	int		llmin;
	int		init;
	int		ret;
	int		index;
	char	buff[BUFF_SIZE];
}				t_info;

//main.c

//print_f.c
void			ft_addfloat(va_list ap, t_info *options);

//test.c
void			ft_put_info(t_info *info);

//else.c
int				t_info_init(t_info *options, int i);
int				ft_accuracy(t_info *options);
void			usage();

//mem.c
void			ft_bzero(void *s, size_t n);
void			*ft_memset(void *b, int c, size_t len);
void			*ft_memalloc(size_t size);
void			ft_putchar(char c);
void			ft_putstr(char const *s);
void			ft_putnbr(int n);
size_t			ft_strlen(const char *s);
int				ft_atoi(const char *str);

//itoa_base.c
long long		ft_abs(long long value);
long long		res_size(long long value, int base);
char			*fill_base(int base, int l);
char			*neg_int(long long value);
char			*ft_itoa_base(long long value, int base, int l);

//print_%.c
void			ft_addpercent(va_list ap, t_info *options);

//print_c.c
void			ft_addchar(va_list ap, t_info *options);

//print_s.c
void			ft_addstr(va_list ap, t_info *options);

//print_p.c
void			ft_addaddr(va_list ap, t_info *options);

//print_i.c
void			ft_nbr(va_list ap, t_info *options);
void			ft_nbrsign(t_info *options);
void			ft_addnbr(long long cast_ap, t_info *options);
void			ft_addnbr_core(long long nb, t_info *options);

//print_u.c
void			ft_uns(va_list ap, t_info *options);
void			ft_adduns(long long cast_ap, t_info *options);
void			ft_adduns_core(unsigned long long nb, t_info *options);

//print_o.c
void			ft_oct(va_list ap, t_info *options);
void			ft_addoct(long long cast_ap, t_info *options);

//print_x.c
void			ft_hex(va_list ap, t_info *options);
void			ft_addhexmin(char *cast_ap, t_info *options);
void			ft_addhexmaj(char *cast_ap, t_info *options);

//print_b.c
void			ft_addbin(va_list ap, t_info *options);

//width_csp.c
void			addwidth_char(int nb, t_info *options);
void			addwidth_string(int nb, char *cast_ap, t_info *options);
void			addwidth_pointer(int nb, char * __unused cast_ap, t_info *options);
void			char_null(int cast_ap, t_info *options);
char			*string_for_null(char *cast_ap);

//width_dioux.c
int				width_size_diou(t_info *options, long long cast_ap, int base);
int				width_size_x(t_info *options, char *cast_ap);
int				width_size_o(t_info *options, unsigned long long cast_ap);
void			width_for_null(t_info *options);
int				itooct(int nb);

//parse.c
int				check_flag(char c, t_info *options);
int				check_width(char c, t_info *options);
int				check_accuracy_one(char c, t_info __unused *options);
int				check_accuracy_two(char c, t_info *options);
int				check_type(char c, t_info *options);
int				check_conversion(char c, t_info *options);

//ft_printf.c
void			(*funptr[11])(va_list, t_info *);
void			addbuff(char *str, t_info *options);
int				parse_str(char *buff, t_info *options);
int				append_to_buff(char c, int print, t_info *options);
int				ft_printf(char *buff, ...); 

// mettre attribute __attribute__ ((format (printf, 1, 2))) 

#endif


//# include <stdlib.h>
//# include <ctype.h>
//# include <sys/types.h>
//# include <sys/stat.h>
//# include <fcntl.h>
//# include <stdio.h>


//gcc -Wall -Werror -Wextra print_base.c print_csp.c print_ui.c ft_printf.c itoa_base.c main.c mem.c parse.c else.c test.c width_csp.c width_ui.c -o test && ./test | cat -e