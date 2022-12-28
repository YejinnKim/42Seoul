/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yejinkim <yejinkim@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/22 15:00:58 by yejinkim          #+#    #+#             */
/*   Updated: 2022/12/28 23:22:40 by yejinkim         ###   ########seoul.kr  */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void exit_game(t_vars *vars)
{
	printf("GAME CLEAR!!!\n");
	mlx_destroy_window(vars->mlx, vars->win);
	exit(0);
}

void player_move(t_vars *vars, int x, int y)
{
	if (vars->map[vars->player_y + y][vars->player_x + x] == '0' || vars->map[vars->player_y + y][vars->player_x + x] == 'C')
	{
		printf("movements %d\n", ++vars->movements);
		mlx_put_image_to_window(vars->mlx, vars->win, vars->land, vars->player_x * 64, vars->player_y * 64);
		vars->player_x += x;
		vars->player_y += y;
		mlx_put_image_to_window(vars->mlx, vars->win, vars->cat, vars->player_x * 64, vars->player_y * 64);
		if (vars->map[vars->player_y][vars->player_x] == 'C')
			vars->collections--;
	}
	else if (vars->map[vars->player_y + y][vars->player_x + x] == 'E' && vars->collections == 0)
		exit_game(vars);
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
		player_move(vars, 1, 0);
	else if (keycode == KEY_ESC)
		mlx_destroy_window(vars->mlx, vars->win);
	return (0);
}

int	main(int argc, char **argv)
{
	t_vars	vars;

	if (argc != 2)
		return (0);
	open_map(argv[1], &vars);

	vars.mlx = mlx_init();
	vars.win = mlx_new_window(vars.mlx, vars.width * 64, vars.height * 64, "so_long");
	
	set_image(&vars);
	mlx_key_hook(vars.win, key_hook, &vars);

	put_img(&vars);
	mlx_loop(&vars);

	return (0);
	// cc -lmlx -framework OpenGL -framework AppKit *.c ./get_next_line/*.c
}