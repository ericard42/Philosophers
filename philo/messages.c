#include "philosophers.h"

void	print_fork(int nb_philo, t_frame *frame)
{
	unsigned int	time_now;

	pthread_mutex_lock(&frame->message);
	if (frame->philo_die == 1)
	{
		pthread_mutex_unlock(&frame->message);
		return ;
	}
	//time_now = g_time() - frame->philos[nb_philo - 1].last_time_eat;
	time_now = g_time() - frame->start_time;
	printf("%d\t%d has taken a fork\n", time_now, nb_philo);
	pthread_mutex_unlock(&frame->message);
}

void	print_eat(int nb_philo, t_frame *frame)
{
	unsigned int	time_now;

	pthread_mutex_lock(&frame->message);
	if (frame->philo_die == 1)
	{
		pthread_mutex_unlock(&frame->message);
		return ;
	}
	//time_now = g_time() - frame->philos[nb_philo - 1].last_time_eat;
	time_now = g_time() - frame->start_time;
	printf("%d\t%d is eating\n", time_now, nb_philo);
	pthread_mutex_unlock(&frame->message);
}

void	print_sleep(int nb_philo, t_frame *frame)
{
	unsigned int	time_now;

	pthread_mutex_lock(&frame->message);
	if (frame->philo_die == 1)
	{
		pthread_mutex_unlock(&frame->message);
		return ;
	}
	//time_now = g_time() - frame->philos[nb_philo - 1].last_time_eat;
	time_now = g_time() - frame->start_time;
	printf("%d\t%d is sleeping\n", time_now, nb_philo);
	pthread_mutex_unlock(&frame->message);
}

void	print_think(int nb_philo, t_frame *frame)
{
	unsigned int	time_now;

	pthread_mutex_lock(&frame->message);
	if (frame->philo_die == 1)
	{
		pthread_mutex_unlock(&frame->message);
		return ;
	}
	//time_now = g_time() - frame->philos[nb_philo - 1].last_time_eat;
	time_now = g_time() - frame->start_time;
	printf("%d\t%d is thinking\n", time_now, nb_philo);
	pthread_mutex_unlock(&frame->message);
}

void	print_died(int nb_philo, t_frame *frame)
{
	unsigned int	time_now;

	frame->philo_die = 1;
	pthread_mutex_lock(&frame->message);
	//time_now = g_time() - frame->philos[nb_philo - 1].last_time_eat;
	time_now = g_time() - frame->start_time;
	printf("%d\t%d died\n", time_now, nb_philo);
	pthread_mutex_unlock(&frame->message);
}
