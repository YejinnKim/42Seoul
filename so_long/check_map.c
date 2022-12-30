/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_map.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yejinkim <yejinkim@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/29 19:28:36 by yejinkim          #+#    #+#             */
/*   Updated: 2022/12/30 19:32:04 by yejinkim         ###   ########seoul.kr  */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	check_map(t_vars *vars)
{
	if (vars->plyaer_chk != 1 || vars->exit_chk != 1 || vars->collections < 1)
		destroy_game(vars, 2);
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
		if (i == 0 || i == vars->height - 1)
		{
			if (line[len] != '1' && len != vars->width)
				return (0);
		}
		else
		{
			if ((len == 0 || len == vars->width - 1) && line[len] != '1')
				return (0);
		}
		len++;
	}
	if (i == vars->height - 1)
		len++;
	if (len != vars->width + 1)
		return (0);
	return (1);
}
