/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex_bonus.h                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yejinkim <yejinkim@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/21 21:24:14 by yejinkim          #+#    #+#             */
/*   Updated: 2023/02/27 22:43:41 by yejinkim         ###   ########seoul.kr  */
/*                                                                            */
/* ************************************************************************** */

#ifndef PIPEX_BONUS_H
# define PIPEX_BONUS_H

# include <unistd.h>
# include <stdlib.h>
# include <fcntl.h>
# include <stdio.h>
# include "../libft/libft.h"

typedef struct s_args
{
	int		infile;
	int		outfile;
	char	**cmd;
	char	*cmd_path;
	char	**path;
	char	**envp;
	int		argc;
	int		heredoc;
}	t_args;

void	pipex(t_args *args);
void	pipex_mult(t_args *args, char **argv);
void	free_cmd(char **cmd, char *cmd_path);
void	print_error(char *str, int errno);
void	parse_args(t_args *args, int argc, char **argv, char **envp);
char	*find_path(t_args *args, char **cmd);
char	**pars_envp(char **envp);
char	*get_next_line(int fd);

#endif