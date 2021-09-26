/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ericard@student.42.fr <ericard>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/07/28 17:22:53 by ericard           #+#    #+#             */
/*   Updated: 2021/09/26 16:08:46 by ericard@stu      ###   ########.fr       */
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
	if ((ret = init(&frame, ac, av)) != 0)
		return (ft_error(ret));
	int i;

	i = 0;
	while (i < frame.num_philos)
	{
		printf("%d, %d, %d\n", frame.philos[i].position, frame.philos[i].lfork, frame.philos[i].rfork);
		i++;
	}
	return (1);
}
