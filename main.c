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

static int	is_digit(char c)
{
	return (c >= '0' && c <= '9');
}

static size_t	ft_strlen(char *s)
{
	size_t	len;

	len = 0;
	while (s[len])
		len++;
	return (len);
}

static int	put_msgfd(char *msg, int fd)
{
	size_t	msg_len;

	if (!msg || fd < 0)
		return (0);
	msg_len = ft_strlen(msg);
	write(fd, msg, msg_len);
	return (1);
}

static int	args_valid(char **av, int ac)
{
	int	i;
	int	j;

	i = 1;
	while (i < ac)
	{
		j = 0;
		while (av[i][j])
		{
			if (!is_digit(av[i][j]))
				return (0);
			j++;
		}
		i++;
	}
	return (1);
}

int	main(int ac, char **av)
{
	t_data	*data;

	if (ac != 5 && ac != 6)
	{
		printf("./philo number_of_philosophers time_to_die time_to_eat"
			"time_to_sleep [number_of_times_each_philosopher_must_eat]\n");
		return (0);
	}
	if (!args_valid(av, ac))
		return (put_msgfd("err in args.", 2), 1);
	data = malloc(sizeof(t_data));
	if (!data)
		return (1);
	if (!init_data(data, ac, av))
		return (free(data), put_msgfd("err on init data\n", 2));
	if (!init_philos(data))
		return (free(data), put_msgfd("err on init philos\n", 2));
	if (!start_simulation(data))
		return (free(data), put_msgfd("err starting simulation\n", 2));
	free_all(data);
	return (0);
}
