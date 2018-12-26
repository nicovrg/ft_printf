/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nivergne <nivergne@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/12/23 16:44:36 by nivergne          #+#    #+#             */
/*   Updated: 2018/12/26 01:56:35 by nivergne         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/ft_printf.h"

int		main(int ac, char **av)
{
	int		test_int;
	char	test_char;
	char	*test_string;

	test_int = 42;
	test_char = 'c';
	test_string = "here for the long run";

	ft_printf("Testons donc cette fonction, %d\n%c\n%s\n", test_int, test_char, test_string);
	return (0);
}
