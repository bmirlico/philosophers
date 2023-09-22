/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   routine.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bmirlico <bmirlico@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/11 17:06:38 by bmirlico          #+#    #+#             */
/*   Updated: 2023/09/22 16:49:51 by bmirlico         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/philo.h"

// check pb si les threads se lancent simultanement

void	*philo_routine(void *arg)
{
	t_philo	*philo;
	int		philo_num;

	philo = (t_philo *)arg;
	philo_num = philo->index % 2;
	if ((philo_num == EVEN && !philo->nb_eats) || (philo->data->nb_philos % 2 == ODD
			&& philo->index == philo->data->nb_philos))
	{
		print_status(philo, THINK);
		ft_usleep(philo->data->eat_time * 0.2);
	}
	while (1)
	{
		// if ((philo->nb_eats && philo->nb_eats == philo->data->nb_meals)
		// 	|| philo->data->dead == 1)
		// 	break ;
		if (philo_num == ODD)
		{
			pthread_mutex_lock(philo->l_fork);
			print_status(philo, FORK);
			pthread_mutex_lock(philo->r_fork);
			print_status(philo, FORK);
		}
		else if (philo_num == EVEN)
		{
			pthread_mutex_lock(philo->r_fork);
			print_status(philo, FORK);
			pthread_mutex_lock(philo->l_fork);
			print_status(philo, FORK);
		}
		// pthread_mutex_lock(&(philo->data->lock));
		// philo->nb_eats++;
		// pthread_mutex_unlock(&(philo->data->lock));
		print_status(philo, EAT);
		ft_usleep(philo->data->eat_time);
		if (philo_num == ODD)
		{
			pthread_mutex_unlock(philo->l_fork);
			pthread_mutex_unlock(philo->r_fork);
		}
		else if (philo_num == EVEN)
		{
			pthread_mutex_unlock(philo->r_fork);
			pthread_mutex_unlock(philo->l_fork);
		}
		print_status(philo, SLEEP);
		ft_usleep(philo->data->sleep_time);
		print_status(philo, THINK);
		break ;
	}
	return (NULL);
}

void	print_status(t_philo *philo, char *status)
{
	uint64_t	start_time;

	start_time = philo->data->start_time;
	pthread_mutex_lock(&(philo->data->print));
	printf("%lu %d %s\n", get_time() - start_time, philo->index, status);
	pthread_mutex_unlock(&(philo->data->print));
}

void	*monitor_routine(void *arg)
{
	t_philo		*philo;
	uint64_t	check_death;

	philo = (t_philo *)arg;
	while (1)
	{
		check_death = get_time() - philo->last_time_ate;
		if (check_death > philo->data->death_time)
		{
			pthread_mutex_lock(&(philo->data->print));
			printf("%lu %d died\n", check_death, philo->index);
			pthread_mutex_unlock(&(philo->data->print));
			philo->data->dead = 1;
			break ;
		}
	}
	return (NULL);
}

void	lock_forks(int left_first, pthread_mutex_t *l_fork,
	pthread_mutex_t *r_fork)
{
	if (left_first == 1)
	{
		pthread_mutex_lock(l_fork);
		pthread_mutex_lock(r_fork);
	}
	else
	{
		pthread_mutex_lock(r_fork);
		pthread_mutex_lock(l_fork);
	}
}


void	unlock_forks(int left_first, pthread_mutex_t *l_fork,
	pthread_mutex_t *r_fork)
{
	if (left_first == 1)
	{
		pthread_mutex_unlock(l_fork);
		pthread_mutex_unlock(r_fork);
	}
	else
	{
		pthread_mutex_unlock(r_fork);
		pthread_mutex_unlock(l_fork);
	}
}

