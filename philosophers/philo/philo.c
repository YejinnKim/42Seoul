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
	pthread_mutex_lock(&info->print);
	if (!info->end)
	{
		if (type == FORK)
			printf("%lld %d has taken a fork\n", info->timestamp, philo->num);
		else if (type == EAT)
			printf("%lld %d is eating [%lld]\n", info->timestamp, philo->num, philo->last_eat);
		else if (type == SLEEP)
			printf("%lld %d is sleeping\n", info->timestamp, philo->num);
		else if (type == THINK)
			printf("%lld %d is thinking\n", info->timestamp, philo->num);
		else if (type == DIE)
			printf("%lld %d died [%lld]\n", info->timestamp, philo->num, philo->last_eat);
	}
	pthread_mutex_unlock(&info->print);
}

void    eating(t_philo *philo, t_info *info)
{
    pthread_mutex_lock(&info->forks[philo->left_fork]);
	print_cmd(FORK, philo, info);
	pthread_mutex_lock(&info->forks[philo->right_fork]);
	print_cmd(FORK, philo, info);
	philo->eat_num++;
	print_cmd(EAT, philo, info);
	philo->last_eat = info->timestamp + info->eat_time;
	usleep_time(info, info->eat_time);
	pthread_mutex_unlock(&info->forks[philo->left_fork]);
	pthread_mutex_unlock(&info->forks[philo->right_fork]);
}

void    sleeping(t_philo *philo, t_info *info)
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
	if (philo->num % 2 == 0)
		usleep(2000); // 1000으로 수정?
	while (1)
	{
		if (philo->num % 2 == 0) // 삭제?
			usleep(200);
        eating(philo, philo->info);
		if (philo->eat_num == philo->info->must_eat)
			break ;
        sleeping(philo, philo->info);
		thinking(philo, philo->info);
	}
	return (0);
}