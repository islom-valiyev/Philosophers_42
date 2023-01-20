/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo_utils.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ivaliev <ivaliev@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/13 08:37:57 by ivaliev           #+#    #+#             */
/*   Updated: 2023/01/17 16:44:04 by ivaliev          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

int	ft_atoi(char *str)
{
	int		i;
	long	res;
	int		sign;

	sign = 1;
	res = 0;
	i = 0;
	if (str[i] == '-')
		return (0);
	if (str[i] == '+')
		i++;
	while (!ft_isdigit(str[i++]))
		return (0);
	i = 0;
	while (ft_isdigit(str[i]))
	{
		res = (res * 10) + (str[i] - 48);
		i++;
		if ((res > 2147483647 && sign == 1))
			return (0);
	}
	return (res * sign);
}

void	print(t_philo *philo, int id, char *is_doing)
{
	pthread_mutex_lock(&(philo->info->printig));
	if (!ft_check_died(philo))
	{
		printf("%lli %i %s\n", get_time() - philo->info->start_time,
			id + 1, is_doing);
	}
	pthread_mutex_unlock(&(philo->info->printig));
}

long long	get_time(void)
{
	struct timeval	tv;

	gettimeofday(&tv, NULL);
	return ((tv.tv_sec * 1000) + (tv.tv_usec / 1000));
}
