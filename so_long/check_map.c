/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_map.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yejinkim <yejinkim@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/29 19:28:36 by yejinkim          #+#    #+#             */
/*   Updated: 2022/12/29 22:49:27 by yejinkim         ###   ########seoul.kr  */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void check_map(t_vars *vars)
{
	if ( vars->plyaer_chk != 1 || vars->exit_chk != 1 || vars->collections < 1)
	{
		printf("MAP ERROR!!!\n");
		destroy_game(vars, 0);
	}
}

void check_line(t_vars *vars, char *line)
{
	
}