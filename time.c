/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   time.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nleoni <nleoni@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/13 22:11:07 by nleoni            #+#    #+#             */
/*   Updated: 2024/08/30 20:43:01 by nleoni           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

long	get_current_time(void)
{
	struct timeval	tv;
	long			ret;

	if (gettimeofday(&tv, (void *)0) == -1)
		write(2, "Error\nTime\n", 11);
	ret = tv.tv_sec * 1000;
	ret += tv.tv_usec / 1000;
	return (ret);
}

int	ft_usleep(t_data *data, size_t time)
{
	size_t	current_time;

	current_time = get_current_time();
	while (!is_end(data) && (size_t)(get_current_time() - current_time) < time)
		usleep(100);
	return (0);
}
