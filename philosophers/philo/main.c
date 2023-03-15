/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yejinkim <yejinkim@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/13 16:53:34 by yejinkim          #+#    #+#             */
/*   Updated: 2023/03/15 21:57:29 by yejinkim         ###   ########seoul.kr  */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

void	print_cmd(t_philo *philo)
{
	pthread_mutex_lock(&philo->info->print);
	{
		printf("philo %d\n", philo->num);
		printf("\n");
	}
	pthread_mutex_unlock(&philo->info->print);
}

void	*do_philo(t_philo *philo)
{
	// while(1)
	{
		// fork 1
		// fork 2
		// eat
		// sleep
		// think
	}
	for (int i=0; i<3; i++)
		print_cmd(philo);
	
	return (0);
}

void	create_philo(t_philo *philo, t_info info)
{
	int	i;

	i = 0;
	while (i < info.philo_num)
	{
		// printf("---[%d]---\n", philo[i].num);
		pthread_create(&philo[i].thread, NULL, (void *)do_philo, (t_philo *)&philo[i]);
		i++;
	}
	i = 0;
	while(i < info.philo_num)
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
	philo = malloc(sizeof(t_philo) * info.philo_num);
	init_philo(philo, &info);
	create_philo(philo, info);
	return (0);
}