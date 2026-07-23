/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rutine.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: k0fe <garevalo@student.42madrid.com>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/07/23 21:42:44 by k0fe              #+#    #+#             */
/*   Updated: 2026/07/23 22:24:57 by k0fe             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "rutine.h"

void	eat(t_philo *philo)
{
	pick_forks(philo);
	pthread_mutex_lock(&philo->lock);
	philo->eating = 1;
	philo->time_to_die = get_time() + philo->data->death_time;
	philo->eat_cont++;
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

static int	check_meals(t_philo *philo)
{
	int	done;

	done = 0;
	pthread_mutex_lock(&philo->lock);
	if (philo->data->meals_nbr != -1
		&& philo->eat_cont >= philo->data->meals_nbr)
		done = 1;
	pthread_mutex_unlock(&philo->lock);
	return (done);
}
//revisar logica entro en un bucle , debe estar bloqueandose entre procesos y ninguno accede
void	*philo_routine(void *arg)
{
	t_philo	*philo;

	philo = (t_philo *)arg;
	if (philo->id % 2 == 0)
		ft_usleep(philo->data->eat_time / 2);
	while (1)
	{
		pthread_mutex_lock(&philo->data->lock);
		if (philo->data->dead || philo->data->finished)
		{
			pthread_mutex_unlock(&philo->data->lock);
			break ;
		}
		pthread_mutex_unlock(&philo->data->lock);
		eat(philo);
		if (check_meals(philo))
			break ;
		sleepp(philo);
		think(philo);
	}
	return (NULL);
}
