/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: garevalo <garevalo@student.42madrid.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/22 11:23:33 by garevalo          #+#    #+#             */
/*   Updated: 2026/07/17 19:11:30 by garevalo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

int	main(int ac, char **av)
{
	t_data	*data;

	data = malloc(sizeof(t_data));
	if (!data)
		return (1);
	if (ac != 5 && ac != 6)
	{
		printf("Usage: ./philo number_of_philosophers time_to_die time_to_eat"
			"time_to_sleep [number_of_times_each_philosopher_must_eat]\n");
		return (free(data), 1);
	}
	if (!init_data(data, ac, av))
		return (free(data), 1);
	if (!init_philos(data))
		return (free(data), 1);
	if (!start_simulation(data))
		return (free(data), 1);
	free_all(data);
	return (0);
}
