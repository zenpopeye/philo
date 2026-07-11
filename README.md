*Este proyecto ha sido creado como parte del currículo de 42 por garevalo.*
*This project was created as a part of the 42's curriculum by garevalo*

# Description.

## Intodution

Philosophers is one of the best programs to manage "data races" in multi-thread programming.

*Data race* occurs when two or more threads are triying to the same memory address  eg. *&philo->lock*


Why is mutex used to manage this kinda of computanional problems?

Mutex is a Mutual Exclusion Tool, and is useful for protecting 
shared data structures from current modifications and implementingn critical sections
and monitors.

That can lead with data-races. Mutex use decrease the program performance
in ejecution time. This is because mutex block everything inside the *block call* when it is called. 

``` c

static int	check_death(t_philo *philo)
{
	uint64_t now;
	int	died;

	died = 0;
	thread_mutex_lock(&philo->lock);
	now = get_time();
	if (!philo->eating && &philo->time_to_die)
	{
		die = 1;
		philo->status = DEAD;
	}
	pthread_mutex_unlock(&philo->lock);
	return (died);
}

```

You can also see all mutex documentation [clicking here](https://man7.org/linux/man-pages/man3/pthread_mutex_lock.3.html)
Some popular good practises also [clicking here](https://medium.com/@sherniiazov.da/mutexes-in-c-ac2b0f1a6d34) 

Lets dive in into our Philosophers problem. Finally. :neckbeard:

continue here..

Philosophers es uno de los programas que mejor pueden explicar
las condiciones de carrera entre procesos. Y por que es tan importante.
El problema de philosophers nos dicta una serie de reglas y un target,
que todos coman por igual en N ciclos completos (comer-> pensar-> dormir).
Sin que ninguno muera.

Para comer necesitas dos tenedores, cogeras el tenedor del philosopher de 
la derecha, comeras y soltaras el tenedor, pensara y dormiras. 
Aqui en este punto esta la dificultad, ya que los procesos == philosophers 
NO deciden el momento que la CPU les dara para modificar en memoria X 
direccion de memoria (que esta almacenando K variables que deben compartir 
entre todos ya que entre ellos no pueden/deben comunicarse),
Esto puede conseguir que mas de un philosopher puede quedarse sin comer y,
morir.

---

# Intrucciones

``` bash
git clone http://intra-repo-url ~/sgoinfre/philo

cd ~/sgoinfre/philo

#testea Makefile, no debe hacer re-link
make 			#buildea el proyecto.
make re 		#re-buildea.
make clean 		#limpia los objetos generados por make.
make fclean 	#ejecuta make clean y elimina compilados.
make all

# Acuerdate de buildear
make
```

``` bash

./philo philos_nbr death_time eat_time sleep_time [nbr_meals]

```
---

# Recursos

[Geeks4Geeks](https://www.geeksforgeeks.org/operating-systems/dining-philosophers-problem/)

[mutex Linux manual ref.](https://man7.org/linux/man-pages/man3/pthread_mutex_lock.3.html)
