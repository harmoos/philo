/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   routine.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nleoni <nleoni@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/13 22:14:25 by nleoni            #+#    #+#             */
/*   Updated: 2024/08/30 21:21:05 by nleoni           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

void	thinking(t_data *data, t_philo *philo)
{
	print_output(data, philo, "is thinking", philo->id + 1);
}

void	sleeping(t_data *data, t_philo *philo)
{
	print_output(data, philo, "is sleeping", philo->id + 1);
	ft_usleep(data, data->args.time_sleep);
}

void	meal_eating(t_data *data, t_philo *philo)
{
	pthread_mutex_lock(&data->meal_lock);
	philo->eating = 1;
	pthread_mutex_unlock(&data->meal_lock);
	print_output(data, philo, "is eating", philo->id + 1);
	pthread_mutex_lock(&data->meal_lock);
	philo->last_meal = get_current_time();
	pthread_mutex_unlock(&data->meal_lock);
	ft_usleep(data, data->args.time_eat);
	pthread_mutex_lock(&data->meal_lock);
	philo->eating = 0;
	pthread_mutex_unlock(&data->meal_lock);
	pthread_mutex_lock(&data->meal_lock);
	philo->meals_eaten++;
	pthread_mutex_unlock(&data->meal_lock);
}

void	eating(t_data *data, t_philo *philo)
{
	if (philo->id % 2)
	{
		pthread_mutex_lock(&data->forks[philo->l_fork]);
		print_output(data, philo, "has taken a fork", philo->id + 1);
		pthread_mutex_lock(&data->forks[philo->r_fork]);
		print_output(data, philo, "has taken a fork", philo->id + 1);
	}
	else
	{
		pthread_mutex_lock(&data->forks[philo->r_fork]);
		print_output(data, philo, "has taken a fork", philo->id + 1);
		if (data->args.num_philos == 1)
		{
			ft_usleep(data, data->args.time_die);
			pthread_mutex_unlock(&data->forks[philo->r_fork]);
			return ;
		}
		pthread_mutex_lock(&data->forks[philo->l_fork]);
		print_output(data, philo, "has taken a fork", philo->id + 1);
	}
	meal_eating(data, philo);
	unlock_mutexes(data, philo);
}

void	*routine(void *arg)
{
	t_philo	*philo;
	t_data	*data;

	philo = (t_philo *)arg;
	data = (t_data *)philo->data;
	while (!is_end(data))
	{
		if (!is_end(data))
			eating(data, philo);
		if (!is_end(data))
			sleeping(data, philo);
		thinking(data, philo);
	}
	return (0);
}
