/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bmirlico <bmirlico@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/04 16:46:06 by bmirlico          #+#    #+#             */
/*   Updated: 2023/09/20 17:57:40 by bmirlico         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PHILO_H
# define PHILO_H

# include <unistd.h>
# include <stdio.h>
# include <string.h> 
# include <stdlib.h>
# include <stdint.h>
# include <sys/time.h>
# include <pthread.h>

# define EVEN 0
# define ODD 1

# define FORK "has taken a fork"
# define EAT "is eating"
# define SLEEP "is sleeping"
# define THINK "is thinking"
# define DIED "died"

struct	s_data;

typedef struct s_philo
{
	struct s_data	*data;
	int				index;
	pthread_mutex_t	*l_fork;
	pthread_mutex_t	*r_fork;
	uint64_t		last_time_ate;
	int				nb_eats;
}	t_philo;

typedef struct s_data
{
	int				nb_philos;
	int				nb_meals;
	int				dead;
	uint64_t		death_time;
	uint64_t		eat_time;
	uint64_t		sleep_time;
	uint64_t		start_time;
	pthread_mutex_t	print;
	pthread_mutex_t	lock;
	pthread_t		*tab_threads;
	pthread_t		*monitor;
	pthread_mutex_t	*tab_forks;
	t_philo			*tab_philos;
}	t_data;

// main.c

void		philo(int ac, char **av);

// parsing.c

int			check_input(int ac, char **av);

int			check_str(char **av);

int			check_negatives(char **av);

int			check_number(const char *nptr);

int			is_negative(const char *nptr);

// thread.c

void		init_philos_and_threads(t_data *data);

void		join_threads(t_data data);

// routine.c

void		*philo_routine(void *arg);

void		*monitor_routine(void *arg);

void		print_status(t_philo *philo, char *status);

void		lock_forks(int left_first, pthread_mutex_t *l_fork,
				pthread_mutex_t *r_fork);

void		unlock_forks(int left_first, pthread_mutex_t *l_fork,
				pthread_mutex_t *r_fork);

// time.c

uint64_t	get_time(void);

void		ft_usleep(uint64_t time);

// utils.c

void		init_data(int ac, char **av, t_data *data);

void		free_data(t_data data);

void		destroy_mutex(t_data data);

int			ft_atoi(const char *nptr);

uint64_t	ft_u_atoi(const char *nptr);

// faire fonctions de clean/free des structs, etc

#endif