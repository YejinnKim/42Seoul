/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yejinkim <yejinkim@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/13 16:55:29 by yejinkim          #+#    #+#             */
/*   Updated: 2023/03/13 22:26:31 by yejinkim         ###   ########seoul.kr  */
/*                                                                            */
/* ************************************************************************** */

#ifndef PHILO_H
# define PHILO_H

# include <pthread.h>
# include <stdio.h>

# include <stdlib.h>

typedef struct	s_info
{
	int				philo_num;
	int				die_time;
	int				eat_time;
	int				sleep_time;
	int				must_eat;
	int				start_time;
	pthread_mutex_t	*forks;
	pthread_mutex_t eating;
	pthread_mutex_t	print;
}	t_info;

typedef struct	s_philo
{
	int		num;
	int		right_fork;
	int		left_fork;
	int		eat_num;
	int		end_time;
	t_info	*info;
}	t_philo;

#endif