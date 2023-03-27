/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yejinkim <yejinkim@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/18 16:53:34 by yejinkim          #+#    #+#             */
/*   Updated: 2023/03/27 16:18:51 by yejinkim         ###   ########seoul.kr  */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

int	fork_ing(t_philo *philo, t_info *info)
{
	pthread_mutex_lock(&info->forks[philo->left_fork]);
	if (print_cmd(FORK, philo, info))
	{
		pthread_mutex_unlock(&info->forks[philo->left_fork]);
		return (1);
	}
	if (check_one(info))
		return (1);
	pthread_mutex_lock(&info->forks[philo->right_fork]);
	if (print_cmd(FORK, philo, info))
	{
		pthread_mutex_unlock(&info->forks[philo->left_fork]);
		pthread_mutex_unlock(&info->forks[philo->right_fork]);
		return (1);
	}
	return (0);
}

int	eating(t_philo *philo, t_info *info)
{
	if (print_cmd(EAT, philo, info))
	{
		pthread_mutex_unlock(&info->forks[philo->left_fork]);
		pthread_mutex_unlock(&info->forks[philo->right_fork]);
		return (1);
	}
	pthread_mutex_lock(&info->time);
	philo->last_eat = info->timestamp;
	pthread_mutex_unlock(&info->time);
	usleep_time(info, info->eat_time);
	pthread_mutex_unlock(&info->forks[philo->left_fork]);
	pthread_mutex_unlock(&info->forks[philo->right_fork]);
	pthread_mutex_lock(&info->check);
	philo->eat_num++;
	pthread_mutex_unlock(&info->check);
	if (philo->eat_num == info->must_eat)
		return (1);
	return (0);
}

int	sleeping(t_philo *philo, t_info *info)
{
	if (print_cmd(SLEEP, philo, info))
		return (1);
	usleep_time(info, info->sleep_time);
	return (0);
}

int	thinking(t_philo *philo, t_info *info)
{
	if (print_cmd(THINK, philo, info))
		return (1);
	return (0);
}

void	*do_philo(t_philo *philo)
{
	if (philo->num % 2 == 0)
		usleep(500);
	while (1)
	{
		if (fork_ing(philo, philo->info))
			break ;
		if (eating(philo, philo->info))
			break ;
		if (sleeping(philo, philo->info))
			break ;
		if (thinking(philo, philo->info))
			break ;
	}
	return (0);
}
