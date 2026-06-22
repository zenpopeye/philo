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

static int args_is_valid(char **args) {
  int i;
  int j;

  i = 1;
  while (*args[i]) {
    j = 0;
    if (args[i][j] == '-' || args[i][j] == '+')
      j++;
    while (args[i][j]) {
      if (!is_digit(args[i][j]))
        return (0);
      j++;
    }
    i++;
  }
  return (1);
}

static void *init_philos_in_memm(size_t nro_philos) {
  void *philos;

  if (!nro_philos || nro_philos <= 0)
    return (NULL);
  philos = malloc(sizeof(t_philo) * nro_philos + 1);
  if (!philos)
    return (NULL);
  return (philos);
}

static int add_philo(int id, t_philo *philos, unsigned int time_to_eat,
                     unsigned int time_to_sleep, unsigned int time_to_kill) {
  // create philo instances
  // si no se pudo crear devuelvo 0
  return (1);
}

int main(int ac, char **av) {

  int id;
  size_t nro_philos;
  unsigned long time_to_sleep;
  unsigned long time_to_eat;
  unsigned long time_to_kill;
  typedef struct t_philos philos;

  id = 0;
  if (ac == 5) {
    nro_philos = (size_t)get_value(*av[1]);
    philos = (t_philo *)init_philos_in_memm(nro_hilos);
    if (!philos)
      return (exit_with_error_message("cannot init philos"), -1);
    if (!av)
      return (exit_with_error_message("cannot find any argument"),
              -1); // error handlig, NO_ARGS
    while (*av[id]) {
      if (!args_is_valid(&av))
        return (-1);
      // TODO: needs check for better data types for times in millisecs
      time_to_sleep = (unsigned long)get_value(*av[2]);
      time_to_eat = (unsigned long)get_value(*av[3]);
      time_to_kill = (unsigned long)get_value(*av[4]);
      if (!add_philo(&id, &philos, time_to_sleep, time_to_eat, time_to_kill))
        return (exit_with_error_message("cannot add philo on philos"), -1);
      id++;
    }
    // instance monitoring
    // start the jobs -> routines on philos_jobs.c
    // check updates about philos from monitoring
    // freeing all the space on memmory
  }
  return (0);
}
