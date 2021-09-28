/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philosophers.h                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ericard <ericard@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/07/28 17:23:00 by ericard           #+#    #+#             */
/*   Updated: 2021/09/28 16:19:11 by ericard          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PHILOSOPHERS_H
# define PHILOSOPHERS_H

# include <unistd.h>
# include <pthread.h>
# include <stdlib.h>
# include <stdio.h>
#include <sys/time.h>

# define ACT_FORK 1
# define ACT_EAT 2
# define ACT_SLEEP 3
# define ACT_THINK 4
# define ACT_DIED 5

# define ARGUMENT 1
# define MALLOC 2
# define PTHREAD 3

typedef struct	s_philo
{
	int				position;
	int				lfork;
	int				rfork;
	unsigned int	last_time_eat;
	struct s_frame	*frame;
}				t_philo;

typedef struct	s_frame
{
	int					num_philos;
	unsigned int		time_to_die;
	unsigned int		time_to_eat;
	unsigned int		time_to_sleep;
	int					num_eat;
	int					philo_die;
	unsigned int		start_time;
	pthread_t			*thread_philo;
	pthread_mutex_t		*forks;
	struct s_philo		*philos;
}				t_frame;	

int				ft_atoi(const char *str);
int				init(t_frame *philo, int ac, char **av);
void			print_message(int nb_philo, t_frame *philo, int action);
int				ft_error(int error);
void			*routine(void *p_data);
unsigned int	g_time(void);
void			p_wait(unsigned int time);

#endif