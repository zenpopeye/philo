#include "../philo.h"

int init_data(t_data *data, char **argv, int argc) {
  if (argc < 5 || argc > 6)
    return (1);
  data->philos_nbr = ft_atoi(argv[1]);
  if (data->philos_nbr > MAX_PHILO)
    return (1);
  data->death_time = ft_atoi(argv[2]);
  data->eat_time = ft_atoi(argv[3]);
  data->sleep_time = ft_atoi(argv[4]);
  if (argc == 6)
    data->meals_nbr = ft_atoi(argv[5]);
  else
    data->meals_nbr = -1;
  if (data->philos_nbr <= 0 || data->death_time <= 0 || data->eat_time <= 0 ||
      data->sleep_time <= 0)
    return (1);
  return (0);
}

int alloc(t_data *data) {
  // TODO: allocate t_data on mem
  data->tid = malloc(sizeof(pthread_t) * data->philos_nbr);
  data->forks = malloc(sizeof(pthread_mutex_t) * data->philos_nbr);
  data->philos = malloc(sizeof(t_philo) * data->philos_nbr);
  if (!data->tid || !data->forks || !data->philos)
    return (1);
  return (0);
}

int init_forks(t_data *data) {
  // init forks.
  int i;

  i = 0;
  while (i < data->philos_nbr)
    pthread_mutex_init(&data->philos[i].lock, NULL);
  return (0);
}

int init_philos(t_data *data) {
  // init philos.
  int i;

  i = 0;
  while (i < data->philos_nbr)
    data->philos[i].id = i;
  return (0);
}
int init(t_data *data, char **argv, int argc) {
  if (init_data(data, argv, argc))
    return (1);
  if (alloc(data))
    return (1);
  if (init_forks(data))
    return (1);
  if (init_philos(data))
    return (1);
  return (0);
}
