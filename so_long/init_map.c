/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_map.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yejinkim <yejinkim@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/28 18:26:41 by yejinkim          #+#    #+#             */
/*   Updated: 2022/12/30 19:38:21 by yejinkim         ###   ########seoul.kr  */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	set_vars(t_vars *vars)
{
	vars->collections = 0;
	vars->plyaer_chk = 0;
	vars->exit_chk = 0;
	vars->movements = 0;
}

void	set_image(t_vars *vars)
{
	int	img_width;
	int	img_height;

	vars->cat = mlx_xpm_file_to_image(vars->mlx, \
		"./images/cat.xpm", &img_width, &img_height);
	vars->land = mlx_xpm_file_to_image(vars->mlx, \
		"./images/land.xpm", &img_width, &img_height);
	vars->wall = mlx_xpm_file_to_image(vars->mlx, \
		"./images/wall.xpm", &img_width, &img_height);
	vars->exit = mlx_xpm_file_to_image(vars->mlx, \
		"./images/exit.xpm", &img_width, &img_height);
	vars->mouse = mlx_xpm_file_to_image(vars->mlx, \
		"./images/mouse.xpm", &img_width, &img_height);
}

void	put_img(t_vars *vars)
{
	int	i;
	int	j;

	j = 0;
	set_vars(vars);
	while (j < vars->height)
	{
		i = 0;
		while (i < vars->width)
		{
			mlx_put_image_to_window(vars->mlx, vars->win, vars->land, \
				i * 64, j * 64);
			if (vars->map[j][i] == '1')
				mlx_put_image_to_window(vars->mlx, vars->win, vars->wall, \
					i * 64, j * 64);
			else if (vars->map[j][i] == 'C')
			{
				mlx_put_image_to_window(vars->mlx, vars->win, vars->mouse, \
					i * 64, j * 64);
				vars->collections++;
			}
			else if (vars->map[j][i] == 'E')
			{
				mlx_put_image_to_window(vars->mlx, vars->win, vars->exit, \
					i * 64, j * 64);
				vars->exit_chk++;
			}
			else if (vars->map[j][i] == 'P')
			{
				mlx_put_image_to_window(vars->mlx, vars->win, vars->cat, \
					i * 64, j * 64);
				vars->player_x = i;
				vars->player_y = j;
				vars->plyaer_chk++;
				vars->map[j][i] = '0';
			}
			i++;
		}
		j++;
	}
}

void	malloc_map(char *filename, t_vars *vars)
{
	int		i;
	int		fd;
	char	*line;

	fd = open(filename, O_RDONLY);
	i = 0;
	vars->map = malloc(sizeof(char *) * vars->height);
	if (!vars->map)
		destroy_game(vars, 0);
	while (i < vars->height)
	{
		vars->map[i] = malloc(sizeof(char) * vars->width + 1);
		if (!vars->map[i])
			destroy_game(vars, 0);
		line = get_next_line(fd);
		if (check_line(line, i, vars) == 0)
			destroy_game(vars, 2);
		vars->map[i] = line;
		i++;
	}
	close(fd);
}

void	open_map(char *filename, t_vars *vars)
{
	int		fd;
	char	*line;
	int		width;
	int		height;

	width = 0;
	height = 0;
	fd = open(filename, O_RDONLY);
	line = get_next_line(fd);
	while (line[width])
		width++;
	while (line)
	{
		line = get_next_line(fd);
		height++;
	}
	vars->height = height;
	vars->width = width - 1;
	malloc_map(filename, vars);
	close(fd);
}
