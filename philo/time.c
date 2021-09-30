/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   time.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ericard <ericard@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/28 16:11:59 by ericard           #+#    #+#             */
/*   Updated: 2021/09/30 19:24:07 by ericard          ###   ########.fr       */
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
	end_time = philo->last_time_eat + philo->frame->time_to_die;
	printf("WAITING %d\n", philo->position);
	while (g_time() < end_time)
		usleep(1000);
	printf("DONE WAITING %d\n", philo->position);
	if (last_time_eat_b == philo->last_time_eat && philo->frame->philo_die == 0)
	{
		print_message(philo->position, philo->frame, ACT_DIED);
		philo->frame->philo_die = 1;
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