/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   itoa_base.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nivergne <nivergne@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/01/07 20:00:21 by nivergne          #+#    #+#             */
/*   Updated: 2019/01/07 20:00:52 by nivergne         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

static int	get_size(int n, int base)
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

static char	*ft_itoa_core(unsigned int nb, unsigned int base, int sign, int size)
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
