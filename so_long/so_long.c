/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yejinkim <yejinkim@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/22 15:00:58 by yejinkim          #+#    #+#             */
/*   Updated: 2022/12/28 17:31:42 by yejinkim         ###   ########seoul.kr  */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"
#include "get_next_line.h"
#include <stdio.h>
#include <fcntl.h>

void malloc_map(t_vars *vars)
{
	int i;
	int fd;

	fd = open("./map.ber", O_RDONLY);
	i=0;
	vars->map = malloc(sizeof(char *) * vars->h);
	while (i < vars->h)
	{
		vars->map[i] = malloc(sizeof(char) * vars->w + 1);
		vars->map[i] = get_next_line(fd);
		printf("%s", vars->map[i]);
		i++;
	}
	printf("\n");
	close(fd);
}

void open_map(t_vars *vars)
{
	int		fd;
	char	*line="init";
	int h=0;
	int w=0;

	fd = open("./map.ber", O_RDONLY);
	line = get_next_line(fd);
	while (line[w])
		w++;
	while (line)
	{
		line = get_next_line(fd);
		h++;
	}
	vars->h = h;
	vars->w = w-1;
	malloc_map(vars);
	close(fd);
}

void put_img(t_vars *vars)
{
	int img_width;
	int img_height;

	void *cat = mlx_xpm_file_to_image(vars->mlx, "./images/cat.xpm", &img_width, &img_height);
	void *land = mlx_xpm_file_to_image(vars->mlx, "./images/land.xpm", &img_width, &img_height);
	void *wall = mlx_xpm_file_to_image(vars->mlx, "./images/wall.xpm", &img_width, &img_height);
	void *exit = mlx_xpm_file_to_image(vars->mlx, "./images/exit.xpm", &img_width, &img_height);
	void *mouse = mlx_xpm_file_to_image(vars->mlx, "./images/mouse.xpm", &img_width, &img_height);

	int i;
	int j;

	i=0;
	while (i<vars->w)
	{
		j=0;
		while (j<vars->h)
		{
			mlx_put_image_to_window(vars->mlx, vars->win, land, i*64, j*64);
			printf("%c", vars->map[j][i]);
			j++;
		}
		printf("\n");
		i++;
	}
		
	mlx_put_image_to_window(vars->mlx, vars->win, cat, 0, 0);
	mlx_put_image_to_window(vars->mlx, vars->win, mouse, 100, 0);
	mlx_put_image_to_window(vars->mlx, vars->win, wall, 200, 0);
	mlx_put_image_to_window(vars->mlx, vars->win, wall, 200, 64);
	mlx_put_image_to_window(vars->mlx, vars->win, wall, 264, 64);
	mlx_put_image_to_window(vars->mlx, vars->win, exit, 200, 128);
}

void player_move(t_vars *vars, int x, int y)
{

}

int	key_hook(int keycode, t_vars *vars)
{
	if (keycode == KEY_W)
		player_move(vars, 0, -1);
	else if (keycode == KEY_A)
		player_move(vars, -1, 0);
	else if (keycode == KEY_S)
		player_move(vars, 0, 1);
	else if (keycode == KEY_D)
		player_move(vars, 0, 1);

	printf("%d\n", keycode);
	return (0);
}

int	main(void)
{

	t_vars	vars;

	open_map(&vars);

	vars.mlx = mlx_init();
	vars.win = mlx_new_window(vars.mlx, vars.w*64, vars.h*64, "so_long");
	
	mlx_key_hook(vars.win, key_hook, &vars);

	put_img(&vars);
	mlx_loop(&vars);


	return (0);
	// cc -lmlx -framework OpenGL -framework AppKit *.c
}