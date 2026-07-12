#ifndef INIT_H
#define INIT_H

#include "../philo.h"

int	init_forks(t_data *data);
int	init_mutexes(t_data *data);
int	init_data(t_data *data, int ac, char **av);
t_philo	*create_philo(int id, t_data *data);

#endif
