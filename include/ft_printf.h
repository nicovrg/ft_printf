/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nivergne <nivergne@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/12/23 16:48:36 by nivergne          #+#    #+#             */
/*   Updated: 2018/12/28 02:25:05 by nivergne         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef __FT__PRINTF__H__
# define __FT__PRINTF__H__

# include <unistd.h>
//# include <string.h>

//main.c

//print.c
void	ft_putchar(char c);
void	ft_putstr(char const *s);
void	ft_putnbr(int n);

//ft_printf.c
int		check_buff(char *buff);
int		ft_printf(char *buff, ...);

#endif


//# include <stdlib.h>
//# include <ctype.h>
//# include <sys/types.h>
//# include <sys/stat.h>
//# include <fcntl.h>
//# include <stdio.h>