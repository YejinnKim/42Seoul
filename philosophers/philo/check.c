/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yejinkim <yejinkim@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/18 16:53:34 by yejinkim          #+#    #+#             */
/*   Updated: 2023/03/18 16:56:27 by yejinkim         ###   ########seoul.kr  */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

void	*do_one_philo(t_philo *philo)
{
	int	end;

	pthread_mutex_lock(&philo->info->check);
	end = philo->info->end;
	pthread_mutex_unlock(&philo->info->check);
	while (1)
	{
		pthread_mutex_lock(&philo->info->forks[philo->left_fork]);
		print_cmd(FORK, philo, philo->info);
		if (!end)
			break ;
	}
	return (0);
}

int	check_die(t_philo *philo, t_info *info)
{
	int	last_eat;
	int	eat_num;

	pthread_mutex_lock(&info->check);
	last_eat = philo->last_eat;
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
		pthread_mutex_lock(&info->check);
		info->end = 1;
		pthread_mutex_unlock(&info->check);
		return (1);
	}
	return (0);
}

int	check_eat(t_philo *philo, t_info *info)
{
	int	i;

	i = 0;
	while (i < info->philo_num)
	{
		pthread_mutex_lock(&info->check);
		if (philo[i].eat_num != info->must_eat)
		{
			pthread_mutex_unlock(&info->check);
			break ;
		}
		pthread_mutex_unlock(&info->check);
		i++;
	}
	if (i == info->philo_num)
		return (1);
	return (0);
}

void	check_philo(t_philo *philo, t_info *info)
{
	int	i;
	int	die;

	while (!info->end)
	{
		i = 0;
		while (i < info->philo_num)
		{
			die = check_die(&philo[i], info);
			if (die)
				return ;
			else if (die == -1)
				continue ;
			if (check_eat(philo, info))
				return ;
			i++;
		}
	}
}
