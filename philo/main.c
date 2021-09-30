/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ericard <ericard@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/07/28 17:22:53 by ericard           #+#    #+#             */
/*   Updated: 2021/09/30 19:13:27 by ericard          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philosophers.h"

int	main(int ac, char **av)
{
	int		ret;
	void	*philo;
	int 	i;
	t_frame	*frame;

	frame = malloc(sizeof(t_frame));
	if (!frame)
		return (ft_error(MALLOC, frame));
	ret = 0;
	if (ac < 5 || ac > 6)
		return (ft_error(ARGUMENT, frame));
	if ((ret = init(frame, ac, av)) != 0)
		return (ft_error(ret, frame));
	i = 0;
	while (i < frame->num_philos)
	{
		philo = (void *)&frame->philos[i];
		ret = pthread_create(&frame->thread_philo[i], NULL, &routine, philo);
		if (ret)
			return (ft_error(PTHREAD, frame));
		i++;
	}
	i = 0;
	while (i < frame->num_philos)
	{
		pthread_join(frame->thread_philo[i], NULL);
		i++;
	}
	ft_close(frame);
	return (1);
}
