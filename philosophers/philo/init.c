/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yejinkim <yejinkim@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/15 17:06:26 by yejinkim          #+#    #+#             */
/*   Updated: 2023/03/17 17:45:17 by yejinkim         ###   ########seoul.kr  */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

// exit() 수정하기

int	ft_atoi(const char *str)
{
	long	i;
	long	sign;
	long	result;

	i = 0;
	sign = 1;
	result = 0;
	while ((str[i] >= 9 && str[i] <= 13) || str[i] == ' ')
		i++;
	if (str[i] == '+' || str[i] == '-')
	{
		if (str[i] == '-')
			sign *= -1;
		i++;
	}
	while (str[i] >= '0' && str[i] <= '9')
	{
		result = result * 10 + (str[i] - '0');
		i++;
		if (result * sign < (long)-2147483648 || result * sign > (long)2147483647)
			exit(0);
	}
	return ((int)result * (int)sign);
}

t_philo	*init_philo(t_info *info)
{
	t_philo	*philo;
	int	i;
	int num;

	i = 0;
	num = info->philo_num;
	philo = malloc(sizeof(t_philo) * num);
	if (!philo)
		exit(0);
	while (i < num)
	{
		philo[i].num = i + 1;
		philo[i].right_fork = i;
		philo[i].left_fork = (i + 1) % num;
		philo[i].eat_num = 0;
		philo[i].last_eat = 0;
		philo[i].info = info;
		i++;
	}
	return philo;
}

void	init_mutex(t_info *info)
{
	int	i;

	i = 0;
	info->forks = malloc(sizeof(pthread_mutex_t) * info->philo_num);
	if (!info->forks)
		exit(0);
	while (i < info->philo_num)
	{
		if (pthread_mutex_init(&(info->forks[i]), NULL))
			exit(0);
		i++;
	}
	if (pthread_mutex_init(&(info->print), NULL))
		exit(0);
}

void	init_info(int argc, char **argv, t_info *info)
{
	info->philo_num = ft_atoi(argv[1]);
	info->die_time = ft_atoi(argv[2]);
	info->eat_time = ft_atoi(argv[3]);
	info->sleep_time = ft_atoi(argv[4]);
	if (argc == 5)
		info->must_eat = -1;
	else 
		info->must_eat = ft_atoi(argv[5]);
	info->start_time = get_time(START);
	info->timestamp = 0;
	info->end = 0;
	init_mutex(info);
}