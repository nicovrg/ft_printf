/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nivergne <nivergne@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/12/28 02:16:02 by nivergne          #+#    #+#             */
/*   Updated: 2019/01/04 23:23:40 by nivergne         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/ft_printf.h"

void	ft_addchar(char c)
{
	append_to_buff(c);
}

void	ft_addstr(char const *s)
{
	int	i;

	i = 0;
	if (s != NULL)
	{
		while (s[i])
		{
			append_to_buff(s[i]);
			i++;
		}
	}
}

void	ft_addnbr(int nb)
{
	unsigned int nbr;

	if (nb < 0)
	{
		append_to_buff('-');
		nb = -nb;
	}
	nbr = (unsigned int)nb;
	if (nbr >= 10)
	{
		ft_addnbr(nbr / 10);
		append_to_buff(nbr % 10 + '0');
	}
	else
		append_to_buff(nbr % 10 + '0');
}

void    ft_adduns(unsigned nb)
{
	unsigned int nbr;

	if (nb < 0)
	{
		append_to_buff('-');
		nb = -nb;
	}
	nbr = (unsigned int)nb;
	if (nbr >= 10)
	{
		ft_adduns(nbr / 10);
		append_to_buff(nbr % 10 + '0');
	}
	else
		append_to_buff(nbr % 10 + '0');
}

void    ft_addaddr()
{}