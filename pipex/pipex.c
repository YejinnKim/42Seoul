/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yejinkim <yejinkim@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/13 15:55:51 by yejinkim          #+#    #+#             */
/*   Updated: 2023/02/13 21:41:59 by yejinkim         ###   ########seoul.kr  */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

void	exec_cmd(char **cmd, char **path, char **envp)
{
	char	*tmp;
	int		i;
	int		fd;

	i = 0;
	while (path[i])
	{
		tmp = ft_strjoin(path[i], "/");
		tmp = ft_strjoin(tmp, cmd[0]);
		fd = access(tmp, X_OK);
		if (fd == 0)
		{
			execve(tmp, cmd, envp);
		}
		free(tmp);
		close(fd);
		i++;
	}
}

char	**pars_envp(char **envp)
{
	char	**path;
	int		i;

	i = 0;
	while (envp[i])
	{
		if (ft_strncmp(envp[i], "PATH=", 5) == 0)
			break ;
		i++;
	}
	path = ft_split(envp[i] + 5, ':');
	return (path);
}

void	pipex(t_vars *vars)
{
	int	fds[2];
	pid_t	pid;

	pipe(fds);
	pid = fork();
	if (pid == -1)
	{
		printf("fork 실패\n");
		exit(1);
	}
	else if (pid == 0)
	{
		close(fds[0]);
		dup2(vars->infile, STDIN_FILENO);
		dup2(fds[1], STDOUT_FILENO);
		close(fds[1]);
		close(vars->infile);
		exec_cmd(vars->cmd1, vars->path, vars->envp);
	}
	else
	{
		close(fds[1]);
		dup2(fds[0], STDIN_FILENO);
		dup2(vars->outfile, STDOUT_FILENO);
		close(fds[0]);
		close(vars->outfile);
		waitpid(pid, NULL, 0);
		exec_cmd(vars->cmd2, vars->path, vars->envp);
	}
}

void	parse_arg(t_vars *vars, char **argv, char **envp)
{
	
	vars->infile = open(argv[1], O_RDONLY);
	vars->outfile = open(argv[4], O_RDWR | O_CREAT | O_TRUNC, 0644);
	// file open check
	vars->cmd1 = ft_split(argv[2], ' ');
	vars->cmd2 = ft_split(argv[3], ' ');

	vars->path = pars_envp(envp);
	
	vars->envp = envp;
}

int	main(int argc, char **argv, char **envp)
{
	t_vars	vars;
	
	if (argc != 5)
		return (0);
		
	
	parse_arg(&vars, argv, envp);
	
	pipex(&vars);
	
	return (0);
}