/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   forks.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ericard <ericard@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/28 13:53:14 by ericard           #+#    #+#             */
/*   Updated: 2021/10/16 10:46:02 by ericard          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philosophers.h"

void	take_fork(t_philo *philo)
{
	pthread_mutex_lock(&philo->frame->forks[philo->lfork]);
	if (philo->frame->philo_die == 1)
	{	
		pthread_mutex_unlock(&philo->frame->forks[philo->lfork]);
		return ;
	}
	print_fork(philo->position, philo->frame);
	if (philo->frame->num_philos == 1)
	{
		while (philo->frame->philo_die != 1)
			usleep(100);
		return ;
	}
	pthread_mutex_lock(&philo->frame->forks[philo->rfork]);
	if (philo->frame->philo_die == 1)
	{	
		pthread_mutex_unlock(&philo->frame->forks[philo->lfork]);
		pthread_mutex_unlock(&philo->frame->forks[philo->rfork]);
		return ;
	}
	print_fork(philo->position, philo->frame);
}

void	drop_fork(t_philo *philo)
{
	pthread_mutex_unlock(&philo->frame->forks[philo->lfork]);
	pthread_mutex_unlock(&philo->frame->forks[philo->rfork]);
}
