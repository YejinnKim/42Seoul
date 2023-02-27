/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex_bonus.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yejinkim <yejinkim@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/21 21:22:32 by yejinkim          #+#    #+#             */
/*   Updated: 2023/02/27 22:49:45 by yejinkim         ###   ########seoul.kr  */
/*                                                                            */
/* ************************************************************************** */

#include "pipex_bonus.h"

void	free_cmd(char **cmd, char *cmd_path)
{
	int	i;

	i = 0;
	while (cmd[i])
		free(cmd[i++]);
	free(cmd);
	free(cmd_path);
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

	pipe(fds);
	pid = fork();
	if (pid == -1)
		print_error("fork error", 1);
	else if (pid == 0)
	{
		close(fds[0]);
		dup2_close(fds[1], STDOUT_FILENO);
		if (execve(args->cmd_path, args->cmd, args->envp) == -1)
			print_error("command not found", 127);
	}
	else
	{
		close(fds[1]);
		dup2_close(fds[0], STDIN_FILENO);
	}
}

void	pipex_mult(t_args *args, char **argv)
{
	int	i;

	i = 0;
	if (args->heredoc)
		i++;
	dup2_close(args->infile, STDIN_FILENO);
	while (i < args->argc - 3)
	{
		args->cmd = ft_split(argv[i + 2], ' ');
		args->cmd_path = find_path(args, args->cmd);
		if (i == args->argc - 4)
			break ;
		pipex(args);
		free_cmd(args->cmd, args->cmd_path);
		i++;
	}
	if (args->heredoc)
		unlink(".heredoc");
	dup2_close(args->outfile, STDOUT_FILENO);
	if (execve(args->cmd_path, args->cmd, args->envp) == -1)
		print_error("command not found", 127);
}

int	main(int argc, char **argv, char **envp)
{
	t_args	args;

	if (argc < 5)
		print_error("argc error", 1);
	if (ft_strncmp("here_doc", argv[1], ft_strlen(argv[1])) == 0)
		args.heredoc = 1;
	parse_args(&args, argc, argv, envp);
	pipex_mult(&args, argv);
	return (0);
}
