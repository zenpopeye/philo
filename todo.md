# Philosophers Project Todo List

This document outlines the necessary steps to complete and fix the "Philosophers" implementation.

## 1. Header & Structure (`philo.h`)
- [X] **Fix typos**: Rename `pthread t1` to `pthread_t t1` and `unint64_t` to `uint64_t`.
- [X] **Add missing includes**: include `<pthread.h>`, `<stdio.h>`, `<stdlib.h>`, `<unistd.h>`, and `<sys/time.h>`.
- [X] **Standardize naming**: Ensure `t_data` and `t_philo` use consistent field names (e.g., `philos_nbr` vs `philo_nbr`).
- [X] **Define Constants**: Add macros for common values (e.g., maximum philosophers if needed).

## 2. Initialization Logic (`src/init.c`)
- [X] **Implement `init_data`**: Parse and validate command-line arguments (number_of_philosophers, time_to_die, time_to_eat, time_to_sleep, [number_of_times_each_philosopher_must_eat]).
- [X] **Implement `alloc`**: Properly allocate memory for `t_data`, `forks`, and `philos`.
- [X] **Implement `init_forks`**: Initialize all mutexes for forks.
- [X] **Implement `init_philos`**: Set up philosopher structures, assigning IDs and linking forks.

## 3. Utility Functions (`philo_utils.c`)
- [ ] **Fix `ft_exit`**: Correct the loop logic (it currently decrements `i` from `-1`).
- [ ] **Implement `get_time`**: Correctly calculate time in milliseconds using `gettimeofday`.
- [ ] **Refine `ft_usleep`**: Ensure it's precise and doesn't drift significantly.
- [ ] **Error Handling**: Standardize error messages and cleanup on failure.

## 4. Simulation & Routines
- [ ] **Philosopher Routine**: Implement the thread function where philosophers eat, sleep, and think.
- [ ] **Fork Management**: Implement logic to pick up and put down forks using mutexes, preventing deadlocks (e.g., by ordering forks).
- [ ] **Monitoring Thread**: Implement a separate thread to check if any philosopher has died or if all have finished eating.

## 5. Main Entry Point (`main_test.c` -> `main.c`)
- [ ] **Cleanup `main`**: Remove duplicated/messy code.
- [ ] **Simulation Lifecycle**: 
    1. Parse args.
    2. Initialize data.
    3. Start philosopher threads.
    4. Start monitoring thread.
    5. Wait for simulation end.
    6. Cleanup and exit.

## 6. Build System (`Makefile`)
- [ ] **Update Makefile**: Ensure it correctly compiles all source files (`src/init.c`, `philo_utils.c`, `main.c`, etc.) and links `pthread`.

## 7. Bug Fixes & Optimization
- [ ] **Memory Leaks**: Run Valgrind to ensure all allocated memory is freed.
- [ ] **Data Races**: Use thread sanitizer or manual review to ensure all shared variables (like `dead` or `last_meal`) are protected by mutexes.
- [ ] **Deadlock Prevention**: Verify philosophers don't get stuck waiting for forks forever.
