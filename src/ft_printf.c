/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: julesqvgn <julesqvgn@student.42.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/12/23 16:58:54 by nivergne          #+#    #+#             */
/*   Updated: 2019/02/08 13:34:17 by julesqvgn        ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

//#include "ft_printf.h"
#include "../include/ft_printf.h"

void	(*funptr[12])(va_list, t_info *) = {
	&ft_addchar,
	&ft_addstr,
	&ft_addaddr,
	&ft_nbr,
	&ft_nbr,
	&ft_oct,
	&ft_uns,
	&ft_hex,
	&ft_hex,
	&ft_addbin,
	&ft_addfloat,
	&ft_addpercent,
};

void	addbuff(char *str, t_info *o)
{
	int		i;

	i = 0;
	if (str != NULL)
	{
		while (str[i] != '\0')
		{
			append_to_buff(str[i], 0, o);
			i++;
		}
	}
}

int		parse_str(char *str, t_info *o)
{
	int		shift;
	int		i;

	shift = 0;
	i = 0;
	while (!check_conversion(str[shift], o) && str[i] != '\0')
	{
		while (check_flag(str[shift], o) == 1)
			shift++;
		while (check_width(str[shift], o) == 1)
			shift++;
		if (check_accuracy_one(str[shift], o) == 1)
			shift++;
		while (check_accuracy_two(str[shift], o) == 1)
			shift++;
		while (check_type(str[shift], o) == 1)
			shift++;
		i++;
	}
	if (check_conversion(str[shift], o) == 1)
		shift++;
	else if (o->width > 0)
		while (o->width-- > 1)
			append_to_buff(' ', 0, o);
	return (shift);
}

int		append_to_buff(char c, int print, t_info *o)
{
	if (print == 0)
		o->buff[o->index] = c;
	else if (print == 1)
	{
		o->index = 0;
		ft_putstr(o->buff);
		ft_bzero(o->buff, BUFF_SIZE);
		return (o->ret);
	}
	o->index++;
	if (o->index == BUFF_SIZE - 1)
		append_to_buff(0, 1, o);
	return (o->ret++);
}

int		ft_printf(char *str, ...)
{
	int		i;
	int		j;
	va_list	arg;
	t_info	o;

	i = 0;
	j = 0;
	va_start(arg, str);
	t_info_init(&o, i);
	while (str[i])
	{
		if (str[i] == '%')
		{
			t_info_init(&o, i);
			i = i + parse_str(str + i + 1, &o);
			o.conversion != -1 ? funptr[o.conversion % 12](arg, &o): 0;
		}
		else
			append_to_buff(str[i], 0, &o);
		i == BUFF_SIZE - 1 ? append_to_buff(0, 1, &o) : 0;
		j++;
		i++;
	}
	va_end(arg);
	return (append_to_buff(0, 1, &o));
}

/*
-padding accuracy octal
-check utilite toute les fonctions
-leaks
-normes
-tester les min et les max
-rechecker tout les test
-voir avec les valeur 0
-expliquer si fct non comprise
-arranger le makefile
-ajouter la libft au projets
-valider ce projet de merde
-octal long max
-precision null pointeur
*/ 
