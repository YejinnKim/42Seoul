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

void	destroy_philo(t_philo *philo, t_info *info)
{
	dsty_mtx(info->philo_num, info->forks, &info->time, &info->check);
	free(philo);
}

long long	get_time(long long value)
{
	struct timeval	tv;
	long long		time;

	gettimeofday(&tv, NULL);
	time = (tv.tv_sec * 1000000 + tv.tv_usec) / 1000;
	if (value == START)
		return (time);
	else
		return (time - value);
}

void	usleep_time(t_info *info, int time)
{
	long long	timestamp;

	pthread_mutex_lock(&info->time);
	timestamp = info->timestamp;
	pthread_mutex_unlock(&info->time);
	while (time >= get_time(info->start_time) - timestamp)
		usleep(10);
	pthread_mutex_lock(&info->time);
	info->timestamp = get_time(info->start_time) - 1;
	pthread_mutex_unlock(&info->time);
}

void	create_philo(t_philo *philo, t_info *info)
{
	int	i;

	i = -1;
	while (++i < info->philo_num)
		pthread_create(&philo[i].thread, NULL, \
			(void *)do_philo, (t_philo *)&philo[i]);
	check_philo(philo, info);
	i = -1;
	while (++i < info->philo_num)
		pthread_join(philo[i].thread, NULL);
}

int	main(int argc, char **argv)
{
	t_info	info;
	t_philo	*philo;

	if (argc != 5 && argc != 6)
		return (0);
	if (!init_info(argc, argv, &info))
		return (0);
	philo = init_philo(&info);
	if (!philo)
		return (0);
	create_philo(philo, &info);
	destroy_philo(philo, &info);
	return (0);
}
