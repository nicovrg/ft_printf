/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: julesqvgn <julesqvgn@student.42.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/12/23 16:58:54 by nivergne          #+#    #+#             */
/*   Updated: 2019/01/26 00:46:05 by julesqvgn        ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

//#include "ft_printf.h"
#include "../include/ft_printf.h"

void	(*funptr[11])(va_list, t_info *) = {
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
	&ft_addpercent,
};

void	addbuff(char *str, t_info __unused *options)
{
	int		i;

	i = 0;
	if (str != NULL)
	{
		while (str[i] != '\0')
		{
			append_to_buff(str[i], 0, options);
			i++;
		}
	}
}

int		parse_str(char *str, t_info *options)
{
	int		shift;
	int		i;

	shift = 0;
	i = 0;
	while (!check_conversion(str[shift], options) && str[i] != '\0')
	{
		while (check_flag(str[shift], options) == 1)
			shift++;
		while (check_width(str[shift], options) == 1)
			shift++;
		if (check_accuracy_one(str[shift], options) == 1)
			shift++;
		while (check_accuracy_two(str[shift], options) == 1)
			shift++;
		while (check_type(str[shift], options) == 1)
			shift++;
		i++;
	}
	if (check_conversion(str[shift], options) == 1)
		shift++;
		//usage();
	//ft_put_info(options);
	return (shift);
}

int		append_to_buff(char c, int print, t_info *options)
{
	if (print == 0)
		options->buff[options->index] = c;
	else if (print == 1 && ft_strlen(options->buff) != 0)
	{
		options->index = -1;
		ft_putstr(options->buff);
		ft_bzero(options->buff, BUFF_SIZE);
	}
	options->index++;
	return (options->ret++);
}

int		ft_printf(char *str, ...)
{
	int		i;
	int		j;
	va_list	arg;
	t_info	options;

	i = 0;
	j = 0;
	va_start(arg, str);
	t_info_init(&options, i);
	while (str[i])
	{
		if (str[i] == '%')
		{
			t_info_init(&options, i);
			i = i + parse_str(str + i + 1, &options);
			options.conversion != -1 ? funptr[options.conversion % 11](arg, &options): 0 ;
		}
		else
			append_to_buff(str[i], 0, &options);
		i == 4096 ? append_to_buff(0, 1, &options) : 0;
		j++;
		i++;
	}
	va_end(arg);
	return (append_to_buff(0, 1, &options));
}
