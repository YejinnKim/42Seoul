/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yejinkim <yejinkim@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/13 16:53:34 by yejinkim          #+#    #+#             */
/*   Updated: 2023/03/17 23:46:27 by yejinkim         ###   ########seoul.kr  */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

long	get_time(void)
{
	struct timeval time;
	
	gettimeofday(&time, NULL);
	return (time.tv_sec * 1000000 + time.tv_usec);
}

void	usleep_time(t_info *info, int time)
{
	//printf("time: %d\n", time);
	while (time * 1000 >= get_time() - info->start_time)
	{
		usleep(1);
		//printf("sleep %ld %ld\n", get_time(), info->start_time);
	}
	info->timestamp += time;
}

void	print_cmd(t_philo *philo, t_info *info, int type)
{
	pthread_mutex_lock(&info->print);
	if (type == FORK)
		printf("%d %d has taken a fork\n", info->timestamp, philo->num + 1);
	else if (type == EAT)
	{
		printf("%d %d is eating\n", info->timestamp, philo->num + 1);
		philo->last_eat = info->timestamp;
		philo->eat_num++;
		usleep_time(info, info->eat_time);
	}
	else if (type == SLEEP)
	{
		printf("%d %d is sleeping\n", info->timestamp, philo->num + 1);
		usleep_time(info, info->sleep_time);
	}
	else if (type == THINK)
		printf("%d %d is thinking\n", info->timestamp, philo->num + 1);
	else if (type == DIE)
		printf("%d %d died\n", info->timestamp, philo->num + 1); 
	pthread_mutex_unlock(&info->print);
}

void	*do_philo(t_philo *philo)
{
	int	time;

	time = 0;
	if (philo->num % 2 != 0)
		usleep(1000);
	//while (!philo->die)
	{
		pthread_mutex_lock(&philo->info->forks[philo->left_fork]);
		print_cmd(philo, philo->info, FORK);
		
		pthread_mutex_lock(&philo->info->forks[philo->right_fork]);
		print_cmd(philo, philo->info, FORK);

		print_cmd(philo, philo->info, EAT);		

		pthread_mutex_unlock(&philo->info->forks[philo->left_fork]);
		pthread_mutex_unlock(&philo->info->forks[philo->right_fork]);

		print_cmd(philo, philo->info, SLEEP);

		print_cmd(philo, philo->info, THINK);

	}
	print_cmd(philo, philo->info, DIE);	
	philo->die = 1;
	return (0);
}

void	create_philo(t_philo *philo, t_info *info)
{
	int	i;

	i = 0;
	while (i < info->philo_num)
	{
		pthread_create(&philo[i].thread, NULL, (void *)do_philo, (t_philo *)&philo[i]);
		// usleep(50);
		i++;
	}
	while (1)
	{
		i = 0;
		while (i < info->philo_num)
		{
			if (philo[i].die == 1)
				printf("끝끝끝\n");
			i++;
		}
	}
	i = 0;
	while(i < info->philo_num)
	{
		pthread_join(philo[i].thread, NULL);
		i++;
	}
}

int main(int argc, char **argv)
{
	t_info	info;
	t_philo	*philo;
	
	if (argc != 5 && argc != 6)
		return (0);
	init_info(argc, argv, &info);
	philo = init_philo(&info);
	create_philo(philo, &info);
	return (0);
}