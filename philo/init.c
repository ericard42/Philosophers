/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ericard <ericard@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/08/05 10:44:08 by ericard           #+#    #+#             */
/*   Updated: 2021/11/02 13:56:56 by ericard          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philosophers.h"

static int	init_philo(t_frame *frame)
{
	int	i;

	i = 0;
	while (i < frame->num_philos)
	{
		frame->philos[i].frame = frame;
		frame->philos[i].last_time_eat = frame->start_time;
		frame->philos[i].position = i + 1;
		frame->philos[i].lfork = i;
		frame->philos[i].last_eat = 0;
		if (i + 1 == frame->num_philos)
			frame->philos[i].rfork = 0;
		else
			frame->philos[i].rfork = i + 1;
		i++;
	}
	return (0);
}

static int	init_args(t_frame *frame, int ac, char **av)
{
	frame->start_time = g_time();
	frame->num_philos = ft_atoi(av[1]);
	frame->time_to_die = ft_atoi(av[2]);
	frame->time_to_eat = ft_atoi(av[3]);
	frame->time_to_sleep = ft_atoi(av[4]);
	if (frame->num_philos <= 0 || frame->time_to_die <= 0
		|| frame->time_to_eat <= 0 || frame->time_to_sleep <= 0)
		return (ARGUMENT);
	if (ac == 6)
	{
		frame->num_eat = ft_atoi(av[5]);
		if (frame->num_eat <= 0)
			return (ARGUMENT);
	}
	else
		frame->num_eat = -1;
	return (0);
}

int	init(t_frame *frame, int ac, char **av)
{
	int	i;

	if (init_args(frame, ac, av) == ARGUMENT)
		return (ARGUMENT);
	frame->philo_die = 0;
	frame->thread_philo = malloc(sizeof(*(frame->thread_philo))
			* frame->num_philos);
	if (!frame->thread_philo)
		return (MALLOC);
	frame->forks = malloc(sizeof(*(frame->forks)) * frame->num_philos);
	if (!frame->forks)
		return (MALLOC);
	i = 0;
	pthread_mutex_init(&frame->message, NULL);
	while (i < frame->num_philos)
	{
		pthread_mutex_init(&frame->forks[i], NULL);
		i++;
	}
	frame->philos = malloc(sizeof(*(frame->philos)) * frame->num_philos);
	if (!frame->philos)
		return (MALLOC);
	init_philo(frame);
	return (0);
}
