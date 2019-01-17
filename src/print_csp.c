/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_csp.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nivergne <nivergne@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/12/28 02:16:02 by nivergne          #+#    #+#             */
/*   Updated: 2019/01/17 02:12:32 by nivergne         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

//#include "ft_printf.h"
#include "../include/ft_printf.h"

void	ft_addchar(va_list ap, t_info *options)
{	
	char	cast_ap;

	cast_ap = va_arg(ap, int);
	if (options->width > 0)
	{
		if (options->minus == 1)
		{
			append_to_buff(cast_ap, 0);
			addwidth_char(options->width);
		}
		else
		{
			addwidth_char(options->width);
			append_to_buff(cast_ap, 0);
		}
	}
	else if (options->width == 0)
		append_to_buff(cast_ap, 0);
}

void	ft_addstr(va_list ap, t_info *options)
{	
	char	*cast_ap;

	cast_ap = va_arg(ap, char *);
	if (options->width > 0)
	{
		if (options->minus == 1)
		{
			addbuff(cast_ap, options);
			addwidth_string(options->width, cast_ap);		
		}
		else
		{
			addwidth_string(options->width, cast_ap);		
			addbuff(cast_ap, options);
		}
	}
	else if (options->width == -1)
		addbuff(cast_ap, options);		
}

void    ft_addaddr(va_list ap, t_info *options)
{
	unsigned long long	cast_ap;
	
	cast_ap = va_arg(ap, unsigned long long);
	if (options->width > 0)
	{
		if (options->minus == 1)
		{
			addbuff("0x", options);	
			addbuff(ft_itoa_base(cast_ap, 16, 32), options);
			addwidth_pointer(options->width, (char *)cast_ap);
		}
		else 
		{
			addwidth_pointer(options->width, (char *)cast_ap);
			addbuff("0x", options);	
			addbuff(ft_itoa_base(cast_ap, 16, 32), options);
		}
	}
	else if (options->width == -1)
	{
		addbuff("0x", options);	
		addbuff(ft_itoa_base(cast_ap, 16, 32), options);
	}
}

void	ft_addpercent(va_list __unused ap, t_info *options)
{
	int		i;

	if (options->minus == 1)
		append_to_buff('%', 0);
	i = options->width;
	while (i-- > 1)
		append_to_buff(options->zero == 0 ? ' ' : '0', 0);
	if (options->minus == 0)
		append_to_buff('%', 0);
}

/*
Working
void	ft_addchar(va_list ap, t_info *options)
{	
	char	cast_ap;

	cast_ap = va_arg(ap, int);
	if (options->width > 0)
	{
		if (options->minus == 1)
		{
			append_to_buff(cast_ap, 0);
			addwidth_char(options->width);
		}
		else
		{
			addwidth_char(options->width);
			append_to_buff(cast_ap, 0);
		}
	}
	else if (options->width == 0)
		append_to_buff(cast_ap, 0);
}


void	ft_addstr(va_list ap, t_info *options)
{
	(void)options;
	int		i;
	char	*cast_ap;

	i = 0;
	cast_ap = va_arg(ap, char *);
	if (ap != NULL)
	{
		while (cast_ap[i])
		{
			append_to_buff(cast_ap[i], 0);
			i++;
		}
	}
}

void    ft_addaddr(va_list ap, t_info *options)
{
	unsigned long long	cast_ap;
	
	cast_ap = va_arg(ap, unsigned long long);
	addbuff("0x", options);	
	addbuff(ft_itoa_base(cast_ap, 16, 32), options);
}

void	ft_addpercent()
{
	append_to_buff('%', 0);
}
*/