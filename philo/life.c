/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   life.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ericard <ericard@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/26 16:11:47 by ericard@stu       #+#    #+#             */
/*   Updated: 2021/10/05 09:50:05 by ericard          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philosophers.h"

void *routine(void *p_data)
{
	t_philo		*philo;
	int i = 1;
	
	philo = (t_philo *)p_data;
	pthread_create(&philo->frame->dead, NULL, &time_to_die, philo);
	while (42)
	{
		if (i == 1 && (philo->position % 2) != 0)
			p_wait(philo->frame->time_to_eat / 2);
		take_fork(philo);
		if (philo->frame->philo_die == 1)
		{
			drop_fork(philo);
			//pthread_join(philo->frame->dead, NULL);
			return NULL;			
		}
		philo->last_time_eat = g_time();
		print_message(philo->position, philo->frame, ACT_EAT);
		p_wait(philo->frame->time_to_eat);
		philo->last_time_eat = g_time();
		pthread_create(&philo->frame->dead, NULL, &time_to_die, philo);
		drop_fork(philo);
		if (philo->frame->philo_die == 1)
		{
			//pthread_join(philo->frame->dead, NULL);
			return NULL;			
		}
		if (philo->frame->num_eat != -1 && i == philo->frame->num_eat)
		{
			//pthread_join(philo->frame->dead, NULL);
			return NULL;			
		}
		print_message(philo->position, philo->frame, ACT_SLEEP);
		p_wait(philo->frame->time_to_sleep);
		if (philo->frame->philo_die == 1)
		{
			//pthread_join(philo->frame->dead, NULL);
			return NULL;			
		}
		print_message(philo->position, philo->frame, ACT_THINK);
		if (philo->frame->philo_die == 1)
		{
			//pthread_join(philo->frame->dead, NULL);
			return NULL;			
		}
		i++;
	}
	//pthread_join(philo->frame->dead, NULL);
	return NULL;
}