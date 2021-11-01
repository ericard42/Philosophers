/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ericard <ericard@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/07/28 17:22:53 by ericard           #+#    #+#             */
/*   Updated: 2021/10/05 09:56:32 by ericard          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philosophers.h"

static int	create_thread(t_frame *frame)
{
	int		i;
	void	*philo;
	int		ret;

	i = 0;
	ret = 0;
	while (i < frame->num_philos)
	{
		philo = (void *)&frame->philos[i];
		ret = pthread_create(&frame->thread_philo[i], NULL, &routine, philo);
		if (ret)
			return (PTHREAD);
		i++;
	}
	return (0);
}

static void	waiting_pthread(t_frame *frame)
{
	int	i;

	i = 0;
	while (i < frame->num_philos)
	{
		pthread_join(frame->thread_philo[i], NULL);
		i++;
	}
}

int	main(int ac, char **av)
{
	int		ret;
	t_frame	*frame;

	frame = malloc(sizeof(t_frame));
	if (!frame)
		return (ft_error(MALLOC, frame));
	ret = 0;
	if (ac < 5 || ac > 6)
	{
		printf("Error : Wrong arguments\n");
		free(frame);
		return (0);
	}
	ret = init(frame, ac, av);
	if (ret != 0)
		return (ft_error(ret, frame));
	if (create_thread(frame) != 0)
		return (ft_error(PTHREAD, frame));
	waiting_pthread(frame);
	ft_close(frame);
	return (1);
}
