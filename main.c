/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nleoni <nleoni@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/13 22:11:04 by nleoni            #+#    #+#             */
/*   Updated: 2024/08/30 21:22:24 by nleoni           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

void	print_output(t_data *data, t_philo *philo, char *str, int id)
{
	if (!is_end(data))
	{
		pthread_mutex_lock(&data->write_lock);
		printf("%zu %d %s\n", (get_current_time() - philo->start_time),
			id, str);
		pthread_mutex_unlock(&data->write_lock);
	}
}

int	main(int ac, char **av)
{
	t_data	data;

	if (check_input(ac, av))
		return (0);
	init_data(&data, av);
	init_philos(&data);
	forks_init(&data);
	create_philos(&data);
	while (!data.end)
	{
		check_death(&data);
		check_meals(&data);
		usleep(100);
	}
	join_philos(&data);
	forks_destroy(&data);
	return (0);
}
