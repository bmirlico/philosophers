/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   time.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bmirlico <bmirlico@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/11 14:44:12 by bmirlico          #+#    #+#             */
/*   Updated: 2023/09/12 14:14:12 by bmirlico         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/philo.h"

uint64_t	get_time(void)
{
	struct timeval	tv;
	uint64_t		time_in_millisec;

	gettimeofday(&tv, NULL);
	time_in_millisec = tv.tv_sec * (uint64_t)1000 + tv.tv_usec / 1000;
	return (time_in_millisec);
}

void	ft_usleep(uint64_t time)
{
	uint64_t	start_time;

	start_time = get_time();
	while (get_time() - start_time < time)
		usleep(time / 10);
	return ;
}
