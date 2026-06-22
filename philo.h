/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: garevalo <garevalo@student.42madrid.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/22 12:17:33 by garevalo          #+#    #+#             */
/*   Updated: 2026/04/30 21:13:55 by garevalo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PHILO_H
#define PHILO_H
#define PHILO_H

#include <pthread.h>
#include <stdint.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <sys/time.h>
#include <unistd.h>

#define MAX_PHILO 200

struct s_data;

typedef struct s_philo {
  struct s_data *data;
  pthread_t t1;
  int id;
  int eat_cont;
  int status;
  int eating;
  uint64_t time_to_die;
  pthread_mutex_t lock;
  pthread_mutex_t *r_fork;
  pthread_mutex_t *l_fork;
} t_philo;

typedef struct s_data {
  pthread_t *tid;
  int philos_nbr;
  int meals_nbr;
  int dead;
  int finished;
  t_philo *philos;
  uint64_t death_time;
  uint64_t eat_time;
  uint64_t sleep_time;
  uint64_t start_time;
  pthread_mutex_t *forks;
  pthread_mutex_t lock;
  pthread_mutex_t write;
} t_data;

int	is_digit(char c);

int init(t_data *data, char **argv, int argc);
void init_monitor(t_data *data);
void init_rutine(t_data *data);

#endif
