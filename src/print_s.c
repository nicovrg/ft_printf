/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_s.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jquivogn <jquivogn@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/12/28 02:16:02 by nivergne          #+#    #+#             */
/*   Updated: 2019/01/28 18:21:34 by jquivogn         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

//#include "ft_printf.h"
#include "../include/ft_printf.h"

char	*ft_strcpy(char *dest, const char *src)
{
	int i;

	i = 0;
	while (*src)
	{
		*dest = *src;
		dest++;
		src++;
		i++;
	}
	*dest = '\0';
	return (dest - i);
}

void	ft_addstr(va_list ap, t_info *options)
{
	char		*cast_ap;
	const char	*tmp = va_arg(ap, char *);
	int			size;
	int			len;

	if (!tmp)
	{
		if (!(cast_ap = string_for_null()))
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
	if (options->accuracy > 0 && options->accuracy < size)
		cast_ap[options->accuracy] = '\0';
	if (options->width > 0)
	{
		if (options->accuracy)
			options->minus == 1 ? addbuff(cast_ap, options) : 0;
		addwidth_string(options->width, cast_ap, options);
		if (options->accuracy)
			options->minus == 0 ? addbuff(cast_ap, options) : 0;
	}
	else if (options->width == -1 && options->accuracy)
		addbuff(cast_ap, options);
	free(cast_ap);
}
