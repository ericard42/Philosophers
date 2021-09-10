/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ericard <ericard@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/07/28 17:22:53 by ericard           #+#    #+#             */
/*   Updated: 2021/08/31 09:44:44 by ericard          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philosophers.h"

int	main(int ac, char **av)
{
	int	ret;

	ret = 0;
	t_frame	frame;

	if (ac < 5 || ac > 6)
		return (ft_error(ARGUMENT));
<<<<<<< HEAD
	if (ret == init(&philo, ac, av) != 0)
		return (ret);
=======
	if (ret = init(&frame, ac, av) != 0)
		return (ft_error(ret));
>>>>>>> fd86620f012f97e09620b5a93ae1c768e029046a
	return (1);
}
