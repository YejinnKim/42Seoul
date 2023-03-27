/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_print.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yejinkim <yejinkim@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/18 16:53:34 by yejinkim          #+#    #+#             */
/*   Updated: 2023/03/27 16:17:42 by yejinkim         ###   ########seoul.kr  */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

int	check_one(t_info *info)
{
	if (info->philo_num == 1)
	{
		while (1)
		{
			pthread_mutex_lock(&info->end_mutex);
			if (info->end)
			{
				pthread_mutex_unlock(&info->end_mutex);
				pthread_mutex_unlock(&info->forks[0]);
				return (1);
			}
			pthread_mutex_unlock(&info->end_mutex);
		}
	}
	return (0);
}

int	check_die(t_philo *philo, t_info *info)
{
	int	last_eat;
	int	eat_num;

	pthread_mutex_lock(&info->time);
	last_eat = philo->last_eat;
	pthread_mutex_unlock(&info->time);
	pthread_mutex_lock(&info->check);
	eat_num = philo->eat_num;
	pthread_mutex_unlock(&info->check);
	if ((last_eat + info->die_time < get_time(info->start_time)))
	{
		if (eat_num == info->must_eat)
			return (-1);
		pthread_mutex_lock(&info->time);
		info->timestamp = get_time(info->start_time);
		pthread_mutex_unlock(&info->time);
		print_cmd(DIE, philo, info);
		return (1);
	}
	return (0);
}

void	check_philo(t_philo *philo, t_info *info)
{
	int	i;
	int	die;

	while (1)
	{
		i = 0;
		while (i < info->philo_num)
		{
			die = check_die(&philo[i], info);
			if (die)
				return ;
			else if (die == -1)
				continue ;
			i++;
		}
	}
}

void	print_type(int type, t_philo *philo, t_info *info)
{
	if (type == FORK)
		printf("%lld %d has taken a fork\n", info->timestamp, philo->num);
	else if (type == EAT)
		printf("%lld %d is eating\n", info->timestamp, philo->num);
	else if (type == SLEEP)
		printf("%lld %d is sleeping\n", info->timestamp, philo->num);
	else if (type == THINK)
		printf("%lld %d is thinking\n", info->timestamp, philo->num);
	else if (type == DIE)
	{
		printf("%lld %d died\n", info->timestamp, philo->num);
		info->end = 1;
	}
}

int	print_cmd(int type, t_philo *philo, t_info *info)
{
	pthread_mutex_lock(&info->end_mutex);
	if (!info->end)
	{
		pthread_mutex_lock(&info->time);
		print_type(type, philo, info);
		pthread_mutex_unlock(&info->time);
		pthread_mutex_unlock(&info->end_mutex);
		return (0);
	}
	else
	{
		pthread_mutex_unlock(&info->end_mutex);
		return (1);
	}
}
