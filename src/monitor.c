#include "../philo.h"

static int check_status(t_philo *philo) {
  pthread_mutex_lock(&philo->lock);
  if (philo->status == DEAD) {
    pthread_mutex_unlock(&philo->lock);
    return (1);
  }
  pthread_mutex_unlock(&philo->lock);
  return (0);
}

static void *check_meals(void *arg) {
  t_philo *philo;

  philo = (t_philo *)arg;
  while (1) {
    pthread_mutex_lock(&philo->lock);
    if (philo->eat_cont == philo->data->meals_nbr) {
      pthread_mutex_unlock(&philo->lock);
      return (NULL);
    }
    pthread_mutex_unlock(&philo->lock);
  }
  return (NULL);
}

void *monitor(void *arg) {
  t_data *data;

  data = (t_data *)arg;
  while (1) {
    // check if any philo is dead
    if (check_status(&data->philos[0]))
      return (NULL);
    // check if all philos have eaten
    if (check_meals(&data->philos[0]))
      return (NULL);
    printf("En monitor %d\n", data->philos[0].id);
  }
  return (NULL);
}

void init_monitor(t_data *data) {
  if (pthread_create(&data->tid[data->philos_nbr], NULL, monitor, data))
    return (error("cannot create thread", data));
}