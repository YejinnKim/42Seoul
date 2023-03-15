/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yejinkim <yejinkim@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/13 16:55:29 by yejinkim          #+#    #+#             */
/*   Updated: 2023/03/15 21:56:24 by yejinkim         ###   ########seoul.kr  */
/*                                                                            */
/* ************************************************************************** */

#ifndef PHILO_H
# define PHILO_H

# include <pthread.h>
# include <stdio.h>

# include <unistd.h>
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
	pthread_mutex_t eating; // 고민!
	pthread_mutex_t	print;
}	t_info;

typedef struct	s_philo
{
	int			num;
	int			die;
	int			right_fork;
	int			left_fork;
	int			eat_num;
	int			end_time;
	t_info		*info;
	pthread_t	thread;
}	t_philo;

void	init_info(int argc, char **argv, t_info *info);
void	init_mutex(t_info *info);
void	init_philo(t_philo *philo, t_info *info);

#endif