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
	int			died;

	died = 0;
	pthread_mutex_lock(&philo->lock);
	now = get_time();
	if (!philo->eating && philo->time_to_die && now >= philo->time_to_die)
	{
		died = 1;
		philo->status = DEAD;
	}
	pthread_mutex_unlock(&philo->lock);
	return (died);
}

static int	all_philos_full(t_data *data)
{
	t_philo	*philo;
	int		all_done;

	if (data->meals_nbr == -1)
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
			break ;
		philo = philo->next;
	}
	return (all_done);
}

static void	*monitoring(t_data *data)
{
	t_philo	*philo;

	philo = data->philos;
	while (philo)
	{
		if (check_death(philo))
		{
			print_status(philo, "died");
			pthread_mutex_lock(&data->lock);
			data->dead = 1;
			pthread_mutex_unlock(&data->lock);
			return (NULL);
		}
		philo = philo->next;
	}
	if (all_philos_full(data))
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
		if (NULL == monitoring(data))
			return (NULL);
	}
	return (NULL);
}
