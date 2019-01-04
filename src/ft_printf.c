/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nivergne <nivergne@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/12/23 16:58:54 by nivergne          #+#    #+#             */
/*   Updated: 2019/01/04 17:34:27 by nivergne         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/ft_printf.h"

int		check_str(char *str)
{
	int		shift;

	shift = 0;
	if (str[0] == '%')
	{

	}
}

int		append_to_buff(char c)
{
	static int		index = 0;
	static char		*buff = NULL;

	if (!buff)
	{
		if (!(buff = ft_memalloc(4096)))
			return (NULL);
	}
	buff[index] = c;
	index++;
}

int		ft_printf(char *str)
{
	int		i;

	i = 0;

	while (str[i])
	{
		if (str[i] == '%')
			i = i + check_str(str + i);
		else
			append_to_buff(str[i]);
		i++;
	}
	return (0);
}

//int		ft_printf(char *buff, ...)