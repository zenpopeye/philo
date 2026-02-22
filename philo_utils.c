/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo_utils.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: garevalo <garevalo@student.42madrid.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/22 11:23:33 by garevalo          #+#    #+#             */
/*   Updated: 2026/02/22 12:16:04 by garevalo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

static int	args_is_valid(char **args)
{
	int i;
	int j;

	i = 1;
	while (*args[i])
	{
		j = 0;
		if (args[i][j] == '-' || args[i][j] == '+')
			j++;
		while (args[i][j])
		{
			if (!is_digit(args[i][j]))
				return (0);
			j++;
		}
		i++;
	}	
	return (1);
}

int main(int ac, char **av)
{
	//TODO: 
	// [X] check and validate the params/args
	// [] create philo instances : create(number_of_philosophers time_to_die time_to_eat time_to_sleep )
	// [] check error on create
	// [] show philo data
	
	int i;
	unsigned int	nro_philos;
	unsigned long int	time_to_sleep;
	unsigned long int	time_to_eat;
	unsigned long int	time_to_dead;
	typedef struct t_philos philos;

	i = 0;
	if (ac == 5)
	{
		if (!init_philos(&philos))
			exit_with_error_message("cannot init philos");
		if (!av)
			return (0);//error handlig, NO_ARGS	
		while (*av[i])
		{
			if (!args_is_valid(&av))
				return (-1);
			nro_philos = (unsigned int) get_nbr_value(*av[1]);
			time_to_sleep = (unsigned long int) get_nbr_value(*av[2]);
			time_to_eat = (unsigned long int) get_nbr_value(*av[3]);
			time_to_die = (unsigned long int) get_nbr_value(*av[4]);
			if (!add_philo(&philos, nro_philos, time_to_sleep, time_to_eat, time_to_die))
				exit_with_error_message("cannot add philo on philos");
			i++;
		}
		//instance monitoring
		//start the jobs -> routines on philos_jobs.c
		//check updates about philos from monitoring
		//freeing all the space on memmory
	}
	return (0);
}
