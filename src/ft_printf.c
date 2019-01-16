/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nivergne <nivergne@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/12/23 16:58:54 by nivergne          #+#    #+#             */
/*   Updated: 2019/01/16 00:04:08 by nivergne         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/ft_printf.h"

void    (*funptr[11])(va_list, t_info *) = {
    &ft_addchar,
    &ft_addstr,
    &ft_addaddr,
    &ft_addnbr,
    &ft_addnbr,
    &ft_addoct,
    &ft_adduns,
    &ft_addhexmin,
    &ft_addhexmaj,
    &ft_addbin,
	&ft_addpercent,
};

void	addbuff(char *str, t_info __unused *options)
{
	int		i;

	i = 0;
	if (str != NULL)
	{
		while (str[i])
		{
			append_to_buff(str[i], 0);
			i++;
		}
	}
}


int		append_to_buff(char c, int print)
{
	static int		index = 0;
	static char		*buff = NULL;

	if (!buff)
	{
		if (!(buff = ft_memalloc(4096)))
			exit(0);
	}
	if (print == 0)
		buff[index] = c;
	else if (print == 1 && ft_strlen(buff) != 0)
	{
		ft_putstr(buff);
		ft_bzero(buff, 4096);
	}
	else if (print == 2)
	{
		buff = NULL;
		index = 0;
		return (0);
	}
	index++;
	return (index);
}

int		parse_str(char *str, t_info *options)
{
	int		shift;

	shift = 0;
	while (check_flag(str[shift], options) == 1)
		shift++;
	while (check_width(str[shift], options) == 1)
		shift++;
	while (check_accuracy(str[shift], options) == 1)
		shift++;
	while (check_type(str[shift], options) == 1)
		shift++;
	if (check_conversion(str[shift], options) == 1)
		shift++;
	else
	{
		usage();
		exit(1); //exit in usage?
	}
	ft_put_info(options);
	return (shift);
}


int		ft_printf(char *str, ...)
{
	int		i;
	va_list	arg;
	t_info	options;

	i = 0;
	va_start(arg, str);
	append_to_buff(0, 2);
	while (str[i])
	{
		if (str[i] == '%')
		{
			t_info_init(&options);
			i = i + parse_str(str + i + 1, &options);
			funptr[options.conversion](arg, &options);
		}
		else
			append_to_buff(str[i], 0);
		if (i == 4096)
			append_to_buff(0, 1);
		i++;
	}
	append_to_buff(0, 1);
	va_end(arg);
	return (i);
}
