/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bmirlico <bmirlico@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/04 16:48:14 by bmirlico          #+#    #+#             */
/*   Updated: 2023/09/22 16:05:20 by bmirlico         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/philo.h"

// valgrind --tool=helgrind ./philo

int	main(int ac, char **av)
{
	if (check_input(ac, av) == 0)
		philo(ac, av);
	return (0);
}

void	philo(int ac, char **av)
{
	t_data	data;

	memset(&data, 0, sizeof(t_data));
	init_data(ac, av, &data);
	init_philos_and_threads(&data);
	join_threads(data);
	destroy_mutex(data);
	free_data(data);
}
