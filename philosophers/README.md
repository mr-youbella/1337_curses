# Philosophers

Two versions of the dining philosophers simulation, using threads and processes.

[Repository](../README.md) · **C / pthreads / semaphores** · **Score: 125**

## Threads and shared state

The mandatory [philo/](philo/) version starts one thread per philosopher and a monitor thread. Forks are mutexes. Separate mutexes protect printing, meal state, completion counts, and stop/failure flags.

Each philosopher takes two forks, eats, releases the forks, sleeps, and thinks. Even-numbered philosophers begin with a short delay to stagger fork acquisition. The monitor checks last-meal times and the optional meal target. Sleeps use short `usleep` intervals so the threaded routine can notice a stop condition. A single philosopher has a separate path because it cannot obtain two forks.

The [philo_bonus/](philo_bonus/) version forks a process for each philosopher. Named semaphores represent the fork pool and coordinate output and death reporting. A monitor thread runs inside each child, while the parent waits for children and terminates the others after a reported death.

## Build

Run these commands from this directory:

```bash
make -C philo
make -C philo_bonus
```

Each subdirectory has its own Makefile and binary. Both recipes run **Norminette before compiling each source file**, so Make, `cc`, and Norminette must be available. The code uses POSIX threads; the bonus also needs `fork` and named semaphores. The checked-in link commands do not add `-pthread`, which may need adjustment on other platforms.

**Current bonus limitations:** its Makefile stops on Norminette errors in `routine_bonus.c`. In addition, `main` allocates the philosopher array using `data.n_philo` before `init_var_sem` initializes it. The process-based source is present, but this checkout needs those issues addressed before relying on bonus runs.

## Arguments and usage

```text
number_of_philosophers time_to_die time_to_eat time_to_sleep [meal_target]
```

Times are in milliseconds. This implementation accepts up to 200 philosophers and requires the three time values to be at least 60. Zero philosophers or a zero meal target exits without starting a simulation.

```bash
./philo/philo 5 800 200 200 7
./philo/philo 1 800 200 200
```

After resolving the bonus limitations, its equivalent invocation is:

```bash
./philo_bonus/philo_bonus 5 800 200 200 7
```

Output includes an elapsed timestamp, philosopher ID, and state such as `has taken a fork`, `is eating`, `is sleeping`, `is thinking`, or `died`, with terminal colors. A meal target provides a finite run; exact scheduling and output order vary.

## Checking behavior

Use the mandatory examples to inspect meal-target termination and the single-philosopher case. Try a short time-to-die scenario to exercise the monitor. A successful run alone does not establish the absence of races or deadlocks; there is no dedicated test runner here. The bonus uses fixed semaphore names, so avoid overlapping bonus sessions.

Use `make -C philo clean` or `fclean` for the threaded build, and the corresponding commands in `philo_bonus` for the process build.

[Project subject](../Subjects/philosophers.subject.pdf) · [Back to 1337 Curses](../README.md)
