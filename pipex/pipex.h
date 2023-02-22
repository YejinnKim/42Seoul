/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yejinkim <yejinkim@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/13 18:00:53 by yejinkim          #+#    #+#             */
/*   Updated: 2023/02/22 15:34:32 by yejinkim         ###   ########seoul.kr  */
/*                                                                            */
/* ************************************************************************** */

#ifndef PIPEX_H
# define PIPEX_H

# include <unistd.h>
# include <stdlib.h>
# include <fcntl.h>
# include <stdio.h>
# include "libft/libft.h"

typedef struct s_args
{
	int		infile;
	int		outfile;
	char	**cmd1;
	char	**cmd2;
	char	*cmd1_path;
	char	*cmd2_path;
	char	**path;
	char	**envp;
}	t_args;

void	pipex(t_args *args);
void	connet_pipe(int in, int out);
void	print_error(char *str, int errno);
void	parse_args(t_args *args, char **argv, char **envp);
void	check_args(t_args *args);
char	*find_path(t_args *args, char **cmd);
char	**pars_envp(char **envp);

#endif