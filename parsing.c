/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nleoni <nleoni@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/16 03:18:14 by nleoni            #+#    #+#             */
/*   Updated: 2024/08/30 21:27:51 by nleoni           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

int	ft_isdigit(char c)
{
	if (c >= '0' && c <= '9')
		return (1);
	return (0);
}

int	ft_atoi(char *str)
{
	int	i;
	int	res;

	i = 0;
	res = 0;
	while ((str[i] == ' ') || (str[i] >= 9 && str[i] <= 13))
		i++;
	while (ft_isdigit(str[i]))
		res = (res * 10) + str[i++] - '0';
	return (res);
}

int	check_input(int ac, char **av)
{
	int	i;
	int	j;

	if (ac < 5 || ac > 6)
		return (1);
	i = 1;
	while (av[i])
	{
		j = 0;
		while (av[i][j])
		{
			if (!ft_isdigit(av[i][j]))
			{
				printf("Error\nInput\n");
				return (1);
			}
			j++;
		}
		i++;
	}
	if (ft_atoi(av[1]) == 0 || ft_atoi(av[1]) > 199)
		return (1);
	if (ac == 6 && ft_atoi(av[5]) == 0)
		return (1);
	return (0);
}
