/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: garevalo <garevalo@student.42madrid.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/22 12:17:33 by garevalo          #+#    #+#             */
/*   Updated: 2026/07/23 22:10:01 by k0fe             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PHILO_H
# define PHILO_H

# include <pthread.h>
# include <stdint.h>
# include <stdio.h>
# include <stdlib.h>
# include <string.h>
# include <sys/time.h>
# include <unistd.h>

# define MAX_PHILO 200

typedef enum e_status
{
	THINKING = 0,
	EATING = 1,
	SLEEPING = 2,
	DEAD = 3
}		t_status;

struct	s_data;

typedef struct s_philo
{
	struct s_data		*data;
	pthread_t			t1;
	uint64_t			time_to_die;
	pthread_mutex_t		lock;
	pthread_mutex_t		*r_fork;
	pthread_mutex_t		*l_fork;
	struct s_philo		*next;
	int					id;
	int					eat_cont;
	int					status;
	int					eating;
}		t_philo;

typedef struct s_data
{
	pthread_mutex_t	*forks;
	pthread_mutex_t	lock;
	pthread_mutex_t	write;
	pthread_t		*tid;
	t_philo			*philos;
	uint64_t		death_time;
	uint64_t		eat_time;
	uint64_t		sleep_time;
	uint64_t		start_time;
	int				philos_nbr;
	int				meals_nbr;
	int				dead;
	int				finished;
}	t_data;

uint64_t	get_time(void);
t_philo		*create_philo(int id, t_data *data);
void		*philo_routine(void *arg);
void		*monitor_routine(void *arg);
void		eat(t_philo *philo);
void		sleepp(t_philo *philo);
void		think(t_philo *philo);
void		pickforks(t_philo *philo);
void		dropforks(t_philo *philo);
void		ft_usleep(uint64_t ms);
void		print_status(t_philo *philo, const char *msg);
void		free_all(t_data *data);
int			ft_atoi(const char *nbr);
int			init_data(t_data *data, int ac, char **av);
int			init_philos(t_data *data);
int			start_simulation(t_data *data);

#endif
