/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ivaliev <ivaliev@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/13 08:40:24 by ivaliev           #+#    #+#             */
/*   Updated: 2023/01/17 16:35:44 by ivaliev          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"
//argumentlarining hammasi raqam ekanligini tekshirish uchun 
int	check(int ac, char **av)
{
	int			i;
	int			j;

	i = 1;
	while (i < ac)
	{
		j = 0;
		while (av[i][j])
		{
			if (!ft_isdigit(av[i][j]))
				return (0);
			j++;
		}
		i++;
	}
	return (1);
}

int	main(int ac, char **av)
{
	t_philo		philo;
	t_info		info;

	if (ac > 6 || ac < 5)
	{
		printf("Invalid arguments\n");
		return (0);
	}
	if (check(ac, av) == 0)
	{
		printf("Error found letter in arguments\n");
		return (0);
	}
	if (double_check(ac, av) == 0)
	{
		printf("Invalid arguments\n");
		return (0);
	}
	info_init(&philo, &info, ac, av);
	return (0);
}
//we are stocking the argument, creating 
//variable that we will use after as indicator.
//creating the mutex
//crating a structur that each philo created will have
//creating the thread
//and free all the malloc
