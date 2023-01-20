/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   start_prog.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ivaliev <ivaliev@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/13 08:38:33 by ivaliev           #+#    #+#             */
/*   Updated: 2023/01/17 16:43:45 by ivaliev          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

void	*pthread(void *philo)
{
	t_philo	*phil;

	phil = (t_philo *)philo;
	if (phil->id % 2)
		usleep(2000);
	while (!ft_check_died(phil))
	{
		if (phil->info->done_eat)
			break ;
		philo_eat(phil);
		print(phil, phil->id, "is sleeping");
		philo_pause(phil, phil->info->time_sleep);
		print(phil, phil->id, "is thinking");
	}
	return (NULL);
}

void	philo_pause(t_philo *philo, int time_pause)
{
	long long	time;

	time = get_time();
	while (!ft_check_died(philo))
	{
		if (get_time() - time >= time_pause)
			break ;
		usleep(500);
	}
}

int	start(t_philo *phil)
{
	int	i;

	i = 0;
	phil->info->start_time = get_time();
	while (i < phil->info->num_philo)
	{
		if (pthread_create(&(phil[i].philo_t), NULL,
				pthread, &(phil[i])))
			return (1);
		++i;
	}
	check_done_eat_and_die(phil);
	i = 0;
	while (i < phil->info->num_philo)
		pthread_join(phil[i++].philo_t, NULL);
	i = 0;
	while (i < phil->info->num_philo)
		pthread_mutex_destroy(&(phil->info->fork[i++]));
	pthread_mutex_destroy(&(phil->info->printig));
	pthread_mutex_destroy(&(phil->info->eating));
	pthread_mutex_destroy(&(phil->info->die));
	pthread_mutex_destroy(&(phil->info->count_eat));
	return (0);
}
