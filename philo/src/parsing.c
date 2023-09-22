/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bmirlico <bmirlico@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/04 18:18:52 by bmirlico          #+#    #+#             */
/*   Updated: 2023/09/06 16:32:44 by bmirlico         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/philo.h"

int	check_input(int ac, char **av)
{
	if (ac > 6 || ac < 5 || check_str(av) || check_negatives(av))
	{
		if (ac > 6)
			printf("Too many arguments.\n");
		else if (ac < 5)
			printf("Too few arguments.\n");
		else if (check_str(av))
			printf("Numeric arguments required.\n");
		else if (check_negatives(av))
			printf("Strictly positive numbers required.\n");
		return (1);
	}
	else
		return (0);
}

int	check_str(char **av)
{
	int	i;

	i = 1;
	while (av[i])
	{
		if (check_number(av[i]))
			return (1);
		i++;
	}
	return (0);
}

int	check_negatives(char **av)
{
	int	i;

	i = 1;
	while (av[i])
	{
		if (is_negative(av[i]))
			return (1);
		i++;
	}
	return (0);
}

int	check_number(const char *nptr)
{
	int	i;

	i = 0;
	while (nptr[i] == 32 || (nptr[i] >= 9 && nptr[i] <= 13))
		i++;
	if (nptr[i] == '+' || nptr[i] == '-')
		i++;
	while (nptr[i] != '\0')
	{
		if (!(nptr[i] >= '0' && nptr[i] <= '9'))
			return (1);
		i++;
	}
	return (0);
}

int	is_negative(const char *nptr)
{
	int	i;
	int	sign;
	int	res;

	i = 0;
	sign = 1;
	res = 0;
	while (nptr[i] == 32 || (nptr[i] >= 9 && nptr[i] <= 13))
		i++;
	if (nptr[i] == '+' || nptr[i] == '-')
	{
		if (nptr[i] == '-')
			sign *= -1;
		i++;
	}
	while (nptr[i] >= '0' && nptr[i] <= '9')
	{
		res = res * 10 + nptr[i] - 48;
		i++;
	}
	if ((res * sign) <= 0)
		return (1);
	return (0);
}
