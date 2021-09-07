/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philosophers.h                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ericard <ericard@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/07/28 17:23:00 by ericard           #+#    #+#             */
/*   Updated: 2021/08/05 14:28:13 by ericard          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PHILOSOPHERS_H
# define PHILOSOPHERS_H

# include <unistd.h>
# include <pthread.h>
# include <stdlib.h>
# include <stdio.h>

# define ACT_FORK 1
# define ACT_EAT 2
# define ACT_SLEEP 3
# define ACT_THINK 4
# define ACT_DIED 5

# define ARGUMENT 1

typedef struct	s_p

typedef struct	s_frame
{
	int		num_philos;
	int		time_to_die;
	int		time_to_eat;
	int		time_to_sleep;
	int		num_eat;
}				t_frame;	

int		ft_atoi(const char *str);
int		init(t_frame *philo, int ac, char **av);
void	print_message(int nb_philo, t_frame *philo, int action);
int		ft_error(int error);

#endif