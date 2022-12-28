/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yejinkim <yejinkim@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/27 17:06:06 by yejinkim          #+#    #+#             */
/*   Updated: 2022/12/28 22:22:49 by yejinkim         ###   ########seoul.kr  */
/*                                                                            */
/* ************************************************************************** */

#ifndef SO_LONG_H
# define SO_LONG_H

#include <mlx.h>
#include <stdlib.h>
#include <fcntl.h>
#include <stdio.h>
#include "get_next_line/get_next_line.h"

# define KEY_ESC	53
# define KEY_W		13
# define KEY_A		0
# define KEY_S		1
# define KEY_D		2

typedef struct	s_vars {
	void	*mlx;
	void	*win;

	char	**map;
	int		height;
	int		width;
	int		player_x; 
	int		player_y;

	void	*cat;
	void	*land;
	void	*wall;
	void	*exit;
	void	*mouse;

	int		collections;
	int		movements;
}	t_vars;

void open_map(char *filename, t_vars *vars);
void malloc_map(t_vars *vars);
void put_img(t_vars *vars);
void set_image(t_vars *vars);

char	*get_next_line(int fd);

#endif