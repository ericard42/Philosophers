#include "philosophers.h"

void	print_message(int nb_philo, t_frame *frame, int action)
{
	int	time;

	time = 0;
	frame->num_eat = -1;
	if (action == ACT_FORK)
		printf("%d\t%d as taken a fork\n", time, nb_philo);
	if (action == ACT_EAT)
		printf("%d\t%d is eating\n", time, nb_philo);
	if (action == ACT_SLEEP)
		printf("%d\t%d is sleeping\n", time, nb_philo);
	if (action == ACT_THINK)
		printf("%d\t%d is thinking\n", time, nb_philo);
	if (action == ACT_DIED)
		printf("%d\t%d died\n", time, nb_philo);
}