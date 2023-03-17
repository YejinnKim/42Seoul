/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yejinkim <yejinkim@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/13 16:55:29 by yejinkim          #+#    #+#             */
/*   Updated: 2023/03/17 22:46:09 by yejinkim         ###   ########seoul.kr  */
/*                                                                            */
/* ************************************************************************** */

#ifndef PHILO_H
# define PHILO_H

# include <pthread.h>
# include <stdio.h>
# include <sys/time.h>

# include <unistd.h>
# include <stdlib.h>

# define FORK	1
# define EAT	2
# define SLEEP	3
# define THINK	4
# define DIE	5

// 시간 변수 int -> long 변경하기

typedef struct	s_info
{
	int				philo_num;
	int				die_time;
	int				eat_time;
	int				sleep_time;
	int				must_eat;
	long			start_time;
	int				timestamp;
	int				end;
	pthread_mutex_t	*forks;
	pthread_mutex_t	print;
}	t_info;

typedef struct	s_philo
{
	int			num;
	int			die;
	int			right_fork;
	int			left_fork;
	int			eat_num;
	int			last_eat;
	t_info		*info;
	pthread_t	thread;
}	t_philo;

void	init_info(int argc, char **argv, t_info *info);
void	init_mutex(t_info *info);
t_philo	*init_philo(t_info *info);
long	get_time(void);

#endif