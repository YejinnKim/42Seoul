/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_args_bonus.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yejinkim <yejinkim@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/21 21:27:10 by yejinkim          #+#    #+#             */
/*   Updated: 2023/02/23 22:37:36 by yejinkim         ###   ########seoul.kr  */
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
	args->argc = argc;
	if (args->heredoc)
	{
		args->infile = open("./infile", O_RDONLY);
		
		// 1. O_WRONLY, O_CREAT, O_TRUNC 모드 및 0644 권한으로 임시 파일 생성
		// 2. limiter가 나오기 전까지 임시 파일에 기록
		// 3. limiter를 만나면 기록을 중지하고 임시 파일을 닫기
		// 4. O_RDONLY 모드로 임시 파일 다시 열기
		// 5. dup2를 통해 표준 입력을 임시 파일로 돌리기
		// 6. 임시 파일 닫기
		args->outfile = open(argv[argc - 1], O_RDWR | O_CREAT | O_APPEND, 0644);		
	}
	else
	{
		args->infile = open(argv[1], O_RDONLY);
		args->outfile = open(argv[argc - 1], O_RDWR | O_CREAT | O_TRUNC, 0644);		
	}
	check_files(args);
}
