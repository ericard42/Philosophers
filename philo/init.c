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

int	init(t_philo *philo, int ac, char **av)
{
	philo->num_philos = ft_atoi(av[1]);
	philo->time_to_die = ft_atoi(av[2]);
	philo->time_to_eat = ft_atoi(av[3]);
	philo->time_to_sleep = ft_atoi(av[4]);
	if (philo->num_philos < 2 || philo->time_to_die < 0 || philo->time_to_eat < 0 || philo->time_to_sleep < 0)
		return (ARGUMENT);
	if (ac == 6)
	{
		philo->num_eat = ft_atoi(av[5]);
		if (philo->num_eat <= 0)
			return (ARGUMENT);
	}
	else
		philo->num_eat = -1;
	return (0);
}