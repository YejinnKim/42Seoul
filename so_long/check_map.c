/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_map.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yejinkim <yejinkim@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/29 19:28:36 by yejinkim          #+#    #+#             */
/*   Updated: 2023/01/05 18:22:39 by yejinkim         ###   ########seoul.kr  */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	set_vars(t_vars *vars)
{
	vars->w = 0;
	vars->h = 0;
	vars->c_chk = 0;
	vars->p_chk = 0;
	vars->e_chk = 0;
	vars->movements = 0;
}

int	check_path(t_vars *vars, char **map, int x, int y)
{
	if (map[y][x] != '1')
	{
		if (map[y][x] == 'C')
			vars->c_chk--;
		if (map[y][x] == 'E')
			vars->e_chk--;
		map[y][x] = '1';
		if (map[y][x + 1] != '1')
			check_path(vars, map, x + 1, y);
		if (map[y][x - 1] != '1')
			check_path(vars, map, x - 1, y);
		if (map[y - 1][x] != '1')
			check_path(vars, map, x, y - 1);
		if (map[y + 1][x] != '1')
			check_path(vars, map, x, y + 1);
		if (vars->c_chk == 0 && vars->e_chk == 0)
			return (1);
	}
	return (0);
}

void	check_game(t_vars *vars, char **map)
{
	int		i;
	int		j;

	i = -1;
	while (++i < vars->h)
	{
		j = -1;
		while (++j < vars->w)
		{
			if (vars->map[i][j] == 'C')
				vars->c_chk++;
			else if (vars->map[i][j] == 'E')
				vars->e_chk++;
			else if (vars->map[i][j] == 'P')
			{
				vars->x = j;
				vars->y = i;
				vars->p_chk++;
			}
			map[i][j] = vars->map[i][j];
		}
		map[i][j] = '\0';
	}
	vars->c = vars->c_chk;
}

void	check_map(t_vars *vars)
{
	char	**map;
	int		i;
	int		chk;

	i = 0;
	map = malloc(sizeof(char *) * vars->h);
	if (!map)
		destroy_game(vars, "MALLOC ERROR!!!");
	i = -1;
	while (++i < vars->h)
	{
		map[i] = malloc(sizeof(char) * vars->w + 1);
		if (!map[i])
			destroy_game(vars, "MALLOC ERROR!!!");
	}
	check_game(vars, map);
	if (vars->p_chk != 1 || vars->e_chk != 1 || vars->c < 1)
		destroy_game(vars, "MAP ERROR!!!");
	chk = check_path(vars, map, vars->x, vars->y);
	free_map(vars, map);
	if (chk == 0)
		destroy_game(vars, "MAP ERROR!!!");
}

int	check_line(char *line, int i, t_vars *vars)
{
	int	len;

	len = 0;
	while (line[len])
	{
		if (!(line[len] == '1' || line[len] == '0' || line[len] == 'P' || \
			line[len] == 'C' || line[len] == 'E' || line[len] == '\n'))
			return (0);
		if (i == 0 || i == vars->h - 1)
		{
			if (line[len] != '1' && len != vars->w)
				return (0);
		}
		else
		{
			if ((len == 0 || len == vars->w - 1) && line[len] != '1')
				return (0);
		}
		len++;
	}
	if (i == vars->h - 1)
		len++;
	if (len != vars->w + 1)
		return (0);
	return (1);
}
