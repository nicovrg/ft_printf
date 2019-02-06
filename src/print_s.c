/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_s.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jquivogn <jquivogn@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/12/28 02:16:02 by nivergne          #+#    #+#             */
/*   Updated: 2019/02/06 20:54:43 by jquivogn         ###   ########.fr       */
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
	char		*tmp;
	int			size;
	int			len;

	tmp = va_arg(ap, char *);
	if (!tmp)
	{
		if (!(cast_ap = string_for_null()))
			return ;
	}
	else if (options->type == 2 || options->conversion == 13)
	{
		ft_strwchar((char *)tmp, options);
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
	//free(cast_ap);
}

void	ft_strwchar(char *tmp, t_info *options)
{
	wchar_t	*str;
	int		len;

	len = -1;
	while (tmp[++len] != '\0');
	if (!(str = (wchar_t *)malloc(sizeof(wchar_t) * (len + 1))))
		return ;
	str[len] = '\0';
	str = (wchar_t *)tmp;
	if (options->width > 0)
	{
		if (options->accuracy)
			options->minus == 1 ? print_ls(str, options) : 0;
		addwidth_wstring(options->width, str, options);
		if (options->accuracy)
			options->minus == 0 ? print_ls(str, options) : 0;
	}
	else if (options->width == -1 && options->accuracy)
		print_ls(str, options);
	//free(str);
}

void	print_ls(wchar_t *str, t_info *options)
{
	int	i;
	int	range;

	i = 0;
	range = -1;
	while (str[++range] != '\0');
	range = options->accuracy == -1 ? range * 4: options->accuracy;
	append_to_buff(0, 1, options);
	while (str[i] != '\0' && range > 0)
	{
		if ((range > 0 || range < 0 ) && str[i] <= 0x7F)
			range -= 1;
		else if ((range > 1 || range < 0 ) && str[i] <= 0x7FF)
			range -= 2;
		else if ((range > 2 || range < 0 ) && str[i] <= 0xFFFF)
			range -= 3;
		else if ((range > 3 || range < 0 ) && str[i] <= 0x10FFFF)
			range -= 4;
		else
			break ;
		options->ret++;
		ft_putwchar(str[i], options);
		i++;
	}
	append_to_buff(0, 1, options);
}

void		addwidth_wstring(int nb, wchar_t *cast_ap, t_info *options)
{
	int	size;	/*taille str*/
	int	i;		/*index quelconque*/\
	int	s_oct;
	int	tmp;
				/*nb egal a width*/
	size = -1;
	i = -1;
	s_oct = 0;
	while (cast_ap[++size] != '\0')
		s_oct += size_wchar(cast_ap[size]);
	if (options->accuracy > nb && size)
		nb = 0;
	else if (options->accuracy == -1 && nb > s_oct)
		nb -= s_oct;
	else if (options->accuracy < nb && options->accuracy > -1 && size > 0)
		nb -= options->accuracy - 1;
	else if (options->accuracy == -1)
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
			if (nb <= (nb - options->accuracy > 0 ? options->accuracy : 0))
			{
				nb = nb == 0 ? 0 : tmp;
				break ;
			}
			tmp = nb;
			nb -= size_wchar(cast_ap[i]);
		}
	}
	while (nb-- > 0)
		append_to_buff(options->zero && !options->minus && options->accuracy < 0 ? '0' : ' ', 0, options);
}

// void		addwidth_wstring(int nb, wchar_t *cast_ap, t_info *options)
// {
// 	int	len;
// 	int	size;
// 	int	tmp;
// 	int	i;

// 	i = 0;
// 	size = 0;
// 	len = nb;
// 	tmp = 0;
// 	while (cast_ap[size] != '\0')
// 		size++;
// 	if (options->accuracy > len && size)
// 		len = 0;
// 	else if (options->accuracy == -1 && len > size)
// 		len -= size;
// 	else if (options->accuracy > 0)
// 	{
// 		while (cast_ap[i] != '\0')
// 		{
// 			//printf("width = %d\nlen = %d\ntmp = %d\nsize = %d\naccu = %d\ni = %d ---> %lc\n===============\n", nb, len, tmp, size, options->accuracy, i, cast_ap[i]);
// 			if (len <= (nb - options->accuracy > 0 ? options->accuracy : 0))
// 			{
// 				len = len == 0 ? 0 : tmp;
// 				break ;
// 			}
// 			tmp = len;
// 			if (cast_ap[i] <= 0x7F && len > nb - options->accuracy > 0 ? options->accuracy : 0)
// 				len -= 1;
// 			else if (cast_ap[i] <= 0x7FF && len > nb - options->accuracy > 0 ? options->accuracy : 0)
// 				len -= 2;
// 			else if (cast_ap[i] <= 0xFFFF && len > nb - options->accuracy > 0 ? options->accuracy : 0)
// 				len -= 3;
// 			else if (cast_ap[i] <= 0x10FFFF && len > nb - options->accuracy > 0 ? options->accuracy : 0)
// 				len -= 4;
// 			i++;
// 		}
// 	}
// 	else if (options->accuracy == -1 && size > 0)
// 		len = 0;
// 	else if (options->accuracy < len && size > 0)
// 		len -= options->accuracy - 1;
// 	//printf("======END======\nwidth = %d\nlen = %d\ntmp = %d\nsize = %d\naccu = %d\ni = %d\n===============\n", nb ,len, tmp, size, options->accuracy, i);
// 	while (len > 0)
// 	{
// 		append_to_buff(options->zero && !options->minus && options->accuracy < 0 ? '0' : ' ', 0, options);
// 		len--;
// 	}
// }

int			size_wchar(wchar_t c)
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