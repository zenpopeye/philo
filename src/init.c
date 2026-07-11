#include "../philo.h"

int	init_forks(t_data *data)
{
	int	i;
	data->forks = malloc(sizeof(pthread_mutex_t) * data->philos_nbr);
	if (!data->forks)
		return (0);
	i = 0;
	while (i < data->philos_nbr)
	{
		if (pthread_mutex_init(&data->forks[i], NULL) != 0)
		{
			while (--i >= 0)
				pthread_mutex_destroy(&data->forks[i]);
			free(data->forks);
			data->forks = NULL;
			return (0);
		}
		i++;
	}
	return (1);
}

int	init_mutexes(t_data *data)
{
	if (pthread_mutex_init(&data->lock, NULL) != 0)
		return (0);
	if (pthread_mutex_init(&data->write, NULL) != 0)
		return (pthread_mutex_destroy(&data->lock), 0);
	return (1);
}

int	init_data(t_data *data, int ac, char **av)
{
	data->philos_nbr = ft_atoi(av[1]);
	data->death_time = (uint64_t) ft_atoi(av[2]);
	data->eat_time = (uint64_t) ft_atoi(av[3]);
	data->sleep_time = (uint64_t) ft_atoi(av[4]);
	data->meals_nbr = -1;
	if (ac == 5)
		data->meals_nbr = ft_atoi(av[5]);
	data->dead = 0;
	data->finished = 0;
	data->philos = NULL;
	data->forks = NULL;
	data->tid = NULL;
	data->start_time = 0;

	if (!init_mutexes(data))
		return (0);
	if (!init_forks(data))
	{
		pthread_mutex_destroy(&data->lock);
		pthread_mutex_destroy(&data->write);
		return (0);
	}
	data->tid = malloc(sizeof(pthread_t) * data->philos_nbr);
	if (!data->tid)
	{
		int i;
		i = 0;
		while (i < data->philos_nbr)
			pthread_mutex_destroy(&data->forks[i++]);
		free(data->forks);
		pthread_mutex_destroy(&data->lock);
		pthread_mutex_destroy(&data->write);
		return (0);
	}
	return (1);
}

t_philo	*create_philo(int id, t_data *data)
{
	t_philo *philo;

	philo = malloc(sizeof(t_philo));
	if (!philo)
		return (NULL);
	philo->next = NULL;
	philo->data = data;
	philo->id = id;
	philo->eat_cont = 0;
	philo->status = THINKING;
	philo->eating = 0;
	philo->last_meal = 0;
	philo->time_to_die = 0;
	philo->r_fork = NULL;
	philo->l_fork = NULL;
	if (pthread_mutex_init(&philo->lock, NULL) != 0)
	{
		free(philo);
		return (NULL);
	}
	return (philo);
}

static void	append_philo(t_philo **head, t_philo *new_philo)
{
	t_philo *current;

	if (!*head)
	{
		*head = new_philo;
		return ;
	}
	current = *head;
	while (current->next)
		current = current->next;
	current->next = new_philo;
}

static int	add_philo(int id, t_data *data)
{
	t_philo *philo;

	philo = create_philo(id, data);
	if (!philo)
		return (0);
	append_philo(&data->philos, philo);
	return (1);
}

static void	assign_forks(t_philo *philo, t_data *data)
{
	philo->l_fork = &data->forks[philo->id -1];
	philo->r_fork = &data->forks[philo->id % data->philos_nbr];
}

int	init_philos(t_data *data)
{
	int	i;
	t_philo *current;

	i = 1;
	while (i <= data->philos_nbr)
	{
		if (!add_philo(i, data))
		i++;
	}
	current = data->philos;
	while (current)
	{
		assign_forks(current, data);
		current = current->next;
	}
	return (1);
}
