/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_args_bonus.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yejinkim <yejinkim@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/21 21:27:10 by yejinkim          #+#    #+#             */
/*   Updated: 2023/02/22 21:07:33 by yejinkim         ###   ########seoul.kr  */
/*                                                                            */
/* ************************************************************************** */

#include "pipex_bonus.h"

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

void	parse_args(t_args *args, int argc, char **argv, char **envp)
{
	args->envp = envp;
	args->path = pars_envp(envp);
	args->infile = open(argv[1], O_RDONLY);
	args->outfile = open(argv[argc - 1], O_RDWR | O_CREAT | O_TRUNC, 0644);
	args->argc = argc;
	check_files(args);
}
