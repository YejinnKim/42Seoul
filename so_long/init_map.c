/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yejinkim <yejinkim@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/28 18:26:41 by yejinkim          #+#    #+#             */
/*   Updated: 2022/12/28 22:41:35 by yejinkim         ###   ########seoul.kr  */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void set_image(t_vars *vars)
{
	int img_width;
	int img_height;
	
	vars->cat = mlx_xpm_file_to_image(vars->mlx, "./images/cat.xpm", &img_width, &img_height);
	vars->land = mlx_xpm_file_to_image(vars->mlx, "./images/land.xpm", &img_width, &img_height);
	vars->wall = mlx_xpm_file_to_image(vars->mlx, "./images/wall.xpm", &img_width, &img_height);
	vars->exit = mlx_xpm_file_to_image(vars->mlx, "./images/exit.xpm", &img_width, &img_height);
	vars->mouse = mlx_xpm_file_to_image(vars->mlx, "./images/mouse.xpm", &img_width, &img_height);
}

void put_img(t_vars *vars)
{
	int	i;
	int	j;
	int	cnt;

	j = 0;
	cnt = 0;
	while (j<vars->height)
	{
		i = 0;
		while (i<vars->width)
		{
			mlx_put_image_to_window(vars->mlx, vars->win, vars->land, i * 64, j * 64);
			if (vars->map[j][i] == '1')
				mlx_put_image_to_window(vars->mlx, vars->win, vars->wall, i * 64, j * 64);
			else if (vars->map[j][i] == 'C')
			{
				mlx_put_image_to_window(vars->mlx, vars->win, vars->mouse, i * 64, j * 64);
				cnt++;
			}
			else if (vars->map[j][i] == 'E')
				mlx_put_image_to_window(vars->mlx, vars->win, vars->exit, i * 64, j * 64);
			else if (vars->map[j][i] == 'P')
			{
				mlx_put_image_to_window(vars->mlx, vars->win, vars->cat, i * 64, j * 64);
				vars->player_x = i;
				vars->player_y = j;
				vars->movements = 0;
				vars->map[j][i] = '0';
			}
			i++;
		}
		j++;
	}
	vars->collections = cnt;
}

void malloc_map(t_vars *vars)
{
	int i;
	int fd;

	fd = open("./map.ber", O_RDONLY);
	i=0;
	vars->map = malloc(sizeof(char *) * vars->height);
	while (i < vars->height)
	{
		vars->map[i] = malloc(sizeof(char) * vars->width + 1);
		vars->map[i] = get_next_line(fd);
		i++;
	}
	close(fd);
}

void open_map(char *filename, t_vars *vars)
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
	vars->width = width-1;
	malloc_map(vars);
	close(fd);
}