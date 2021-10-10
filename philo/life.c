/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   life.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ericard@student.42.fr <ericard>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/26 16:11:47 by ericard@stu       #+#    #+#             */
/*   Updated: 2021/10/10 12:39:10 by ericard@stu      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philosophers.h"

void *routine(void *p_data)
{
	t_philo		*philo;
	pthread_t	dead;
	int i = 1;
	
	philo = (t_philo *)p_data;
	pthread_create(&dead, NULL, &time_to_die, philo);
	while (42)
	{
		if (i == 1 && philo->frame->num_philos > 2 && (philo->position % 2) != 0)
			p_wait(philo->frame->time_to_eat / 2);
		take_fork(philo);
		if (philo->frame->philo_die == 1)
		{
			drop_fork(philo);
			pthread_join(dead, NULL);
			return NULL;			
		}
		philo->last_time_eat = g_time();
		pthread_create(&dead, NULL, &time_to_die, philo);
		print_eat(philo->position, philo->frame);
		p_wait(philo->frame->time_to_eat);
		drop_fork(philo);
		if (philo->frame->philo_die == 1)
		{
			pthread_join(dead, NULL);
			return NULL;			
		}
		if (philo->frame->num_eat != -1 && i == philo->frame->num_eat)
		{
			pthread_join(dead, NULL);
			return NULL;			
		}
		print_sleep(philo->position, philo->frame);
		p_wait(philo->frame->time_to_sleep);
		if (philo->frame->philo_die == 1)
		{
			pthread_join(dead, NULL);
			return NULL;			
		}
		print_think(philo->position, philo->frame);
		if (philo->frame->philo_die == 1)
		{
			pthread_join(dead, NULL);
			return NULL;			
		}
		i++;
	}
	pthread_join(dead, NULL);
	return NULL;
}