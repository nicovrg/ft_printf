/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   width_csp.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: julesqvgn <julesqvgn@student.42.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/01/11 22:11:13 by nivergne          #+#    #+#             */
/*   Updated: 2019/02/01 01:57:11 by julesqvgn        ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

//#include "ft_printf.h"
#include "../include/ft_printf.h"

void		addwidth_char(int nb, t_info *options)
{
	while (nb > 1)
	{
		append_to_buff(options->zero && !options->minus && options->accuracy < 0 ? '0' : ' ', 0, options);
		nb--;
	}
}

void		addwidth_string(int nb, char *cast_ap, t_info *options)
{
	int	len;
	int	size;

	size = ft_strlen(cast_ap);
	if (options->accuracy > 0)
		len = nb - (size > options->accuracy ? options->accuracy : size);
	else if (options->accuracy == -1)
		len = nb - size;
	else
		len = nb;
	while (len > 0)
	{
		append_to_buff(options->zero && !options->minus && options->accuracy < 0 ? '0' : ' ', 0, options);
		len--;
	}
}

void		addwidth_pointer(int nb, char * __unused cast_ap, t_info *options)
{
	int len;

	len = nb - 11;
	while (len > 0)
	{
		append_to_buff(' ', 0, options);
		len--;
	}
}

void		char_null(int cast_ap, t_info *options)
{
	options->ret++;
	(void)cast_ap;
	//options->buff[options->index++] = '\x';
	if (options->index == BUFF_SIZE)
		append_to_buff(0, 1, options);
	options->buff[options->index++] = '\0' + cast_ap;
}

char	*string_for_null(void)
{
	char	*str;

	if (!(str = (char *)malloc(sizeof(char) * 6)))
		return (NULL);
	str = ft_strcpy(str, "(null)");
	return (str);
}