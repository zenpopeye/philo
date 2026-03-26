#include "../philo.h"

static void eat(t_philo *philo) {}

static void sleep(t_philo *philo) {}

static void think(t_philo *philo) {}

void *rutine(void *arg) {
  t_philo *philo;

  philo = (t_philo *)arg;
  while (1) {
    printf("En rutina %d\n", philo->id);
    // TODO: make the philo eat
    // TODO: make the philo sleep
    // TODO: make the philo think
  }
  return (NULL);
}

void init_rutine(t_data *data) {
  int i;

  i = 0;
  while (i < data->philos_nbr) {
    if (pthread_create(&data->tid[i], NULL, rutine, &data->philos[i]))
      return (error("cannot create thread", data));
    i++;
  }
}