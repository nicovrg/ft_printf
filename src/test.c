/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   test.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nivergne <nivergne@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/01/08 22:08:14 by nivergne          #+#    #+#             */
/*   Updated: 2019/01/09 00:59:25 by nivergne         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/ft_printf.h"

void	ft_put_info(t_info *info)
{
	ft_putstr("// *********************************** \\\\ \n");
	ft_putstr("|\t\tFLAGS\t\t\t| \n");

	ft_putstr("|\t      + :     ");
	ft_putnbr((info->plus) ? 1 : 0);
	ft_putstr("\t\t\t|");

	ft_putstr("\n|\t      - :     ");
	ft_putnbr((info->minus) ? 1 : 0);
	ft_putstr("\t\t\t|");

	ft_putstr("\n|\t      0 :     ");
	ft_putnbr((info->zero) ? 1 : 0);
	ft_putstr("\t\t\t|");

	ft_putstr("\n|\t      # :     ");
	ft_putnbr((info->hashtag) ? 1 : 0);
	ft_putstr("\t\t\t|");

	ft_putstr("\n|\t      space : ");
	ft_putnbr((info->space) ? 1 : 0);
	ft_putstr("\t\t\t|");
	ft_putstr("\n\\\\ *********************************** // \n\n\n");

	ft_putstr("// *********************************** \\\\ \n");
	ft_putstr("|\t\tWIDTH\t\t\t|\n");

	ft_putstr("|\t      width: ");
	ft_putnbr((info->width));
	ft_putstr("\t\t\t|");

	ft_putstr("\n\\\\ *********************************** // \n\n\n");

	ft_putstr("// *********************************** \\\\ \n");
	ft_putstr("|\t\tACCURACY\t\t|\n");

	ft_putstr("|\t       accuracy: ");
	ft_putnbr((info->accuracy));
	ft_putstr("\t\t|");

	ft_putstr("\n\\\\ *********************************** // \n\n\n");

	ft_putstr("// *********************************** \\\\ \n");
	ft_putstr("|\t\tTYPE\t\t\t|\n");

	ft_putstr("|\t       type: ");
	ft_putnbr((info->type));
	ft_putstr("\t\t\t|");

	ft_putstr("\n\\\\ *********************************** // \n\n\n");

	ft_putstr("// *********************************** \\\\ \n");
	ft_putstr("|\t     CONVERSION\t\t\t|\n");

	ft_putstr("|\t    conversion: ");
	ft_putnbr((info->conversion));
	ft_putstr("\t\t|");

	ft_putstr("\n\\\\ *********************************** // \n");
}
