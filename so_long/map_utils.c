/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_utils.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yejinkim <yejinkim@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/28 18:26:41 by yejinkim          #+#    #+#             */
/*   Updated: 2023/01/05 18:25:47 by yejinkim         ###   ########seoul.kr  */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	set_image(t_vars *vars)
{
	int	img_width;
	int	img_height;

	vars->cat = mlx_xpm_file_to_image(vars->mlx, \
		"./textures/cat.xpm", &img_width, &img_height);
	vars->land = mlx_xpm_file_to_image(vars->mlx, \
		"./textures/land.xpm", &img_width, &img_height);
	vars->wall = mlx_xpm_file_to_image(vars->mlx, \
		"./textures/wall.xpm", &img_width, &img_height);
	vars->exit = mlx_xpm_file_to_image(vars->mlx, \
		"./textures/exit.xpm", &img_width, &img_height);
	vars->mouse = mlx_xpm_file_to_image(vars->mlx, \
		"./textures/mouse.xpm", &img_width, &img_height);
	put_image(vars);
}

void	put_image(t_vars *vars)
{
	int	i;
	int	j;

	j = -1;
	while (++j < vars->h)
	{
		i = -1;
		while (++i < vars->w)
		{
			mlx_put_image_to_window(vars->mlx, vars->win, vars->land, \
				i * 64, j * 64);
			if (vars->map[j][i] == '1')
				mlx_put_image_to_window(vars->mlx, vars->win, vars->wall, \
					i * 64, j * 64);
			else if (vars->map[j][i] == 'C')
				mlx_put_image_to_window(vars->mlx, vars->win, vars->mouse, \
					i * 64, j * 64);
			else if (vars->map[j][i] == 'E')
				mlx_put_image_to_window(vars->mlx, vars->win, vars->exit, \
					i * 64, j * 64);
			else if (vars->map[j][i] == 'P')
				mlx_put_image_to_window(vars->mlx, vars->win, vars->cat, \
					i * 64, j * 64);
		}
	}
}

void	free_map(t_vars *vars, char **map)
{
	int	i;

	i = -1;
	while (++i < vars->h && map[i])
		free(map[i]);
	free(map);
}

void	malloc_map(char *filename, t_vars *vars)
{
	int		i;
	int		fd;
	char	*line;

	fd = open(filename, O_RDONLY);
	i = 0;
	vars->map = malloc(sizeof(char *) * vars->h);
	if (!vars->map)
		destroy_game(vars, "MALLOC ERROR!!!");
	while (i < vars->h)
	{
		line = get_next_line(fd);
		vars->map[i] = line;
		if (check_line(line, i, vars) == 0)
		{
			vars->h = i;
			destroy_game(vars, "MAP ERROR!!!");
		}
		i++;
	}
	close(fd);
	check_map(vars);
	vars->m_chk = 1;
}

void	open_map(char *filename, t_vars *vars)
{
	int		fd;
	char	*line;

	set_vars(vars);
	fd = open(filename, O_RDONLY);
	if (fd < 0)
		destroy_game(vars, "MAP ERROR!!!");
	line = get_next_line(fd);
	if (!line)
		destroy_game(vars, "MAP ERROR!!!");
	while (line[vars->w + 1])
		vars->w++;
	free(line);
	while (line)
	{
		line = get_next_line(fd);
		free(line);
		vars->h++;
	}
	close(fd);
	malloc_map(filename, vars);
}
