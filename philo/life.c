/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   life.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ericard <ericard@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/26 16:11:47 by ericard@stu       #+#    #+#             */
/*   Updated: 2021/09/28 16:23:33 by ericard          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philosophers.h"

void *routine(void *p_data)
{
	t_philo		*philo;
	int i = 0;

	philo = (t_philo *)p_data;
	while (i < 5)
	{
		print_message(philo->position, philo->frame, ACT_FORK);
		print_message(philo->position, philo->frame, ACT_FORK);
		print_message(philo->position, philo->frame, ACT_EAT);
		p_wait(philo->frame->time_to_eat);
		print_message(philo->position, philo->frame, ACT_SLEEP);
		p_wait(philo->frame->time_to_sleep);
		print_message(philo->position, philo->frame, ACT_THINK);
		i++;
	}
	return NULL;
}