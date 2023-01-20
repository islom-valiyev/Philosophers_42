/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   initialize.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ivaliev <ivaliev@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/13 08:37:31 by ivaliev           #+#    #+#             */
/*   Updated: 2023/01/17 16:42:47 by ivaliev          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

int	ft_isdigit(int num)
{
	if (num >= '0' && num <= '9')
		return (1);
	else
		return (0);
}

void	init_mutex(t_info *info)
{
	int	i;

	info->fork = malloc(sizeof(pthread_mutex_t) * info->num_philo);
	i = 0;
	while (i < info->num_philo)
	{
		pthread_mutex_init(&info->fork[i++], NULL);
	}
	pthread_mutex_init(&info->eating, NULL);
	pthread_mutex_init(&info->die, NULL);
	pthread_mutex_init(&info->printig, NULL);
	pthread_mutex_init(&info->count_eat, NULL);
}

void	philo_init(t_info *info, t_philo *philo)
{
	int	i;

	i = -1;
	while (++i < info->num_philo)
	{
		philo[i].info = info;
		philo[i].ate = 0;
		philo[i].id = i;
		philo[i].info->fork_status[i] = 0;
		philo[i].info->sig[i] = -1;
		philo[i].lfork = i;
		philo[i].rfork = (i + 1) % info->num_philo;
		philo[i].last_ate = get_time();
	}
}

void	info_init(t_philo *philo, t_info *info, int ac, char **av)
{
	philo = malloc(sizeof(t_philo) * ft_atoi(av[1]));
	info = malloc(sizeof(t_info));
	info->num_philo = ft_atoi(av[1]);
	info->fork_status = malloc(sizeof(int) * info->num_philo);
	info->sig = malloc(sizeof(int) * info->num_philo);
	info->time_die = ft_atoi(av[2]);
	info->time_eat = ft_atoi(av[3]);
	info->time_sleep = ft_atoi(av[4]);
	info->done_eat = 0;
	info->count = 0;
	info->died = 0;
	if (ac == 6)
		info->must_eat = ft_atoi(av[5]);
	else
		info->must_eat = 0;
	init_mutex(info);
	philo_init(info, philo);
	start(philo);
	free(philo);
	free(info->fork);
	free(info->fork_status);
	free(info->sig);
	free(info);
}

int	double_check(int ac, char **av)
{
	if (ft_atoi(av[1]) > 200
		|| ft_atoi(av[2]) < 60 || ft_atoi(av[3]) < 60
		|| ft_atoi(av[4]) < 60 || ft_atoi(av[1]) < 1)
		return (0);
	else if (ft_atoi(av[ac - 1]) < 1 && ac == 6)
		return (0);
	return (1);
}
//number_of_philosophers
//time_to_die
//time_to_eat 
//time_to_sleep
//[number_of_times_each_philosopher_must_eat]