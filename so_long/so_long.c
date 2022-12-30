/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yejinkim <yejinkim@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/22 15:00:58 by yejinkim          #+#    #+#             */
/*   Updated: 2022/12/30 19:35:08 by yejinkim         ###   ########seoul.kr  */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int	destroy_game(t_vars *vars, int flag)
{
	if (flag == 1)
		printf("GAME CLEAR!!!\n");
	else if (flag == 2)
	{
		printf("MAP ERROR!!!\n");
		exit(0);
		return (0);
	}
	mlx_destroy_window(vars->mlx, vars->win);
	exit(0);
	return (0);
}

void	player_move(t_vars *vars, int x, int y)
{
	if (vars->map[vars->player_y + y][vars->player_x + x] == '0' \
		|| vars->map[vars->player_y + y][vars->player_x + x] == 'C')
	{
		printf("movements %d\n", ++vars->movements);
		mlx_put_image_to_window(vars->mlx, vars->win, vars->land, \
			vars->player_x * 64, vars->player_y * 64);
		vars->player_x += x;
		vars->player_y += y;
		mlx_put_image_to_window(vars->mlx, vars->win, vars->cat, \
			vars->player_x * 64, vars->player_y * 64);
		if (vars->map[vars->player_y][vars->player_x] == 'C')
		{
			vars->collections--;
			vars->map[vars->player_y][vars->player_x] = '0';
		}
	}
	else if (vars->map[vars->player_y + y][vars->player_x + x] == 'E' \
		&& vars->collections == 0)
		destroy_game(vars, 1);
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
		destroy_game(vars, 0);
	return (0);
}

int	main(int argc, char **argv)
{
	t_vars	vars;

	if (argc != 2)
		destroy_game(&vars, 2);
	open_map(argv[1], &vars);
	vars.mlx = mlx_init();
	vars.win = mlx_new_window(vars.mlx, \
		vars.width * 64, vars.height * 64, "so_long");
	set_image(&vars);
	put_img(&vars);
	check_map(&vars);
	mlx_key_hook(vars.win, key_hook, &vars);
	mlx_hook(vars.win, X_EVENT_KEY_EXIT, 0, destroy_game, &vars);
	mlx_loop(&vars);
	return (0);
	// cc -lmlx -framework OpenGL -framework AppKit *.c ./get_next_line/*.c
}
