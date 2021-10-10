/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   time.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ericard@student.42.fr <ericard>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/28 16:11:59 by ericard           #+#    #+#             */
/*   Updated: 2021/10/10 12:40:01 by ericard@stu      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philosophers.h"

void	*time_to_die(void *p_data)
{
	t_philo			*philo;
	unsigned int	end_time;
	unsigned int	last_time_eat_b;

	philo = (t_philo *)p_data;
	last_time_eat_b = philo->last_time_eat;
	end_time = last_time_eat_b + philo->frame->time_to_die;
	while (g_time() < end_time)
	{
		if (philo->frame->philo_die == 1 || last_time_eat_b != philo->last_time_eat)
			return NULL ;
		usleep(1000);
	}
	if (last_time_eat_b == philo->last_time_eat && philo->frame->philo_die == 0)
	{
		philo->frame->philo_die = 1;
		print_died(philo->position, philo->frame);
	}
	return NULL;
}

unsigned int	g_time(void)
{
	struct timeval time;
	unsigned int	mil_seconds;

	mil_seconds = 0;
	gettimeofday(&time, NULL);
	mil_seconds = time.tv_usec * 0.001 + time.tv_sec * 1000;
	return (mil_seconds);
}	

void	p_wait(unsigned int time)
{
	unsigned int	end_time;
	
	end_time = g_time() + time;
	while (g_time() < end_time)
		usleep(1000);
}