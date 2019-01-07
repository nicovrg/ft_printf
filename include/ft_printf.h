/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nivergne <nivergne@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/12/23 16:48:36 by nivergne          #+#    #+#             */
/*   Updated: 2019/01/07 20:49:50 by nivergne         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef __FT__PRINTF__H__
# define __FT__PRINTF__H__

# include <unistd.h>
//# include <string.h>
//# include <stdarg.h>

typedef struct s_info
{
    int     zero : 1;
    int     plus : 1;
    int     minus : 1;
    int     space : 1;
    int     hashtag : 1;
    int     width;
    int     accuracy;
    int     type;
    char    conversion;
} t_info;

//main.c

//mem.c
void	ft_bzero(void *s, size_t n);
void	*ft_memset(void *b, int c, size_t len);
void	*ft_memalloc(size_t size);

//print.c
void	ft_addchar(char c);                     //%c
void	ft_addstr(char const *s);               //%s
void	ft_addnbr(int nb);                      //%d %i
void    ft_adduns(unsigned nb);                 //%u
void    ft_addaddr();                           //%p

//conv.c
void    ft_addbin();                            //%b
void    ft_addoct();                            //%o
void    ft_addhexmin();                         //%x
void    ft_addhexmaj();                         //%X
void    ft_addfloat();                          //%f

//parse.c
int		check_flag(char c, t_info *options);
int		check_width(char c, t_info *options);
int		check_accuracy(char c, t_info *options);
int		check_type(char c, t_info *options);
int		check_conversion(char c, t_info *options);

//ft_printf.c
int		parse_str(char *buff, t_info *options);
int		append_to_buff(char c);
int		ft_printf(char *buff); //, ...

#endif


//# include <stdlib.h>
//# include <ctype.h>
//# include <sys/types.h>
//# include <sys/stat.h>
//# include <fcntl.h>
//# include <stdio.h>