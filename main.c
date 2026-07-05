/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: garevalo <garevalo@student.42madrid.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/22 11:23:33 by garevalo          #+#    #+#             */
/*   Updated: 2026/06/22 16:15:40 by garevalo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

int main(int ac, char **av)
{
	t_data data;
	
	if (ac != 5 && ac != 6)
	{
		printf("Usage: ./philo philos_nbr death_time eat_time sleep_time [meals_nbr]\n");
		return (1);
	}
	if (!init_data(&data, ac, av))
		return (1);
	if (!init_philos(&data))
		return (free_all(&data), 1);
	if (!start_simulation(&data))
		return (free_all(&data), 1);
	free_all(&data);
	return (0);
}
