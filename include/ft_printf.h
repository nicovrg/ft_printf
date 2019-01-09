/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nivergne <nivergne@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/12/23 16:48:36 by nivergne          #+#    #+#             */
/*   Updated: 2019/01/09 01:27:10 by nivergne         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef __FT__PRINTF__H__
# define __FT__PRINTF__H__

# include <unistd.h>
//# include <string.h>
//# include <stdarg.h>
# include "libft.h"

typedef struct  s_info
{
    int         zero : 1;
    int         plus : 1;
    int         minus : 1;
    int         space : 1;
    int         hashtag : 1;
    int         width;
    int         accuracy;
    int         type;
    char        conversion;
}               t_info;

//main.c

//test.c
void            ft_put_info(t_info *info);

//else.c
int             t_info_init(t_info *options);

//itoa_base.c
static int      get_size(int n, int base);
static char     *ft_itoa_core(unsigned int nb, unsigned int base, int sign, int size);
char            *ft_itoa_base(int n, int base);

//mem.c
void            ft_bzero(void *s, size_t n);
void            *ft_memset(void *b, int c, size_t len);
void            *ft_memalloc(size_t size);

//print.c
void            ft_addchar(char c);
void            ft_addstr(char const *s);
void            ft_addnbr(int nb);
void            ft_adduns(unsigned nb);
void            ft_addaddr();

//conv.c
void            ft_addbin();
void            ft_addoct();
void            ft_addhexmin();
void            ft_addhexmaj();
void            ft_addfloat();

//parse.c
int		        check_flag(char c, t_info *options);
int		        check_width(char c, t_info *options);
int		        check_accuracy(char c, t_info *options);
int		        check_type(char c, t_info *options);
int		        check_conversion(char c, t_info *options);

//ft_printf.c
int		        parse_str(char *buff, t_info *options);
int		        append_to_buff(char c);
int		        ft_printf(char *buff); //, ...

#endif


//# include <stdlib.h>
//# include <ctype.h>
//# include <sys/types.h>
//# include <sys/stat.h>
//# include <fcntl.h>
//# include <stdio.h>