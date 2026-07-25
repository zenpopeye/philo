/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rutine.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: k0fe <garevalo@student.42madrid.com>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/07/23 21:45:01 by k0fe              #+#    #+#             */
/*   Updated: 2026/07/25 14:17:19 by garevalo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef RUTINE_H
# define RUTINE_H

# include "../philo.h"

void	pick_forks(t_philo *philo, pthread_mutex_t *first,
			pthread_mutex_t *second);
void	drop_forks(pthread_mutex_t *first, pthread_mutex_t *second);

#endif
