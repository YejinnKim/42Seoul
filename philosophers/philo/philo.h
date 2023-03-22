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

# define START -1

typedef struct s_info
{
	int				philo_num;
	int				die_time;
	int				eat_time;
	int				sleep_time;
	int				must_eat;
	int				end;
	long long		start_time;
	long long		timestamp;
	pthread_mutex_t	*forks;
	pthread_mutex_t	time;
	pthread_mutex_t	check;
}	t_info;

typedef struct s_philo
{
	int			num;
	int			right_fork;
	int			left_fork;
	int			eat_num;
	long long	last_eat;
	t_info		*info;
	pthread_t	thread;
}	t_philo;

void		create_philo(t_philo *philo, t_info *info);
long long	usleep_time(t_info *info, int time);
long long	get_time(long long value);
void		destroy_philo(t_philo *philo, t_info *info);
int			init_info(int argc, char **argv, t_info *info);
int			init_mutex(t_info *info);
t_philo		*init_philo(t_info *info);
int			dsty_mtx(int n, pthread_mutex_t *f, \
						pthread_mutex_t *t, pthread_mutex_t *c);
int			ft_atoi(const char *str);
void		*do_philo(t_philo *philo);
void		thinking(t_philo *philo, t_info *info);
void		sleeping(t_philo *philo, t_info *info);
void		eating(t_philo *philo, t_info *info);
void		print_cmd(int type, t_philo *philo, t_info *info);
void		*do_one_philo(t_philo *philo);
void		check_philo(t_philo *philo, t_info *info);
int			check_eat(t_philo *philo, t_info *info);
int			check_die(t_philo *philo, t_info *info);

#endif