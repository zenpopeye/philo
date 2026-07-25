/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rutine.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: k0fe <garevalo@student.42madrid.com>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/07/23 21:42:44 by k0fe              #+#    #+#             */
/*   Updated: 2026/07/25 14:15:46 by garevalo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "rutine.h"

static void	eating(t_philo *philo, pthread_mutex_t *first,
	pthread_mutex_t *second)
{
	pick_forks(philo, first, second);
	pthread_mutex_lock(&philo->lock);
	philo->last_meal = get_time();
	philo->eating = 1;
	pthread_mutex_unlock(&philo->lock);
	print_status(philo, "is eating");
	ft_usleep(philo->data->eat_time);
	pthread_mutex_lock(&philo->lock);
	philo->eating = 0;
	philo->eat_cont++;
	pthread_mutex_unlock(&philo->lock);
	drop_forks(first, second);
}

void	eat(t_philo *philo)
{
	pthread_mutex_t	*first;
	pthread_mutex_t	*second;

	if (philo->l_fork < philo->r_fork)
	{
		first = philo->l_fork;
		second = philo->r_fork;
	}
	else
	{
		first = philo->r_fork;
		second = philo->l_fork;
	}
	eating(philo, first, second);
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
