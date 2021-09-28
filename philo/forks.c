/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   forks.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ericard <ericard@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/28 13:53:14 by ericard           #+#    #+#             */
/*   Updated: 2021/09/28 17:47:23 by ericard          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philosophers.h"

void	take_fork(t_philo *philo)
{
	pthread_mutex_lock(&philo->frame->forks[philo->lfork]);
	print_message(philo->position, philo->frame, ACT_FORK);
	pthread_mutex_lock(&philo->frame->forks[philo->rfork]);
	print_message(philo->position, philo->frame, ACT_FORK);
}

void	drop_fork(t_philo *philo)
{
	pthread_mutex_unlock(&philo->frame->forks[philo->lfork]);
	pthread_mutex_unlock(&philo->frame->forks[philo->rfork]);
}