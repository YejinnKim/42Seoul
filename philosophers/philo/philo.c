/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yejinkim <yejinkim@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/18 16:53:34 by yejinkim          #+#    #+#             */
/*   Updated: 2023/03/18 16:56:27 by yejinkim         ###   ########seoul.kr  */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

void	print_cmd(int type, t_philo *philo, t_info *info)
{
	int	end;

	pthread_mutex_lock(&info->check);
	end = info->end;
	pthread_mutex_unlock(&info->check);
	pthread_mutex_lock(&info->time);
	if (!end)
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
			printf("%lld %d died\n", info->timestamp, philo->num);
	}
	pthread_mutex_unlock(&info->time);
}

void	eating(t_philo *philo, t_info *info)
{
	pthread_mutex_lock(&info->forks[philo->left_fork]);
	print_cmd(FORK, philo, info);
	pthread_mutex_lock(&info->forks[philo->right_fork]);
	print_cmd(FORK, philo, info);
	print_cmd(EAT, philo, info);
	pthread_mutex_lock(&info->check);
	pthread_mutex_lock(&info->time);
	philo->last_eat = info->timestamp;
	pthread_mutex_unlock(&info->time);
	philo->eat_num++;
	pthread_mutex_unlock(&info->check);
	usleep_time(info, info->eat_time);
	pthread_mutex_unlock(&info->forks[philo->left_fork]);
	pthread_mutex_unlock(&info->forks[philo->right_fork]);
}

void	sleeping(t_philo *philo, t_info *info)
{
	print_cmd(SLEEP, philo, info);
	usleep_time(info, info->sleep_time);
}

void	thinking(t_philo *philo, t_info *info)
{
	print_cmd(THINK, philo, info);
}

void	*do_philo(t_philo *philo)
{
	int	end;

	pthread_mutex_lock(&philo->info->check);
	end = philo->info->end;
	pthread_mutex_unlock(&philo->info->check);
	if (philo->num % 2 == 0)
		usleep(1000);
	while (!end)
	{
		eating(philo, philo->info);
		if (philo->eat_num == philo->info->must_eat)
			break ;
		sleeping(philo, philo->info);
		thinking(philo, philo->info);
		pthread_mutex_lock(&philo->info->check);
		end = philo->info->end;
		pthread_mutex_unlock(&philo->info->check);
	}
	return (0);
}
