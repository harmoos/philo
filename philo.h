/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nleoni <nleoni@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/13 22:16:59 by nleoni            #+#    #+#             */
/*   Updated: 2024/08/30 20:42:59 by nleoni           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PHILO_H
# define PHILO_H

# include <sys/time.h>
# include <stdio.h>
# include <stdlib.h>
# include <unistd.h>
# include <pthread.h>

typedef struct s_args
{
	int				num_philos;
	size_t			time_die;
	size_t			time_eat;
	size_t			time_sleep;
	int				meals_max;
}	t_args;

typedef struct s_philo
{
	void			*data;
	pthread_t		thread;
	int				id;
	int				eating;
	int				meals_eaten;
	int				num_times_eat;
	size_t			last_meal;
	t_args			args;
	size_t			start_time;
	int				r_fork;
	int				l_fork;
}	t_philo;

typedef struct s_data
{
	int				end;
	size_t			start_time;
	t_args			args;
	t_philo			philo[200];
	pthread_mutex_t	forks[200];
	pthread_mutex_t	write_lock;
	pthread_mutex_t	end_lock;
	pthread_mutex_t	meal_lock;
	pthread_mutex_t	dead_lock;
}	t_data;

/*	init	*/

void	init_philos(t_data *data);
void	forks_init(t_data *data);
void	forks_destroy(t_data *data);
void	init_data(t_data *data, char **args);

/*	parsing	*/

int		ft_atoi(char *str);
int		ft_isdigit(char c);
int		check_input(int ac, char **av);

/*	philo	*/

void	create_philos(t_data *data);
void	join_philos(t_data *data);
void	unlock_mutexes(t_data *data, t_philo *philo);

/*	time	*/

long	get_current_time(void);
int		ft_usleep(t_data *data, size_t time);

/*	routine	*/

void	*routine(void *arg);
void	eating(t_data *data, t_philo *philo);
void	sleeping(t_data *data, t_philo *philo);
void	thinking(t_data *data, t_philo *philo);
void	meal_eating(t_data *data, t_philo *philo);

/*	check_end	*/

int		is_end(t_data *data);
void	check_meals(t_data *data);
void	check_death(t_data *data);

void	print_output(t_data *data, t_philo *philo, char *str, int id);

#endif
