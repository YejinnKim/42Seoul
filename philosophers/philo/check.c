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
	if ((philo->last_eat + info->die_time <= get_time(info->start_time)))
	{
		if (philo->eat_num == info->must_eat)
			return (-1);
        info->timestamp = get_time(info->start_time);
		print_cmd(DIE, philo, philo->info);
        info->end = 1;
        return (1);
    }
    return (0);
}

int    check_eat(t_philo *philo, t_info *info)
{
    int i;
    
    i = 0;
	while (i < info->philo_num)
	{
		if (philo[i].eat_num != info->must_eat)
			break ;
		i++;
	}
	if (i == info->philo_num)
		return (1);
    return (0);
}

void	check_philo(t_philo *philo, t_info *info)
{
	int	i;
    int die;

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