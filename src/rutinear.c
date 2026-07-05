#include "../philo.h"

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

void	eat(t_philo *philo)
{
	pick_forks(philo);
	pthread_mutex_lock(&philo->lock);
	philo_eating = 1;
	philo->time_to_die = get_time() + philo->data->death_time;
	philo->eat_cont++;
	philo->status = EATING;
	pthread_mutex_unlock(&philo->lock);
	print_status(philo, "is eating ..");
	ft_usleep(philo->data->eat_time);
	pthread_mutex_lock(philo->lock);
	philo->eating = 0;
	pthread_mutex_unlock(philo->lock);
	drop_forks(philo);
}

void	sleepp(t_philo *philo)
{
	pthread_mutex_lock(&philo->lock);
	philo->status = SLEEPING;
	pthread_mutex_unlock(&philo->lock);
	print_status(philo, "is sleeping..");
	ft_usleep(philo->data->sleep_time);
}

void	think(t_philo *philo)
{
	pthread_mutex_lock(&philo->lock);
	philo->status = THINKING;
	pthread_mutex_unlock(&philo->lock);
	print_status(philo, "thinking ..");
}

void	*philo_routine(void *arg)
{
	t_philo *philo;

	philo = (t_philo *)arg;
	if (philo->id % 2 == 0)
		ft_usleep(philo->data->eat_time /2);
	while (1)
	{
		pthread_mutex_lock(&philo->data->lock);
		if (philo->data->dead) || philo->data->finished)
		{
			pthread_mutex_unlock(&philo);
			break;
		}
		pthread_mutex_unlock(&philo->data->lock);
		eat(philo);
		sleepp(philo);
		think(philo);
	}
	return (NULL);
}
