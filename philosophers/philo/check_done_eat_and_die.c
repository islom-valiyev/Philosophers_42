/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_done_eat_and_die.c                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ivaliev <ivaliev@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/15 14:56:37 by ivaliev           #+#    #+#             */
/*   Updated: 2023/01/17 16:44:15 by ivaliev          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

void	death(t_philo *philo)
{
	pthread_mutex_lock(&(philo->info->die));
	philo->info->died = 1;
	pthread_mutex_unlock(&(philo->info->die));
}

void	done_eat(t_philo *philo)
{
	pthread_mutex_lock(&(philo->info->die));
	philo->info->done_eat = 1;
	pthread_mutex_unlock(&(philo->info->die));
}

int	ft_check_died(t_philo *philo)
{
	pthread_mutex_lock(&(philo->info->die));
	if (philo->info->died)
	{
		pthread_mutex_unlock(&(philo->info->die));
		return (1);
	}
	pthread_mutex_unlock(&(philo->info->die));
	return (0);
}

int	check_death(t_philo *philo)
{
	int			i;
	long long	time;

	pthread_mutex_lock(&philo->info->count_eat);
	if (philo->info->must_eat > 0 && \
		philo->info->count >= philo->info->num_philo)
		done_eat(philo);
	pthread_mutex_unlock(&philo->info->count_eat);
	i = 0;
	while (i < philo->info->num_philo)
	{
		pthread_mutex_lock(&(philo->info->eating));
		time = philo[i].last_ate;
		pthread_mutex_unlock(&(philo->info->eating));
		if (get_time() - time >= philo->info->time_die)
		{
			print(philo, i, "died");
			death(philo);
		}
		if (ft_check_died(philo))
			return (1);
		i++;
	}
	return (0);
}

void	check_done_eat_and_die(t_philo *phil)
{
	while (!phil->info->done_eat)
	{
		usleep(200);
		if (check_death(phil) || phil->info->done_eat)
			break ;
	}
}
