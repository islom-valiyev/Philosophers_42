/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   routine.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ivaliev <ivaliev@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/13 08:38:23 by ivaliev           #+#    #+#             */
/*   Updated: 2023/01/17 16:43:40 by ivaliev          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

void	take_fork(t_philo *philo, int lfork, int rfork, int id)
{
	pthread_mutex_lock(&(philo->info->count_eat));
	philo->ate++;
	if (philo->ate == philo->info->must_eat)
		philo->info->count++;
	pthread_mutex_unlock(&(philo->info->count_eat));
	pthread_mutex_lock(&(philo->info->fork[lfork]));
	philo->info->fork_status[lfork] = 1;
	philo->info->sig[lfork] = philo->id;
	print(philo, id, "has taken a fork");
	pthread_mutex_unlock(&(philo->info->fork[lfork]));
	pthread_mutex_lock(&(philo->info->fork[rfork]));
	philo->info->fork_status[rfork] = 1;
	philo->info->sig[rfork] = philo->id;
	print(philo, id, "has taken a fork");
	pthread_mutex_unlock(&(philo->info->fork[rfork]));
}

int	cheack_fork_status(t_philo *philo)
{
	int	rfork;
	int	lfork;
	int	rsig;
	int	lsig;

	if (philo->info->num_philo == 1)
		return (0);
	pthread_mutex_lock(&(philo->info->fork[philo->rfork]));
	rfork = philo->info->fork_status[philo->rfork];
	rsig = philo->info->sig[philo->rfork];
	pthread_mutex_unlock(&(philo->info->fork[philo->rfork]));
	pthread_mutex_lock(&(philo->info->fork[philo->lfork]));
	lfork = philo->info->fork_status[philo->lfork];
	lsig = philo->info->sig[philo->lfork];
	pthread_mutex_unlock(&(philo->info->fork[philo->lfork]));
	if (lfork == 0 && rfork == 0 && lsig != philo->id && rsig != philo->id)
	{
		take_fork(philo, philo->lfork, philo->rfork, philo->id);
		return (1);
	}
	return (0);
}

void	put_down_fork(t_philo *philo)
{
	pthread_mutex_lock(&(philo->info->fork[philo->lfork]));
	philo->info->fork_status[philo->lfork] = 0;
	pthread_mutex_unlock(&(philo->info->fork[philo->lfork]));
	pthread_mutex_lock(&(philo->info->fork[philo->rfork]));
	philo->info->fork_status[philo->rfork] = 0;
	pthread_mutex_unlock(&(philo->info->fork[philo->rfork]));
}

void	philo_eat(t_philo *philo)
{
	while (!ft_check_died(philo))
	{
		usleep(100);
		if (cheack_fork_status(philo))
			break ;
	}
	print(philo, philo->id, "is eating");
	philo_pause(philo, philo->info->time_eat);
	pthread_mutex_lock(&(philo->info->eating));
	philo->last_ate = get_time();
	pthread_mutex_unlock(&(philo->info->eating));
	put_down_fork(philo);
}
