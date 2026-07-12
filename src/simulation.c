#include "../philo.h"

static void	set_initial_deadlines(t_data *data)
{
	t_philo *philo;

	data->start_time = get_time();
	philo = data->philos;
	while (philo)
	{
		philo->time_to_die = data->start_time + data->death_time;
		philo = philo->next;
	}
}

int	start_simulation(t_data *data)
{
	t_philo *philo;
	pthread_t monitor;
	int	i;

	set_initial_deadlines(data);
	philo = data->philos;
	i = 0;
	while (philo)
	{
		if (pthread_create(&philo->t1, NULL, philo_routine, philo) != 0)
			return (0);
		data->tid[i] = philo->t1;
		philo = philo->next;
		i++;
	}
	if (pthread_create(&monitor, NULL, monitor_routine, data) != 0)
		return (0);
	pthread_join(monitor, NULL);
	philo = data->philos;
	while (philo)
	{
		pthread_join(philo->t1, NULL);
		philo= philo->next;
	}
	return (1);
}
