/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_end.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nleoni <nleoni@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/13 22:10:58 by nleoni            #+#    #+#             */
/*   Updated: 2024/08/30 21:19:56 by nleoni           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

void	check_meals(t_data *data)
{
	int	i;
	int	to_eat;

	i = 0;
	to_eat = 0;
	if (data->args.meals_max > 0)
	{
		while (i < data->args.num_philos)
		{
			pthread_mutex_lock(&data->meal_lock);
			if (data->philo[i].meals_eaten >= data->args.meals_max)
				to_eat++;
			pthread_mutex_unlock(&data->meal_lock);
			if (to_eat == data->args.num_philos)
			{
				pthread_mutex_lock(&data->end_lock);
				data->end = 1;
				pthread_mutex_unlock(&data->end_lock);
			}
			i++;
		}
	}
}

void	check_death(t_data *data)
{
	int	i;

	i = 0;
	pthread_mutex_lock(&data->meal_lock);
	pthread_mutex_lock(&data->dead_lock);
	while (i < data->args.num_philos)
	{
		if (data->philo[i].eating == 0 && (get_current_time()
				- data->philo[i].last_meal) > data->args.time_die)
		{
			pthread_mutex_lock(&data->end_lock);
			data->end = 1;
			pthread_mutex_unlock(&data->end_lock);
			pthread_mutex_lock(&data->write_lock);
			printf("%zu %d %s\n", (get_current_time()
					- data->philo[i].start_time), i + 1, "died");
			pthread_mutex_unlock(&data->write_lock);
			pthread_mutex_unlock(&data->dead_lock);
			pthread_mutex_unlock(&data->meal_lock);
			return ;
		}
		i++;
	}
	pthread_mutex_unlock(&data->dead_lock);
	pthread_mutex_unlock(&data->meal_lock);
}

int	is_end(t_data *data)
{
	int	end;

	end = 0;
	pthread_mutex_lock(&data->end_lock);
	if (data->end)
		end = 1;
	pthread_mutex_unlock(&data->end_lock);
	return (end);
}
