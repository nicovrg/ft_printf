/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jquivogn <jquivogn@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/12/23 16:48:36 by nivergne          #+#    #+#             */
/*   Updated: 2019/02/06 20:11:07 by jquivogn         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H

# include <unistd.h>
# include <stdarg.h>
# include <wchar.h>
# include "libft.h"

# define BUFF_SIZE 256

typedef struct	s_float
{
	int					sign;
	unsigned long long	exponent;
	unsigned long long	mantis;
	unsigned char		big_expo[10000];
	unsigned char		big_mant[10000];
}				t_float;


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
	t_float	f;
}				t_info;

//main.c

//main.c

//big_int.c
void			update_bigstring(int i, t_info *options);
void			multi_bigstring(t_info *options);
void			exponent_bigint(t_info *options);

//print_f.c
void			ft_addfloat(va_list ap, t_info *options);
void			ft_add_fsign(t_info *options);
void			ft_add_fexpo(t_info *options);


//print_ff.c
void			ft_initfloat(t_info *options);
void			ft_extract_sign(unsigned char *char_ap, t_info *options);
void			ft_extract_expo(unsigned char *char_ap, t_info *options);
void			ft_extract_mant(unsigned char *char_ap, t_info *options);

//test.c
void			ft_put_binary1(unsigned char byte);
void			ft_put_binary2(unsigned long long byte);
void			show_float_test(unsigned char *char_ap, t_info *options);
void			ft_show_extracted(unsigned char *char_ap, t_info *options);
void			ft_showbin_sign(t_info *options);
void			ft_showbin_expo(t_info *options);
void			ft_showbin_mant(t_info *options);
void			ft_showbin_addfloat(unsigned char *char_ap);
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
char			*ft_strjoin(char const *s1, char const *s2);
//not in libft
void				ft_putunll(unsigned long long n);
void				ft_putstr_test(unsigned char *s);
// size_t			ft_strlen_test(unsigned char *s);
// void				paws(unsigned char *a, unsigned char *b);
// unsigned char	*esreverse(unsigned char *str);

//itoa_base.c
unsigned long long		res_size(unsigned long long value, int base);
char			*fill_base(int base, int l);
char			*ft_itoa_base(unsigned long long value, int base, int l);

//print_%.c
void			ft_addpercent(va_list ap, t_info *options);

//print_c.c
void			ft_addchar(va_list ap, t_info *options);
void			ft_addwchar(va_list ap, t_info *options);
void			ft_putwchar(wchar_t c, t_info *options);
void			addwidth_wchar(wchar_t c, int nb, t_info *options);
int				size_wchar(wchar_t c);

//print_s.c
void			ft_addstr(va_list ap, t_info *options);
void			ft_strwchar(char *tmp, t_info *options);
void			print_ls(wchar_t *str, t_info *options);
char			*ft_strcpy(char *dest, const char *src);
void			addwidth_wstring(int nb, wchar_t *cast_ap, t_info *options);

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
void			ft_adduns_core(unsigned long long nb, t_info *options, int base);

//print_o.c
void			ft_oct(va_list ap, t_info *options);
void			ft_addoct(unsigned long long cast_ap, t_info *options);
void			oct_for_null(t_info *options);

//print_x.c
void			ft_hex(va_list ap, t_info *options);
void			ft_addhexmin(char *cast_ap, t_info *options);
void			ft_addhexmaj(char *cast_ap, t_info *options);
void			hex_for_null(t_info *options);

//print_b.c
void			ft_addbin(va_list ap, t_info *options);

//width_csp.c
void			addwidth_char(int nb, t_info *options);
void			addwidth_string(int nb, char *cast_ap, t_info *options);
void			addwidth_pointer(int nb, char * __unused cast_ap, t_info *options);
void			char_null(int cast_ap, t_info *options);
char			*string_for_null(void);

//width_dioux.c
int				width_size_diou(t_info *options, long long cast_ap, int base);
int				width_size_x(t_info *options, char *cast_ap);
int				width_size_o(t_info *options, unsigned long long cast_ap);
void			width_for_null(t_info *options);
unsigned long long	itooct(unsigned long long nb);
int				width_bin(t_info *options);

//parse.c
int				check_flag(char c, t_info *options);
int				check_width(char c, t_info *options);
int				check_accuracy_one(char c, t_info __unused *options);
int				check_accuracy_two(char c, t_info *options);
int				check_type(char c, t_info *options);
int				check_conversion(char c, t_info *options);

//ft_printf.c
void			(*funptr[12])(va_list, t_info *);
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