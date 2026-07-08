Este proyecto ha sido creado como parte del currículo de 42 por garevalo.

# Descripcion

## to-do: traducir al ingles.

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
