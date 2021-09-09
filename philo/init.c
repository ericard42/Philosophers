/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ericard <ericard@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/08/05 10:44:08 by ericard           #+#    #+#             */
/*   Updated: 2021/08/05 14:27:59 by ericard          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philosophers.h"

int	init(t_frame *frame, int ac, char **av)
{
	frame->num_philos = ft_atoi(av[1]);
	frame->time_to_die = ft_atoi(av[2]);
	frame->time_to_eat = ft_atoi(av[3]);
	frame->time_to_sleep = ft_atoi(av[4]);
	if (frame->num_philos < 2 || frame->time_to_die < 0 || frame->time_to_eat < 0 || frame->time_to_sleep < 0)
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