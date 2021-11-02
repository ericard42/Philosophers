/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philosophers.h                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ericard <ericard@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/02 14:06:07 by ericard           #+#    #+#             */
/*   Updated: 2021/11/02 14:06:08 by ericard          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PHILOSOPHERS_H
# define PHILOSOPHERS_H

# include <unistd.h>
# include <pthread.h>
# include <stdlib.h>
# include <stdio.h>
# include <sys/time.h>

# define ARGUMENT 1
# define MALLOC 2
# define PTHREAD 3

typedef struct s_philo
{
	int				position;
	int				lfork;
	int				rfork;
	unsigned int	last_time_eat;
	int				last_eat;
	pthread_t		dead;
	pthread_t		dead2;
	struct s_frame	*frame;
}				t_philo;

typedef struct s_frame
{
	int					num_philos;
	long int			time_to_die;
	long int			time_to_eat;
	long int			time_to_sleep;
	int					num_eat;
	int					philo_die;
	unsigned int		start_time;
	pthread_t			*thread_philo;
	pthread_mutex_t		*forks;
	pthread_mutex_t		message;
	struct s_philo		*philos;
}				t_frame;	

int				ft_atoi(const char *str);
int				init(t_frame *philo, int ac, char **av);
int				ft_error(int error, t_frame *frame);
void			*routine(void *p_data);
unsigned int	g_time(void);
void			p_wait(unsigned int time);
void			take_fork(t_philo *philo);
void			drop_fork(t_philo *philo);
void			*time_to_die(void *p_data);
int				ft_close(t_frame *frame);
void			print_fork(int nb_philo, t_frame *frame);
void			print_eat(int nb_philo, t_frame *frame);
void			print_sleep(int nb_philo, t_frame *frame);
void			print_think(int nb_philo, t_frame *frame);
void			print_died(int nb_philo, t_frame *frame);
void			ft_putstr_fd(char *str, int fd);
#endif