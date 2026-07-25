/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rutine_utils.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: k0fe <garevalo@student.42madrid.com>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/07/23 21:45:31 by k0fe              #+#    #+#             */
/*   Updated: 2026/07/23 21:45:40 by k0fe             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "rutine.h"

void	pick_forks(t_philo *philo, pthread_mutex_t *first,
	pthread_mutex_t *second)
{
	pthread_mutex_lock(first);
	print_status(philo, "has taken a fork");
	pthread_mutex_lock(second);
	print_status(philo, "has taken a fork");
}

void	drop_forks(pthread_mutex_t *first,
	pthread_mutex_t *second)
{
	pthread_mutex_unlock(first);
	pthread_mutex_unlock(second);
}

int	check_meals(t_philo *philo)
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
