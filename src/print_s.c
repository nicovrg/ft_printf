/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_s.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nivergne <nivergne@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/12/28 02:16:02 by nivergne          #+#    #+#             */
/*   Updated: 2019/02/07 21:17:12 by nivergne         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

//#include "ft_printf.h"
#include "../include/ft_printf.h"

void			ft_addstr(va_list ap, t_info *o)
{
	char		*cast_ap;
	char		*tmp;
	int			size;
	int			len;

	tmp = va_arg(ap, char *);
	if (!tmp)
	{
		if (!(cast_ap = string_for_null()))
			return ;
	}
	else if (o->type == 2 || o->conversion == 13)
	{
		ft_strwchar((char *)tmp, o);
		return ;
	}
	else
	{
		len = ft_strlen(tmp);
		if (!(cast_ap = (char *)malloc(sizeof(char) * len)))
			return ;
		cast_ap = ft_strcpy(cast_ap, tmp);
	}
	size = ft_strlen(cast_ap);
	if (o->accuracy > 0 && o->accuracy < size)
		cast_ap[o->accuracy] = '\0';
	if (o->width > 0)
	{
		if (o->accuracy)
			o->minus == 1 ? addbuff(cast_ap, o) : 0;
		addwidth_string(o->width, cast_ap, o);
		if (o->accuracy)
			o->minus == 0 ? addbuff(cast_ap, o) : 0;
	}
	else if (o->width == -1 && o->accuracy)
		addbuff(cast_ap, o);
	//free(cast_ap);
}

void			ft_strwchar(char *tmp, t_info *o)
{
	int		len;
	wchar_t	*str;

	len = 0;
	while (tmp[len])
		len++;
	if (!(str = (wchar_t *)malloc(sizeof(wchar_t) * (len + 1))))
		return ;
	str[len] = '\0';
	str = (wchar_t *)tmp;
	if (o->width > 0)
	{
		if (o->accuracy)
			o->minus == 1 ? print_ls(str, o) : 0;
		addwidth_wstring(o->width, str, o);
		if (o->accuracy)
			o->minus == 0 ? print_ls(str, o) : 0;
	}
	else if (o->width == -1 && o->accuracy)
		print_ls(str, o);
	//free(str);
}

void			print_ls(wchar_t *str, t_info *o)
{
	int	i;
	int	range;

	i = 0;
	range = 0;
	while (str[range])
		range++;
	range = o->accuracy == -1 ? range * 4 : o->accuracy;
	append_to_buff(0, 1, o);
	while (str[i++] && range > 0)
	{
		if ((range > 0 || range < 0) && str[i] <= 0x7F)
			range -= 1;
		else if ((range > 1 || range < 0) && str[i] <= 0x7FF)
			range -= 2;
		else if ((range > 2 || range < 0) && str[i] <= 0xFFFF)
			range -= 3;
		else if ((range > 3 || range < 0) && str[i] <= 0x10FFFF)
			range -= 4;
		else
			break ;
		o->ret++;
		ft_putwchar(str[i], o);
	}
	append_to_buff(0, 1, o);
}

void			addwidth_wstring(int nb, wchar_t *cast_ap, t_info *o)
{
	int	i;
	int	size;
	int	s_oct;
	int	tmp;

	size = -1;
	i = -1;
	s_oct = 0;
	while (cast_ap[++size] != '\0')
		s_oct += size_wchar(cast_ap[size]);
	if (o->accuracy > nb && size)
		nb = 0;
	else if (o->accuracy == -1 && nb > s_oct)
		nb -= s_oct;
	else if (o->accuracy < nb && o->accuracy > -1 && size > 0)
		nb -= o->accuracy - 1;
	else if (o->accuracy == -1)
	{
		while (cast_ap[++i] != '\0')
		{
			if (nb <= 0)
				break ;
			nb -= size_wchar(cast_ap[i]);
		}
	}
	else
	{
		i = 0;
		tmp = 0;
		while (cast_ap[++i] != '\0')
		{
			if (nb <= (nb - o->accuracy > 0 ? o->accuracy : 0))
			{
				nb = nb == 0 ? 0 : tmp;
				break ;
			}
			tmp = nb;
			nb -= size_wchar(cast_ap[i]);
		}
	}
	while (nb-- > 0)
		append_to_buff(o->zero && !o->minus && o->accuracy < 0
		? '0' : ' ', 0, o);
}

int				size_wchar(wchar_t c)
{
	if (c <= 0x7F)
		return (1);
	else if (c <= 0x7FF)
		return (2);
	else if (c <= 0xFFFF)
		return (3);
	else if (c <= 0x10FFFF)
		return (4);
	return (0);
}
