/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_s.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jquivogn <jquivogn@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/12/28 02:16:02 by nivergne          #+#    #+#             */
/*   Updated: 2019/02/11 18:04:29 by jquivogn         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void			ft_addstr(va_list ap, t_info *o)
{
	char		*cast_ap;
	const char	null[] = "(null)";
	char		*tmp;
	int			len;

	tmp = va_arg(ap, char *);
	cast_ap = NULL;
	if ((o->type == 2 || o->conversion == 13) && tmp)
		return (ft_strwchar((char *)tmp, o));
	else
	{
		len = ft_strlen(tmp ? tmp : "(null)");
		if (!(cast_ap = (char *)malloc(sizeof(char) * len)))
			return ;
		cast_ap = ft_strcpy(cast_ap, tmp ? tmp : null);
		ft_strchar(cast_ap, o);
		free(cast_ap);
	}
}

void			ft_strchar(char *cast_ap, t_info *o)
{
	int	size;

	size = ft_strlen(cast_ap);
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
}

void			ft_strwchar(char *tmp, t_info *o)
{
	int		len;
	wchar_t	*str;

	len = 0;
	while (tmp[len])
		len++;
	if (!(str = (wchar_t *)malloc(sizeof(wchar_t) * (len * 4 + 1))))
		return ;
	str[len] = '\0';
	str = (wchar_t *)tmp;
	if (o->width > 0)
	{
		if (o->accuracy)
			o->minus == 1 ? print_ls(str, o) : 0;
		addwidth_string(o->width, (char *)str, o);
		if (o->accuracy)
			o->minus == 0 ? print_ls(str, o) : 0;
	}
	else if (o->width == -1 && o->accuracy)
		print_ls(str, o);
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
		ft_putwchar(str[i], o);
	}
}
