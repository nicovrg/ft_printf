/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_p.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jquivogn <jquivogn@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/01/17 23:29:11 by nivergne          #+#    #+#             */
/*   Updated: 2019/02/08 16:18:40 by jquivogn         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	ft_addaddr(va_list ap, t_info *o)
{
	void *cast;
	char *tmp;

	cast = conv(va_arg(ap, unsigned long long), 16, 1);
	tmp = ft_strjoin("0x", cast);
	free(cast);
	cast = tmp;
	if (o->hashtag == 1)
		o->hashtag = 0;
	ft_addhexmin(cast, o);
}
