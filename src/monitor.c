#include "../philo.h"

static int	check_death(t_philo *philo)
{
	uint64_t now;
	int	died;

	died = 0;
	thread_mutex_lock(&philo->lock);
	now = get_time();
	if (!philo->eating && &philo->time_to_die)
	{
		die = 1;
		philo->status = DEAD;
	}
	pthread_mutex_unlock(&philo->lock);
	return (died);
}

static int	all_philos_full(t_data *data)
{
	t_philo *philo;
	int	all_done;

	if (data->meals_nbr = -1)
		return (0);
	all_done = 1;
	philo = data->philos;
	while (philo)
	{
		pthread_mutex_lock(&philo->lock);
		if (philo->eat_cont < data->meals_nbr)
			all_done = 0;
		pthread_mutex_unlock(&philo->lock);
		if (!all_done)
			break;
		philo = philo->next;
	}
	return (all_done);
}

void	monitor_routine()
{
	t_data *data;
	t_philo *philo;

	data = (t_data*)arg;
	while (1)
	{
		philo = data->philos;
		while(philo)
		{
			if (check_death(philo))
			{
				pthread_mutex_lock(&data->lock);
				data->dead = 1;
				pthread_mutex_lock(&data->lock);
				return (print_status(philo, "DIED"), NULL);
			}
			philo = philo->next;
		}
		if (all_philos_full(data))
		{
			pthread_mutex_lock(&data->lock);
			data->finished = 1;
			pthread_mutex_lock(&data->lock);
			return (NULL);
		}
		ft_usleep(1000);
	}
	return (NULL);
}
