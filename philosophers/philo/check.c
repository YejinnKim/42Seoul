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

# include "philo.h"

int    check_die(t_philo *philo, t_info *info)
{
	int die_time;
	int start_time;

	//pthread_mutex_lock(&info->check);
	die_time = info->die_time;
	start_time = info->start_time;
	//pthread_mutex_unlock(&info->check);
	if ((philo->last_eat + die_time <= get_time(start_time)))
	{
		if (philo->eat_num == info->must_eat)
			return (-1);
		//pthread_mutex_lock(&info->time);
        info->timestamp = get_time(start_time);
		//pthread_mutex_unlock(&info->time);
		print_cmd(DIE, philo, philo->info);
		//pthread_mutex_lock(&info->check);
        info->end = 1;
		//pthread_mutex_unlock(&info->check);
        return (1);
    }
    return (0);
}

int    check_eat(t_philo *philo, int num, int eat)
{
    int i;
    
    i = 0;
	while (i < num)
	{
		if (philo[i].eat_num != eat)
			break ;
		i++;
	}
	if (i == num)
		return (1);
    return (0);
}

void	check_philo(t_philo *philo, t_info *info)
{
	int	i;
    int die;
	int num;
	int eat;

	//pthread_mutex_lock(&info->check);
	num = info->philo_num;
	eat = info->must_eat;
	//pthread_mutex_unlock(&info->check);
	while (!info->end) 
	{
		i = 0;
		while (i < num)
		{
            die = check_die(&philo[i], info);
            if (die)
                return ;
            else if (die == -1)
                continue ;
			if (check_eat(philo, num, eat))
            	return ;
			i++;
		}
	}
}