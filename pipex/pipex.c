/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yejinkim <yejinkim@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/13 15:55:51 by yejinkim          #+#    #+#             */
/*   Updated: 2023/03/03 18:32:37 by yejinkim         ###   ########seoul.kr  */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

void	print_error(char *str, int errno)
{
	perror(str);
	exit(errno);
}

void	dup2_close(int fd1, int fd2)
{
	dup2(fd1, fd2);
	close(fd1);
}

void	pipex(t_args *args)
{
	int		fds[2];
	pid_t	pid;

	dup2_close(args->infile, STDIN_FILENO);
	pipe(fds);
	pid = fork();
	if (pid == -1)
		print_error("fork error", 1);
	else if (pid == 0)
	{
		close(fds[0]);
		dup2_close(fds[1], STDOUT_FILENO);
		if (execve(args->cmd1_path, args->cmd1, args->envp) == -1)
			print_error("command not found", 127);
	}
	else
	{
		close(fds[1]);
		dup2_close(fds[0], STDIN_FILENO);
	}
	dup2_close(args->outfile, STDOUT_FILENO);
	if (execve(args->cmd2_path, args->cmd2, args->envp) == -1)
		print_error("command not found", 127);
	if (args->infile < 0)
		exit(1);
}

int	main(int argc, char **argv, char **envp)
{
	t_args	args;

	if (argc != 5)
		print_error("argc error", 1);
	parse_args(&args, argv, envp);
	pipex(&args);
	return (0);
}
