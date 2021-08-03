/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ericard <ericard@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/07/28 17:22:53 by ericard           #+#    #+#             */
/*   Updated: 2021/08/03 14:59:12 by ericard          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philosophers.h"

int		main(int ac, char **av)
{
	t_philo	philo;

	if (ac < 5 || ac > 6)
		exit (0);
	philo.num_philos = av[1];
	philo.time_to_die = av[2];
	philo.time_to_eat = av[3];
	philo.time_to_sleep = av[4];
	if (ac == 6)
		philo.num_eat = av[5];
}