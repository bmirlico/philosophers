/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bmirlico <bmirlico@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/11 17:39:04 by bmirlico          #+#    #+#             */
/*   Updated: 2023/09/20 13:37:42 by bmirlico         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/philo.h"

void	init_data(int ac, char **av, t_data *data)
{
	data->nb_philos = ft_atoi(av[1]);
	if (ac == 6)
		data->nb_meals = ft_atoi(av[ac - 1]);
	else
		data->nb_meals = 0;
	data->death_time = ft_u_atoi(av[2]);
	data->eat_time = ft_u_atoi(av[3]);
	data->sleep_time = ft_u_atoi(av[4]);
	data->start_time = get_time();
	data->tab_philos = malloc(sizeof(t_philo) * data->nb_philos);
	if (!data->tab_philos)
		return ;
	data->tab_forks = malloc(sizeof(pthread_mutex_t) * data->nb_philos);
	if (!data->tab_forks)
		return ;
	data->tab_threads = malloc(sizeof(pthread_t) * data->nb_philos);
	if (!data->tab_threads)
		return ;
}

void	free_data(t_data data)
{
	free(data.tab_forks);
	free(data.tab_philos);
	free(data.tab_threads);
}

void	destroy_mutex(t_data data)
{
	int	i;

	i = 0;
	while (i < data.nb_philos)
	{
		pthread_mutex_destroy(&(data.tab_forks[i]));
		i++;
	}
	pthread_mutex_destroy(&(data.print));
	pthread_mutex_destroy(&(data.lock));
}

int	ft_atoi(const char *nptr)
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
	return (res * sign);
}

uint64_t	ft_u_atoi(const char *nptr)
{
	int			i;
	uint64_t	sign;
	uint64_t	res;

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
	return (res * sign);
}
