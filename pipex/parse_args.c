/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_args.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yejinkim <yejinkim@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/14 16:00:38 by yejinkim          #+#    #+#             */
/*   Updated: 2023/03/03 17:21:44 by yejinkim         ###   ########seoul.kr  */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

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

void	check_files(t_args *args)
{
	if (args->infile < 0)
		perror("infile error");
	if (args->outfile < 0)
		print_error("outfile error", 1);
}

void	parse_args(t_args *args, char **argv, char **envp)
{
	args->envp = envp;
	args->path = pars_envp(envp);
	args->infile = open(argv[1], O_RDONLY);
	args->outfile = open(argv[4], O_RDWR | O_CREAT | O_TRUNC, 0644);
	args->cmd1 = ft_split(argv[2], ' ');
	args->cmd2 = ft_split(argv[3], ' ');
	args->cmd1_path = find_path(args, args->cmd1);
	args->cmd2_path = find_path(args, args->cmd2);
	check_files(args);
}
