/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cleanup.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: k0fe <garevalo@student.42madrid.com>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/07/23 21:33:58 by k0fe              #+#    #+#             */
/*   Updated: 2026/07/23 21:34:51 by k0fe             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../philo.h"

void	free_all(t_data *data)
{
	t_philo	*tmp;
	int		i;

	if (data->forks)
	{
		i = 0;
		while (i < data->philos_nbr)
			pthread_mutex_destroy(&data->forks[i++]);
		free(data->forks);
	}
	while (data->philos)
	{
		tmp = data->philos;
		data->philos = data->philos->next;
		pthread_mutex_destroy(&tmp->lock);
		free(tmp);
	}
	pthread_mutex_destroy(&data->lock);
	pthread_mutex_destroy(&data->write);
	if (data->tid)
		free(data->tid);
}
