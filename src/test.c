/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   test.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nivergne <nivergne@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/01/08 22:08:14 by nivergne          #+#    #+#             */
/*   Updated: 2019/02/02 08:59:01 by nivergne         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

//#include "ft_printf.h"
#include "../include/ft_printf.h"


void	ft_put_binary1(unsigned char byte)
{
	if (byte >= 2)
		ft_put_binary1(byte / 2);
	ft_putchar('0' + byte % 2);
}

void	ft_put_binary2(unsigned long long byte)
{
	if (byte >= 2)
		ft_put_binary2(byte / 2);
	ft_putchar('0' + byte % 2);
}

void		ft_show_extracted(unsigned char __unused *char_ap, t_info *options)
{
	ft_putstr("// *********************************** \\\\\n");
	ft_putstr("|\t\tSIGN\t\t\t|\n");
	ft_putstr("|\t\t|");
	ft_putnbr(options->f.sign);
	ft_putstr("|\t\t\t|");
	ft_putstr("\n\\\\ *********************************** //\n\n\n");

	ft_putstr("// *********************************** \\\\\n");
	ft_putstr("|\t\tEXPONENT\t\t|\n");
	ft_putstr("|\t\t|");
	ft_putunll(options->f.exponent);
	ft_putstr("|\t\t\t|");
	ft_putstr("\n\\\\ *********************************** //\n\n\n");

	ft_putstr("// *********************************** \\\\\n");
	ft_putstr("|\t\tMANTIS\t\t\t|\n");
	ft_putstr("|\t|");
	ft_putunll(options->f.mantis);
	ft_putstr("|\t\t|");
	ft_putstr("\n\\\\ *********************************** //\n\n\n");
}

void	ft_showbin_sign(t_info *options)
{
	ft_putstr("// *********************************** \\\\\n");
	ft_putstr("|\t\tSIGN\t\t\t|\n");
	ft_putstr("|\t\t|");
	ft_put_binary2(options->f.sign);
	ft_putstr("|\t\t\t|");
	ft_putstr("\n\\\\ *********************************** //\n\n\n");
}

void	ft_showbin_expo(t_info *options)
{
	ft_putstr("// *********************************** \\\\\n");
	ft_putstr("|\t\tEXPONENT\t\t|\n");
	ft_putstr("|\t    |");
	ft_put_binary2(options->f.exponent);
	ft_putstr("|\t\t|");
	ft_putstr("\n\\\\ *********************************** //\n\n\n");
}

void	ft_showbin_mant(t_info *options)
{
	ft_putstr("mantis =\t");
	ft_put_binary2(options->f.mantis);
	ft_putstr("\n");
}

void	ft_showbin_addfloat(unsigned char *char_ap)
{
	ft_putstr("binary =\t");
	for (size_t i = 0; i < 10; i++)
	{
		int mag = 1;
		unsigned char bkp = char_ap[i];
		while (bkp /= 2)
			mag++;
		write(1, "00000000", 8 - mag);
		ft_put_binary1(char_ap[i]);
		if (i != 9)
			ft_putchar(' ');
	}
	ft_putchar('\n');
}

void	ft_put_info(t_info *info)
{
	ft_putstr("// *********************************** \\\\\n");
	ft_putstr("|\t\tFLAGS\t\t\t|\n");

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
	ft_putstr("\n\\\\ *********************************** //\n\n\n");

	ft_putstr("// *********************************** \\\\\n");
	ft_putstr("|\t\tWIDTH\t\t\t|\n");

	ft_putstr("|\t      width: ");
	ft_putnbr((info->width));
	ft_putstr("\t\t\t|");

	ft_putstr("\n\\\\ *********************************** //\n\n\n");

	ft_putstr("// *********************************** \\\\\n");
	ft_putstr("|\t\tACCURACY\t\t|\n");

	ft_putstr("|\t       accuracy: ");
	ft_putnbr((info->accuracy));
	ft_putstr("\t\t|");

	ft_putstr("\n\\\\ *********************************** //\n\n\n");

	ft_putstr("// *********************************** \\\\\n");
	ft_putstr("|\t\tTYPE\t\t\t|\n");

	ft_putstr("|\t       type: ");
	ft_putnbr((info->type));
	ft_putstr("\t\t\t|");

	ft_putstr("\n\\\\ *********************************** //\n\n\n");

	ft_putstr("// *********************************** \\\\\n");
	ft_putstr("|\t     CONVERSION\t\t\t|\n");

	ft_putstr("|\t    conversion: ");
	ft_putnbr((info->conversion));
	ft_putstr("\t\t|");

	ft_putstr("\n\\\\ *********************************** //\n");
	ft_putstr("\n\n\n\n\n\n");

}

/*

	ft_putstr("sign =\t\t");
	ft_putnbr(options->f.sign);
	ft_putstr("\n");
	ft_putstr("exponent =\t");
	ft_putunll(options->f.exponent);
	ft_putstr("\n");
	ft_putstr("mantis =\t");
	ft_putunll(options->f.mantis);
	ft_putstr("\n");

	printf("sign =\t\t%d\n", options->f.sign);
	printf("exponent =\t%llu\n", options->f.exponent);
	printf("mantis =\t%llu\n", options->f.mantis);

int	get_size(int n, int base)
{
	int	size;

	size = 0;
    if (n < 0)
	{
		n = -n;
		size++;
	}
	if (n == 0)
		return (1);
	while (n)
	{
		n = n / base;
		size++;
	}
	return (size);
}

char	*ft_itoa_core(unsigned int nb, unsigned int base, int sign, int size)
{
	char	*result;

	if (!(result = (char *)malloc(sizeof(char) * size + 1)))
		return (NULL);
	result[size] = '\0';
	size--;
	if (sign == -1)
	{
		result[0] = '-';
		sign = 1;
	}
	while (nb >= base)
	{
		result[size] = nb % base + '0';
		nb = nb / base;
		size--;
	}
	result[size] = nb % base + '0';
	return (result);
}

char		*ft_itoa_base(int n, int base)
{
	unsigned int	basee;
	unsigned int	nb;
	int				sign;
	int				size;

	size = get_size(n, base);
    basee = (unsigned int)base;
    sign = (n >= 0) ? 0 : -1;
    nb = (n >= 0) ? (unsigned int)n : (unsigned int)-n;
    return (ft_itoa_core(nb, basee, sign, size));
}
*/
