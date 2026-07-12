#include "rutine.h"

void	pick_forks(t_philo *philo)
{
	if (philo->id % 2 == 0)
	{
		pthread_mutex_lock(philo->r_fork);
		print_status(philo, "has taken a fork");
		pthread_mutex_lock(philo->l_fork);
		print_status(philo, "has taken a fork");
	}
	else
	{
		pthread_mutex_lock(philo->l_fork);
		print_status(philo, "has taken a fork");
		pthread_mutex_lock(philo->r_fork);
		print_status(philo, "has taken a fork");
	}
}

void	drop_forks(t_philo *philo)
{
	pthread_mutex_unlock(philo->l_fork);
	pthread_mutex_unlock(philo->r_fork);
}
