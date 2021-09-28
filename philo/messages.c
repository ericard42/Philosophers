#include "philosophers.h"

void	print_message(int nb_philo, t_frame *frame, int action)
{
	unsigned int	time_now;

	time_now = g_time() - frame->start_time;
	frame->num_eat = -1;
	if (action == ACT_FORK)
		printf("%d\t%d has taken a fork\n", time_now, nb_philo);
	if (action == ACT_EAT)
		printf("%d\t%d is eating\n", time_now, nb_philo);
	if (action == ACT_SLEEP)
		printf("%d\t%d is sleeping\n", time_now, nb_philo);
	if (action == ACT_THINK)
		printf("%d\t%d is thinking\n", time_now, nb_philo);
	if (action == ACT_DIED)
		printf("%d\t%d died\n", time_now, nb_philo);
}