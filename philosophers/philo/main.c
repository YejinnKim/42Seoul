/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yejinkim <yejinkim@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/13 16:53:34 by yejinkim          #+#    #+#             */
/*   Updated: 2023/03/13 22:29:56 by yejinkim         ###   ########seoul.kr  */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"
// exit(), atoi() 수정하기

void	init_philo(t_philo **philo, t_info *info)
{
	int	i;
	int num;

	i = 0;
	num = info->philo_num;
	philo = malloc(sizeof(t_philo) * num);
	while (i < num)
	{
		philo[i]->num = i;
		philo[i]->right_fork = i;
		if (i + 1 == num)
			philo[i]->left_fork = 0;
		else
			philo[i]->left_fork = i + 1;
		philo[i]->eat_num = 0;
		philo[i]->end_time = 0; // 없어도 되나?
		philo[i]->info = info;
	}
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
	if (pthread_mutex_init(&(info->eating), NULL))
		exit(0);
	if (pthread_mutex_init(&(info->print), NULL))
		exit(0);
}

void	init_info(int argc, char **argv, t_info *info)
{
	info->philo_num = atoi(argv[1]);
	info->die_time = atoi(argv[2]);
	info->eat_time = atoi(argv[3]);
	info->sleep_time = atoi(argv[4]);
	if (argc == 5)
		info->must_eat = -1;
	else 
		info->must_eat = atoi(argv[5]);
	init_mutex(info);
}

int main(int argc, char **argv)
{
	t_info	info;
	t_philo	*philo;
	
	if (argc != 5 && argc != 6)
		return (0);
	init_info(argc, argv, &info);
	init_philo(&philo, &info);
	
	return (0);
}