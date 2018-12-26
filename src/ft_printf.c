/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nivergne <nivergne@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/12/23 16:58:54 by nivergne          #+#    #+#             */
/*   Updated: 2018/12/26 02:02:32 by nivergne         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/ft_printf.h"

int		check_buff(char *buff)
{

	if (buff[0] == '%')
	{

	}
}

int		ft_printf(char *buff, ...)
{
	int		i;

	i = 0;
	while (buff[i])
	{
		if (check_buff(buff + i) == 1)
			...;
		else
			ft_putstr();
		i++;
	}
	return (0);
}
