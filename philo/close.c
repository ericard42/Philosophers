/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   close.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ericard <ericard@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/30 19:04:44 by ericard           #+#    #+#             */
/*   Updated: 2021/10/05 10:01:52 by ericard          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philosophers.h"

int		ft_close(t_frame *frame)
{
	int	i;

	i = 0;
	while (i < frame->num_philos)
	{
		pthread_mutex_destroy(&frame->forks[i]);
		i++;
	}
	if (frame->forks)
		free(frame->forks);
	if (frame->thread_philo)
		free(frame->thread_philo);
	if (frame->philos)
		free(frame->philos);
	if (frame)
		free(frame);
	return (0);
}