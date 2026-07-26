*This project was created as a part of the 42's curriculum by garevalo*

# Philosophers

## Description

Philosophers is one of the best programs to manage "data races" in multi-thread programming.

*Data race* occurs when two or more threads/proccess are triying to "access/manage" the same memory address eg. *&philo->lock*


Why is mutex used to manage this kinda of computanional problems?

Mutex is a Mutual Exclusion Tool, and is useful for protecting 
shared data structures from current modifications and implementingn critical sections
and monitors.

That can lead with data-races. Mutex bad usage can be decreasing the program performance
in ejecution time and bug the program by deadlock. This is because mutex block everything between the 
*pthread_mutex_lock* */*data manipulation code */* *pthread_mutex_unlock*. Using mutexes we have to try to do not open "data race" windows for preventing unexpected behaivor in our logic.

``` c

static int	check_death(t_philo *philo)
{
	uint64_t now;
	int	died;

	died = 0;
	pthread_mutex_lock(&philo->lock); //lock, im gonna eval if the philo are dead. 
	now = get_time();
	if (!philo->eating && philo->time_to_die 
                        && now - philo->last_meal >= phile->time_to_die) //<- philo is dead?
	{
		die = 1;
		philo->status = DEAD; //possible "data race condition": when 2 or more proccess are trying 
        //to manipulate &philo->status.
        //Actually the main reason is made changes in the same mem address "0x1eFF...0 "
	}
	pthread_mutex_unlock(&philo->lock); //unlocking, the job is done. :D
	return (died);
}

```

NOTE :neckbeard: :
You can also see all mutex documentation [clicking here](https://man7.org/linux/man-pages/man3/pthread_mutex_lock.3.html)
Some popular good practises also [clicking here](https://medium.com/@sherniiazov.da/mutexes-in-c-ac2b0f1a6d34) 

---

## Instructions

### Compilation

``` bash

#cloning repository & change current directory.

git clone git@vogsphere-v2.42madrid.com:vogsphere/intra-uuid-9417db1e-6cae-4e2b-8a52-f9823bb44d9e-7240708-garevalo
~/sgoinfre/philo

cd ~/goinfre/philo

#Makefile cmds
make 			#build project.
make re 		#re-builds.
make clean 		#removes OBJS files.
make fclean 	#clean + removes executable
make all        #builds the project default target.

# build && re-link testing
make && make clean && make all

```

``` bash
#Philo usage

./philo number_of_philosophers time_to_die time_to_eat time_to_sleep [number_of_times_each_philosopher_must_eat]

```

``` table

| Argument                                    | Description                                                                         |
| ------------------------------------------- | ----------------------------------------------------------------------------------- |
| `number_of_philosophers`                    | Number of philosophers and forks                                                    |
| `time_to_die`                               | Time in milliseconds before a philosopher dies if they haven't started eating       |
| `time_to_eat`                               | Time in milliseconds it takes a philosopher to eat                                  |
| `time_to_sleep`                             | Time in milliseconds a philosopher spends sleeping                                  |
| `number_of_times_each_philosopher_must_eat` | *(Optional)* If all philosophers eat at least this many times, the simulation stops |


```
---

# Resources

- [Geeks4Geeks](https://www.geeksforgeeks.org/operating-systems/dining-philosophers-problem/)
- [pthread_create Linux manual ref.](https://man7.org/linux/man-pages/man3/pthread_create.3.html)
- [pthread_mutex_init/destroy/lock/unlock/tryunclok Linux manual ref.](https://man7.org/linux/man-pages/man3/pthread_mutex_init.3.html)
