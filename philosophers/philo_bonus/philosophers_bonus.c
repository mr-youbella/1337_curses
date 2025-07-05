/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philosophers_bonus.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: youbella <youbella@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/23 11:29:52 by youbella          #+#    #+#             */
/*   Updated: 2025/06/10 20:54:18 by youbella         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philosophers_bonus.h"

static short	init_var_sem(char argc, char **argv, t_data *data)
{
	data->n_philo = ft_atoi(argv[1]);
	data->t_d = ft_atoi(argv[2]);
	data->t_e = ft_atoi(argv[3]);
	data->t_s = ft_atoi(argv[4]);
	if (argc == 6)
		data->number_meals = ft_atoi(argv[5]);
	else
		data->number_meals = 0;
	data->start_time = time_now();
	data->forks = sem_open("/forks", O_CREAT | O_EXCL, 0644, data->n_philo);
	if (data->forks == SEM_FAILED)
		return (0);
	data->is_died_sem = sem_open("/is_died", O_CREAT | O_EXCL, 0644, 1);
	if (data->is_died_sem == SEM_FAILED)
		return (sem_end(data, 1), 0);
	data->print_sem = sem_open("/print", O_CREAT | O_EXCL, 0644, 1);
	if (data->print_sem == SEM_FAILED)
		return (sem_end(data, 2), 0);
	data->eat_mutex = sem_open("/eating_plus", O_CREAT | O_EXCL, 0644, 1);
	if (data->eat_mutex == SEM_FAILED)
		return (sem_end(data, 3), 0);
	return (1);
}

static void	no_leaks(t_philo *philo, t_data *data, size_t i, size_t	j)
{
	int		status;

	if (!i)
		i = data->n_philo;
	while (waitpid(-1, &status, 0) > 0)
	{
		if (WIFEXITED(status) && WEXITSTATUS(status) == 1)
		{
			while (j < i)
			{
				kill(philo[j].pid, SIGKILL);
				j++;
			}
			break ;
		}
	}
	sem_close(data->forks);
	sem_close(data->is_died_sem);
	sem_close(data->print_sem);
	sem_close(data->eat_mutex);
	1 && (sem_unlink("/forks"), sem_unlink("/is_died"));
	sem_unlink("/print");
	sem_unlink("/eating_plus");
	free(philo);
}

static void	creat_philos(t_philo *philo, t_data *data)
{
	size_t	i;
	pid_t	pid;

	i = 0;
	while (i < data->n_philo)
	{
		pid = fork();
		if (pid == 0)
		{
			philo[i].id = i + 1;
			philo[i].number_meal_eat = 0;
			philo[i].last_meal = data->start_time;
			philo[i].data = data;
			process(&philo[i]);
			exit(0);
		}
		else if (pid < 0)
		{
			no_leaks(philo, data, i, 0);
			exit(1);
		}
		else
			philo[i].pid = pid;
		i++;
	}
}

int	main(int argc, char **argv)
{
	t_data	data;
	t_philo	*philo;

	if (argc != 5 && argc != 6)
		return (printf(BGRED "Pleas Enter number_of_philo t_die t_eat t_sleep \
[number_of_times_each_philosopher_must_eat]\n" DEF), 1);
	if (!check_numbers(argc, argv, 1, 0))
		return (1);
	if (check_inputs(argc, argv) == 2)
		return (0);
	sem_unlink("/forks");
	sem_unlink("/is_died");
	sem_unlink("/print");
	sem_unlink("/eating_plus");
	philo = malloc(sizeof(t_philo) * data.n_philo);
	if (!philo)
		return (1);
	if (!init_var_sem(argc, argv, &data))
		return (free(philo), 1);
	creat_philos(philo, &data);
	no_leaks(philo, &data, 0, 0);
	return (0);
}
