/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nleoni <nleoni@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/13 22:14:15 by nleoni            #+#    #+#             */
/*   Updated: 2024/08/30 21:21:54 by nleoni           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

void	join_philos(t_data *data)
{
	int	i;

	i = 0;
	while (i < data->args.num_philos)
	{
		if (i % 2 == 0)
		{
			if (pthread_join(data->philo[i].thread, NULL) != 0)
			{
				printf("Error\n");
				return ;
			}
		}
		i++;
	}
	i = 0;
	while (i < data->args.num_philos)
	{
		if (i % 2 != 0)
		{
			if (pthread_join(data->philo[i].thread, NULL) != 0)
				return ;
		}
		i++;
	}
}

void	create_philos(t_data *data)
{
	int	i;

	i = 0;
	while (i < data->args.num_philos)
	{
		data->philo[i].last_meal = get_current_time();
		if (i % 2 == 0)
		{
			if (pthread_create(&data->philo[i].thread, NULL, &routine,
					(void *)&data->philo[i]) != 0)
				return ;
		}
		i++;
	}
	i = 0;
	while (i < data->args.num_philos)
	{
		if (i % 2 != 0)
		{
			if (pthread_create(&data->philo[i].thread, NULL, &routine,
					(void *)&data->philo[i]) != 0)
				return ;
		}
		i++;
	}
}

void	unlock_mutexes(t_data *data, t_philo *philo)
{
	if (philo->id % 2)
	{
		pthread_mutex_unlock(&data->forks[philo->r_fork]);
		pthread_mutex_unlock(&data->forks[philo->l_fork]);
	}
	else
	{
		pthread_mutex_unlock(&data->forks[philo->l_fork]);
		pthread_mutex_unlock(&data->forks[philo->r_fork]);
	}
}
