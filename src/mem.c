/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mem.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nivergne <nivergne@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/01/04 17:10:08 by nivergne          #+#    #+#             */
/*   Updated: 2019/02/02 02:59:51 by nivergne         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

//#include "ft_printf.h"
#include "../include/ft_printf.h"

void	ft_bzero(void *s, size_t n)
{
	ft_memset(s, 0, n);
}

void	*ft_memset(void *b, int c, size_t len)
{
	size_t			i;
	unsigned char	*tmp;

	i = 0;
	tmp = (unsigned char *)b;
	while (i < len)
	{
		tmp[i] = (unsigned char)c;
		i++;
	}
	return (b);
}

void	*ft_memalloc(size_t size)
{
	void	*p;

	p = malloc(size);
	if (!p)
		return (NULL);
	ft_bzero(p, size);
	return (p);
}

size_t		ft_strlen(const char *s)
{
	size_t	i;

	i = 0;
	while (s[i])
		i++;
	return (i);
}

void	ft_putchar(char c)
{
	write(1, &c, 1);
}

void	ft_putstr(char const *s)
{
	if (s)
		write(1, s, ft_strlen(s));
}

void	ft_putnbr(int n)
{
	unsigned int nbr;

	if (n < 0)
	{
		ft_putchar('-');
		n = -n;
	}
	nbr = (unsigned int)n;
	if (nbr >= 10)
	{
		ft_putnbr(nbr / 10);
		ft_putchar(nbr % 10 + '0');
	}
	else
		ft_putchar(nbr % 10 + '0');
}

int		ft_atoi(const char *str)
{
	size_t		i;
	int			sign;
	size_t		result;

	i = 0;
	sign = 1;
	result = 0;
	while ((str[i] >= 9 && str[i] <= 13) || str[i] == 32)
		i++;
	if (str[i] == '-')
		sign = -1;
	if (str[i] == '-' || str[i] == '+')
		i++;
	while (str[i] >= '0' && str[i] <= '9')
	{
		result = result * 10 + str[i] - '0';
		if (sign == 1 && result > INT64_MAX)
			return (-1);
		if (sign == -1 && result > (size_t)(INT64_MAX) + 1)
			return (0);
		i++;
	}
	return ((int)result * sign);
}

char	*ft_strjoin(char const *s1, char const *s2)
{
	int		i;
	int		c;
	char	*str;

	c = -1;
	if (!(s1) || !(s2))
		return (NULL);
	i = ft_strlen(s1) + ft_strlen(s2) + 1;
	if (!(str = ft_memalloc(i)))
		return (NULL);
	while (s1[++c])
		str[c] = s1[c];
	i = 0;
	while (s2[i])
	{
		str[c] = s2[i];
		c++;
		i++;
	}
	str[c] = '\0';
	return (str);
}

void	paws(unsigned char *a, unsigned char *b)
{
	char temp;

	temp = *a;
	*a = *b;
	*b = temp;
}

unsigned char	*esreverse(unsigned char *str)
{
	int		i;
	int		j;

	i = 0;
	j = 0;
	while (str[i] != '\0')
		i++;
	i--;
	while (i > j)
	{
		paws(&str[i], &str[j]);
		i--;
		j++;
	}
	return (str);
}

// void	ft_putstr_test(unsigned char *s)
// {
// 	int i;

// 	i = 0;
// 	while (s[i++])
// 		s[i] += 48;
// 	i = 0;	
// 	while (s[i++])
// 		write(1, s[i], 1);
// 	// if (s)
// 	// 	write(1, s, ft_strlen_test(s));
// }

// size_t		ft_strlen_test(unsigned char *s)
// {
// 	size_t	i;

// 	i = 0;
// 	while (s[i])
// 		i++;
// 	return (i);
// }

