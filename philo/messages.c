/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   messages.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ericard <ericard@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/02 14:06:16 by ericard           #+#    #+#             */
/*   Updated: 2021/11/02 14:06:16 by ericard          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philosophers.h"

void	print_fork(int nb_philo, t_frame *frame)
{
	unsigned int	time_now;

	pthread_mutex_lock(&frame->message);
	if (frame->philo_die == 1)
	{
		pthread_mutex_unlock(&frame->message);
		return ;
	}
	time_now = g_time() - frame->start_time;
	printf("%d\t%d has taken a fork\n", time_now, nb_philo);
	pthread_mutex_unlock(&frame->message);
}

void	print_eat(int nb_philo, t_frame *frame)
{
	unsigned int	time_now;

	pthread_mutex_lock(&frame->message);
	if (frame->philo_die == 1)
	{
		pthread_mutex_unlock(&frame->message);
		return ;
	}
	time_now = g_time() - frame->start_time;
	printf("%d\t%d is eating\n", time_now, nb_philo);
	pthread_mutex_unlock(&frame->message);
}

void	print_sleep(int nb_philo, t_frame *frame)
{
	unsigned int	time_now;

	pthread_mutex_lock(&frame->message);
	if (frame->philo_die == 1)
	{
		pthread_mutex_unlock(&frame->message);
		return ;
	}
	time_now = g_time() - frame->start_time;
	printf("%d\t%d is sleeping\n", time_now, nb_philo);
	pthread_mutex_unlock(&frame->message);
}

void	print_think(int nb_philo, t_frame *frame)
{
	unsigned int	time_now;

	pthread_mutex_lock(&frame->message);
	if (frame->philo_die == 1)
	{
		pthread_mutex_unlock(&frame->message);
		return ;
	}
	time_now = g_time() - frame->start_time;
	printf("%d\t%d is thinking\n", time_now, nb_philo);
	pthread_mutex_unlock(&frame->message);
}

void	print_died(int nb_philo, t_frame *frame)
{
	unsigned int	time_now;

	if (frame->philo_die == 1)
		return ;
	frame->philo_die = 1;
	pthread_mutex_lock(&frame->message);
	time_now = g_time() - frame->start_time;
	printf("%d\t%d died\n", time_now, nb_philo);
	pthread_mutex_unlock(&frame->message);
}
