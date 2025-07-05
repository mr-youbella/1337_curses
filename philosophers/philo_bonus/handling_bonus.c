/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   handling_bonus.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: youbella <youbella@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/23 15:54:53 by youbella          #+#    #+#             */
/*   Updated: 2025/06/10 19:07:58 by youbella         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philosophers_bonus.h"

void	sem_end(t_data *data, short close)
{
	if (close == 1)
	{
		sem_close(data->forks);
		sem_unlink("/forks");
		return ;
	}
	if (close == 2)
	{
		sem_close(data->forks);
		sem_unlink("/forks");
		sem_close(data->is_died_sem);
		sem_unlink("/is_died");
		return ;
	}
	if (close == 3)
	{
		sem_close(data->forks);
		sem_unlink("/forks");
		sem_close(data->is_died_sem);
		sem_unlink("/is_died");
		sem_close(data->print_sem);
		sem_unlink("/print");
		return ;
	}
}

short	check_inputs(int argc, char **argv)
{
	if (ft_atoi(argv[1]) < 0 || ft_atoi(argv[1]) > 200)
		return (printf(BGRED "Use just 1 -> 200 philo.\n" DEF), 0);
	if (!ft_atoi(argv[1]))
		return (2);
	if (ft_atoi(argv[2]) < 60 || ft_atoi(argv[3]) < 60 || ft_atoi(argv[4]) < 60)
		return (printf(BGRED "Use just 60 -> LONG_MAX ms.\n" DEF), 0);
	if (argc == 6 && ft_atoi(argv[5]) < 0)
		return (printf(BGRED "Do not use with more than LONG_MAX.\n" DEF), 0);
	if (argc == 6 && !ft_atoi(argv[5]))
		return (2);
	return (1);
}

short	check_numbers(int argc, char **argv, int i, int j)
{
	while (i < argc)
	{
		j = 0;
		if (argv[i][j] == '+')
			j++;
		if (!argv[i][j])
			return (printf(BGRED "Please Enter just numbers and sign plus.\n"
					DEF), 0);
		while (argv[i][j])
		{
			if (!(argv[i][j] >= '0' && argv[i][j] <= '9'))
				return (printf(BGRED"Please Enter just numbers and sign plus.\n"
						DEF), 0);
			j++;
		}
		i++;
	}
	if (!check_inputs(argc, argv))
		return (0);
	return (1);
}

short	one_philo(t_philo *philo)
{
	if (philo->data->n_philo == 1)
	{
		good_sleep(philo->data->t_d);
		status_print(philo, "died");
		sem_post(philo->data->forks);
		return (0);
	}
	return (1);
}

void	eating(t_philo *philo)
{
	philo->last_meal = time_now();
	status_print(philo, "is eating");
	good_sleep(philo->data->t_e);
	sem_post(philo->data->forks);
	sem_post(philo->data->forks);
}
