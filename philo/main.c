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
	void *philo;

	ret = 0;
	t_frame	*frame;

	frame = malloc(sizeof(t_frame));
	if (!frame)
		return (ft_error(MALLOC));
	if (ac < 5 || ac > 6)
		return (ft_error(ARGUMENT));
	if ((ret = init(frame, ac, av)) != 0)
		return (ft_error(ret));
	int i;

	i = 0;
	while (i < frame->num_philos)
	{
		philo = (void *)&frame->philos[i];
		ret = pthread_create(&frame->thread_philo[i], NULL, &routine, philo);
		if (ret)
			return (ft_error(PTHREAD));
		//pthread_detach(frame->thread_philo[i]);
		i++;
	}
	i = 0;
	while (i < frame->num_philos)
	{
		pthread_join(frame->thread_philo[i], NULL);
		i++;
	}
	return (1);
}
