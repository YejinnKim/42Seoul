/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yejinkim <yejinkim@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/22 15:00:58 by yejinkim          #+#    #+#             */
/*   Updated: 2023/01/04 23:31:13 by yejinkim         ###   ########seoul.kr  */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int	destroy_game(t_vars *vars, char *str)
{
	ft_printf("%s\n", str);
	if (vars->mlx && vars->win)
		mlx_destroy_window(vars->mlx, vars->win);
	exit(0);
	return (0);
}

void	player_move(t_vars *vars, int x, int y)
{
	if (vars->map[vars->y + y][vars->x + x] == 'E' && vars->c == 0)
		destroy_game(vars, "GAME CLEAR!!!");
	if (vars->map[vars->y + y][vars->x + x] != '1')
	{
		ft_printf("movements %d\n", ++vars->movements);
		mlx_put_image_to_window(vars->mlx, vars->win, vars->land, \
			vars->x * 64, vars->y * 64);
		if (vars->map[vars->y][vars->x] == 'E')
			mlx_put_image_to_window(vars->mlx, vars->win, vars->exit, \
				vars->x * 64, vars->y * 64);
		vars->x += x;
		vars->y += y;
		mlx_put_image_to_window(vars->mlx, vars->win, vars->cat, \
			vars->x * 64, vars->y * 64);
		if (vars->map[vars->y][vars->x] == 'C')
		{
			vars->c--;
			vars->map[vars->y][vars->x] = '0';
		}
	}
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
		destroy_game(vars, "EXIT");
	return (0);
}

int	main(int argc, char **argv)
{
	t_vars	vars;

	if (argc != 2)
		destroy_game(&vars, "MAP ERROR!!!");
	open_map(argv[1], &vars);
	vars.mlx = mlx_init();
	vars.win = mlx_new_window(vars.mlx, vars.w * 64, vars.h * 64, "SO_LONG");
	set_image(&vars);
	mlx_key_hook(vars.win, key_hook, &vars);
	mlx_hook(vars.win, X_EVENT_KEY_EXIT, 0, destroy_game, &vars);
	mlx_loop(&vars);
	return (0);
}
