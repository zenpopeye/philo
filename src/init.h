/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init.h                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: k0fe <garevalo@student.42madrid.com>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/07/23 21:37:07 by k0fe              #+#    #+#             */
/*   Updated: 2026/07/23 21:37:50 by k0fe             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef INIT_H
# define INIT_H

# include "../philo.h"

t_philo	*create_philo(int id, t_data *data);
int		init_forks(t_data *data);
int		init_mutexes(t_data *data);
int		init_data(t_data *data, int ac, char **av);

#endif
