/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   thread.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bmirlico <bmirlico@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/11 17:42:39 by bmirlico          #+#    #+#             */
/*   Updated: 2023/09/22 16:40:33 by bmirlico         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/philo.h"

void	init_philos_and_threads(t_data *data)
{
	int	i;

	i = 0;
	pthread_mutex_init(&(data->print), NULL);
	pthread_mutex_init(&(data->lock), NULL);
	while (i < data->nb_philos)
	{
		pthread_mutex_init(&(data->tab_forks[i]), NULL);
		i++;
	}
	i = 0;
	while (i < data->nb_philos)
	{
		data->tab_philos[i].index = i + 1;
		data->tab_philos[i].l_fork = &(data->tab_forks[i]);
		data->tab_philos[i].r_fork = &(data->tab_forks[(i + 1)
				% data->nb_philos]);
		data->tab_philos[i].data = data;
		pthread_create(&(data->tab_threads[i]), NULL, philo_routine,
			&(data->tab_philos[i]));
		// pthread_create(&(data->monitor), NULL, monitor_routine,
		// 	&(data->tab_philos));
		i++;
	}
}

void	join_threads(t_data data)
{
	int	i;

	i = 0;
	while (i < data.nb_philos)
	{
		pthread_join(data.tab_threads[i], NULL);
		// pthread_join(data.tab_monitors[i], NULL);
		i++;
	}
}
