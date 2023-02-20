/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yejinkim <yejinkim@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/13 15:55:51 by yejinkim          #+#    #+#             */
/*   Updated: 2023/02/20 19:28:08 by yejinkim         ###   ########seoul.kr  */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

void	print_error(char *str)
{
	ft_putstr_fd(str, 2);
	exit(1);
}

void	connet_pipe(int in, int out)
{
	dup2(in, STDIN_FILENO);
	dup2(out, STDOUT_FILENO);
	close(in);
	close(out);
}

void	pipex(t_args *args)
{
	int		fds[2];
	pid_t	pid;
	int		status;

	pipe(fds);
	pid = fork();
	if (pid == -1)
		perror("fork error");
	else if (pid == 0)
	{
		close(fds[0]);
		connet_pipe(args->infile, fds[1]);
		if (execve(args->cmd1_path, args->cmd1, args->envp) == -1)
		{
			perror("command not found");
			exit(127);
		}
	}
	else
	{
		close(fds[1]);
		connet_pipe(fds[0], args->outfile);
		waitpid(pid, &status, WNOHANG);
		if (execve(args->cmd2_path, args->cmd2, args->envp) == -1)
		{
			perror("command not found");
			exit(127);
		}
	}
}

int	main(int argc, char **argv, char **envp)
{
	t_args	args;

	if (argc != 5)
		print_error("argc error\n");
	parse_args(&args, argv, envp);
	pipex(&args);
	return (0);
}
