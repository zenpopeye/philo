/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   monitor.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: k0fe <garevalo@student.42madrid.com>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/07/23 21:39:26 by k0fe              #+#    #+#             */
/*   Updated: 2026/07/23 21:48:36 by k0fe             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../philo.h"

static int	check_death(t_philo *philo)
{
	uint64_t	now;
	uint64_t	last;
	int			died;

	died = 0;
	pthread_mutex_lock(&philo->lock);
	last = philo->last_meal;
	now = get_time();
	if (philo->status != EATING  && now - last > philo->data->death_time)
		died = 1;
	pthread_mutex_unlock(&philo->lock);
	return (died);
}

static int	all_philos_full(t_data *data)
{
	t_philo	*philo;
	int		full;
	int		i;

	i = 0;
	philo = data->philos;
	while (philo && i < data->philos_nbr)
	{
		pthread_mutex_lock(&philo->lock);
		full = (philo->eat_cont >= data->meals_nbr);
		pthread_mutex_unlock(&philo->lock);
		if (!full)
			return (0);
		philo = philo->next;
		i++;
	}
	return (1);
}

static void	monitoring_aux(t_data *data, t_philo *philo)
{
	pthread_mutex_lock(&philo->lock);
	philo->status = DEAD;
	pthread_mutex_unlock(&philo->lock);
	print_status(philo, "died");
	pthread_mutex_lock(&data->lock);
	data->dead = 1;
	pthread_mutex_unlock(&data->lock);
}

static void	*monitoring(t_data *data)
{
	t_philo	*philo;
	int		i;

	i = 0;
	philo = data->philos;
	while (philo && i < data->philos_nbr)
	{
		if (check_death(philo))
		{
			monitoring_aux(data, philo);
			return (NULL);
		}
		philo = philo->next;
		i++;
	}
	if (data->meals_nbr != -1 && all_philos_full(data))
	{
		pthread_mutex_lock(&data->lock);
		data->finished = 1;
		pthread_mutex_unlock(&data->lock);
		return (NULL);
	}
	ft_usleep(100);
	return ((void *)1);
}

void	*monitor_routine(void *arg)
{
	t_data	*data;

	data = (t_data *) arg;
	while (1)
	{
		if (!monitoring(data))
			break ;
	}
	return (NULL);
}
