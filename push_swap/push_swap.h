/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yejinkim <yejinkim@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/09 21:23:25 by yejinkim          #+#    #+#             */
/*   Updated: 2023/01/26 23:30:13 by yejinkim         ###   ########seoul.kr  */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include <stdlib.h>

# include <unistd.h>
# include <stdio.h>

typedef struct s_node
{
	int				value;
	struct s_node	*prev;
	struct s_node	*next;
}	t_node;

typedef struct s_stack
{
	t_node	*top;
	t_node	*bottom;
	int		size;
}	t_stack;

t_stack *init_stack(void);
t_node	*create_node(int value);
void	append_node(t_stack* stack, t_node* new_node) ;
void	remove_node(t_stack *stack);
void	swap_stack(t_stack *stack);
void	push_stack(t_stack *s1, t_stack *s2);
void	rotate_stack(t_stack *stack);
void	reverse_rotate_stack(t_stack *stack);
void	a_to_b(t_stack *a, t_stack *b);
void	b_to_a(t_stack *a, t_stack *b);
void	index_arr(t_stack *stack);

#endif