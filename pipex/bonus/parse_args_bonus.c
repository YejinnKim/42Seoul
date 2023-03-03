/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_args_bonus.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yejinkim <yejinkim@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/21 21:27:10 by yejinkim          #+#    #+#             */
/*   Updated: 2023/03/03 17:22:19 by yejinkim         ###   ########seoul.kr  */
/*                                                                            */
/* ************************************************************************** */

#include "pipex_bonus.h"

void	print_error(char *str, int errno)
{
	perror(str);
	exit(errno);
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
	if (!envp[i])
		print_error("path error", 1);
	path = ft_split(envp[i] + 5, ':');
	return (path);
}

char	*find_path(t_args *args, char **cmd)
{
	char	*tmp;
	char	*path;
	int		i;

	i = 0;
	while (args->path[i])
	{
		if (cmd[0][0] == '/')
			path = cmd[0];
		else
		{
			tmp = ft_strjoin(args->path[i], "/");
			path = ft_strjoin(tmp, cmd[0]);
			free(tmp);
		}
		if (access(path, X_OK) == 0)
			return (path);
		free(path);
		i++;
	}
	return (NULL);
}

void	read_heredoc(t_args *args, char *limiter)
{
	char	*line;

	args->infile = open(".heredoc", O_WRONLY | O_CREAT | O_APPEND, 0644);
	while (1)
	{
		write(1, "heredoc> ", 9);
		line = get_next_line(0);
		if (!line)
			print_error("gnl error", 1);
		if (ft_strncmp(limiter, line, ft_strlen(line) - 1) == 0)
			break ;
		write(args->infile, line, ft_strlen(line));
		free(line);
	}
	free(line);
	close(args->infile);
}

void	parse_args(t_args *args, int argc, char **argv, char **envp)
{
	args->envp = envp;
	args->path = pars_envp(envp);
	args->argc = argc;
	if (args->heredoc)
	{
		read_heredoc(args, argv[2]);
		args->infile = open(".heredoc", O_RDONLY);
		args->outfile = open(argv[argc - 1], O_RDWR | O_CREAT | O_APPEND, 0644);
	}
	else
	{
		args->infile = open(argv[1], O_RDONLY);
		args->outfile = open(argv[argc - 1], O_RDWR | O_CREAT | O_TRUNC, 0644);
	}
	if (args->infile < 0)
		perror("infile error");
	if (args->outfile < 0)
		print_error("outfile error", 1);
}
