#include "rutine.h"

void	eat(t_philo *philo)
{
	pick_forks(philo);
	pthread_mutex_lock(&philo->lock);
	philo->eating = 1;
	philo->time_to_die = get_time() + philo->data->death_time;
	philo->eat_cont++;
	printf("\nEAT_COUNTER!!! : %d BY %d\n", philo->eat_cont, philo->id);
	philo->status = EATING;
	pthread_mutex_unlock(&philo->lock);
	print_status(philo, "is eating ..");
	ft_usleep(philo->data->eat_time);
	pthread_mutex_lock(&philo->lock);
	philo->eating = 0;
	pthread_mutex_unlock(&philo->lock);
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
		if (philo->data->dead || philo->data->finished)
		{
			pthread_mutex_unlock(&philo->data->lock);
			break;
		}
		pthread_mutex_unlock(&philo->data->lock);
		eat(philo);
		pthread_mutex_lock(&philo->lock);
		if (philo->data->meals_nbr != -1 && philo->eat_cont >= philo->data->meals_nbr)
		{
			pthread_mutex_unlock(&philo->lock);
			break;
		}
		pthread_mutex_unlock(&philo->lock);
		sleepp(philo);
		think(philo);
	}
	return (NULL);
}
