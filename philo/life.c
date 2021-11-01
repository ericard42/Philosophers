/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   life.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ericard <ericard@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/26 16:11:47 by ericard@stu       #+#    #+#             */
/*   Updated: 2021/10/11 18:34:03 by ericard          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philosophers.h"

static void	*routine_eat(t_philo *philo)
{
	philo->last_time_eat = g_time();
	print_eat(philo->position, philo->frame);
	p_wait(philo->frame->time_to_eat);
	drop_fork(philo);
	return (NULL);
}

static void	routine_boucle(t_philo *philo, int i)
{
	while (42)
	{
		if (i == 1 && philo->frame->num_philos >= 2
			&& (philo->position % 2) != 0)
			p_wait(philo->frame->time_to_eat / 2);
		take_fork(philo);
		if (philo->frame->philo_die == 1)
			return ;
		routine_eat(philo);
		if (philo->frame->philo_die == 1)
			return ;
		if (philo->frame->num_eat != -1 && i == philo->frame->num_eat)
		{
			philo->last_eat = 1;
			return ;
		}
		print_sleep(philo->position, philo->frame);
		p_wait(philo->frame->time_to_sleep);
		if (philo->frame->philo_die == 1)
			return ;
		print_think(philo->position, philo->frame);
		if (philo->frame->philo_die == 1)
			return ;
		i++;
	}
}

void	*routine(void *p_data)
{
	t_philo		*philo;
	int			i;

	i = 1;
	philo = (t_philo *)p_data;
	pthread_create(&philo->dead, NULL, &time_to_die, philo);
	routine_boucle(philo, i);
	pthread_join(philo->dead, NULL);
	return (NULL);
}
