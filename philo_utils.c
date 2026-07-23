/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo_utils.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: garevalo <garevalo@student.42madrid.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/23 15:27:25 by garevalo          #+#    #+#             */
/*   Updated: 2026/07/17 18:37:06 by garevalo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

uint64_t	get_time(void)
{
	struct timeval	tv;

	gettimeofday(&tv, NULL);
	return ((tv.tv_sec * 1000) + (tv.tv_usec / 1000));
}

void	ft_usleep(uint64_t ms)
{
	uint64_t	start;

	start = get_time();
	while ((get_time() - start) < ms)
		usleep(100);
}

int	ft_atoi(const char *str)
{
	int	res;
	int	sign;

	res = 0;
	sign = 1;
	while (*str == ' ' || (*str >= 9 && *str <= 13))
		str++;
	if (*str == '-')
		sign = -1;
	if (*str == '-' || *str == '+')
		str++;
	while (*str >= '0' && *str <= '9')
	{
		res = res * 10 + (*str - '0');
		str++;
	}
	return (res * sign);
}

void	print_status(t_philo *philo, const char *msg)
{
	uint64_t	timestamp;
	t_data		*data;

	data = philo->data;
	pthread_mutex_lock(&data->lock);
	if (data->dead && msg[0] != 'd')
	{
		pthread_mutex_unlock(&data->lock);
		return ;
	}
	pthread_mutex_unlock(&data->lock);
	pthread_mutex_lock(&data->write);
	timestamp = get_time() - data->start_time;
	printf("%llu %d %s\n", timestamp, philo->id, msg);
	pthread_mutex_unlock(&data->write);
}
