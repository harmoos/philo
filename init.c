/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nleoni <nleoni@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/13 22:14:19 by nleoni            #+#    #+#             */
/*   Updated: 2024/08/30 21:20:01 by nleoni           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

void	forks_init(t_data *data)
{
	int	i;

	i = 0;
	while (i < data->args.num_philos)
	{
		pthread_mutex_init(&data->forks[i], NULL);
		i++;
	}
	pthread_mutex_init(&data->dead_lock, NULL);
	pthread_mutex_init(&data->write_lock, NULL);
	pthread_mutex_init(&data->meal_lock, NULL);
	pthread_mutex_init(&data->end_lock, NULL);
}

void	forks_destroy(t_data *data)
{
	int	i;

	i = 0;
	while (i < data->args.num_philos)
	{
		pthread_mutex_destroy(&data->forks[i]);
		i++;
	}
	pthread_mutex_destroy(&data->dead_lock);
	pthread_mutex_destroy(&data->write_lock);
	pthread_mutex_destroy(&data->meal_lock);
	pthread_mutex_destroy(&data->end_lock);
}

void	init_data(t_data *data, char **args)
{
	data->args.num_philos = ft_atoi(args[1]);
	data->args.time_die = ft_atoi(args[2]);
	data->args.time_eat = ft_atoi(args[3]);
	data->args.time_sleep = ft_atoi(args[4]);
	if (args[5])
		data->args.meals_max = ft_atoi(args[5]);
	else
		data->args.meals_max = -1;
	data->start_time = get_current_time();
	data->end = 0;
}

void	init_philos(t_data *data)
{
	int	i;

	i = 0;
	while (i < data->args.num_philos)
	{
		data->philo[i].data = (void *)data;
		data->philo[i].id = i;
		data->philo[i].eating = 0;
		data->philo[i].meals_eaten = 0;
		data->philo[i].last_meal = 0;
		data->philo[i].start_time = data->start_time;
		data->philo[i].r_fork = i;
		if (i == 0)
			data->philo[i].l_fork = data->args.num_philos - 1;
		else
			data->philo[i].l_fork = i - 1;
		i++;
	}
}
