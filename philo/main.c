/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ericard <ericard@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/07/28 17:22:53 by ericard           #+#    #+#             */
/*   Updated: 2021/08/05 14:29:10 by ericard          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philosophers.h"

int		main(int ac, char **av)
{
	int	ret;

	ret = 0;
	t_philo	philo;

	if (ac < 5 || ac > 6)
		return (ft_error(ARGUMENT));
	if (ret = init(&philo, ac, av) != 0)
		return (ret);
	return (1);
}