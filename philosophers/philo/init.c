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

int	ft_atoi(const char *str)
{
	long	i;
	long	len;
	long	result;

	result = 0;
	len = 0;
	while (str[len])
		len++;
	i = 0;
	while ((str[i] >= 9 && str[i] <= 13) || str[i] == ' ')
		i++;
	if (str[i] == '+')
		i++;
	while (str[i] >= '0' && str[i] <= '9')
	{
		result = result * 10 + (str[i++] - '0');
		if (result > (long)2147483647)
			return (-1);
	}
	if (len != i || result == 0)
		return (-1);
	else
		return ((int)result);
}

int	dsty_mtx(int n, pthread_mutex_t *f, pthread_mutex_t *t, pthread_mutex_t *c)
{
	int	i;

	if (f)
	{
		i = -1;
		while (++i < n)
			pthread_mutex_destroy(&(f[i]));
		free(f);
	}
	if (t)
		pthread_mutex_destroy(t);
	if (c)
		pthread_mutex_destroy(c);
	return (0);
}

t_philo	*init_philo(t_info *info)
{
	t_philo	*philo;
	int		i;
	int		num;

	i = 0;
	num = info->philo_num;
	philo = malloc(sizeof(t_philo) * num);
	if (!philo)
	{
		dsty_mtx(info->philo_num, info->forks, &info->time, &info->check);
		return (0);
	}
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
	return (philo);
}

int	init_mutex(t_info *info)
{
	int	i;

	i = 0;
	info->forks = malloc(sizeof(pthread_mutex_t) * info->philo_num);
	if (!info->forks)
		return (0);
	while (i < info->philo_num)
	{
		if (pthread_mutex_init(&(info->forks[i]), NULL))
			return (0);
		i++;
	}
	if (pthread_mutex_init(&(info->time), NULL))
		return (dsty_mtx(info->philo_num, info->forks, NULL, NULL));
	if (pthread_mutex_init(&(info->check), NULL))
		return (dsty_mtx(info->philo_num, info->forks, &info->time, NULL));
	return (1);
}

int	init_info(int argc, char **argv, t_info *info)
{
	info->philo_num = ft_atoi(argv[1]);
	info->die_time = ft_atoi(argv[2]);
	info->eat_time = ft_atoi(argv[3]);
	info->sleep_time = ft_atoi(argv[4]);
	if (argc == 5)
		info->must_eat = -2;
	else
		info->must_eat = ft_atoi(argv[5]);
	if (info->philo_num == -1 || info->die_time == -1 || \
		info->eat_time == -1 || info->sleep_time == -1 || info->must_eat == -1)
		return (0);
	info->start_time = get_time(START);
	info->timestamp = 0;
	info->end = 0;
	if (!init_mutex(info))
		return (0);
	return (1);
}
