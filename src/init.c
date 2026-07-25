/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: k0fe <garevalo@student.42madrid.com>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/07/23 21:35:11 by k0fe              #+#    #+#             */
/*   Updated: 2026/07/23 21:36:51 by k0fe             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "init.h"

static void	append_philo(t_philo **head, t_philo *new_philo)
{
	t_philo	*current;

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
	t_philo	*philo;

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
	t_philo	*current;
	int		i;

	i = 1;
	while (i <= data->philos_nbr)
	{
		if (!add_philo(i, data))
			return (0);
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
