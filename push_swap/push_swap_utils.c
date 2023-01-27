/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap_utils.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yejinkim <yejinkim@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/16 16:23:50 by yejinkim          #+#    #+#             */
/*   Updated: 2023/01/27 20:51:03 by yejinkim         ###   ########seoul.kr  */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	swap_stack(t_stack *stack, char *str)
{
	t_node	*top;
	t_node	*tmp;

	if (stack->size < 2)
		return ;
	top = stack->top;
	tmp = stack->top->next;
	top->next = tmp->next;
	top->prev = tmp;
	tmp->next = top;
	tmp->prev = NULL;
	tmp->next->prev = top;
	stack->top = tmp;
	write(1, str, 3);
}

void	push_stack(t_stack *s1, t_stack *s2, char *str)
{
	int		tmp;
	t_node	*node;

	if (s1->size < 1)
		return ;
	tmp = s1->top->value;
	node = create_node(tmp);
	append_node(s2, node);
	remove_node(s1);
	write(1, str, 3);
}

void	rotate_stack(t_stack *stack, char *str)
{
	t_node	*top;
	t_node	*bottom;
	t_node	*tmp;

	if (stack->size < 2)
		return ;
	top = stack->top;
	bottom = stack->bottom;
	tmp = top->next;
	top->next = NULL;
	top->prev = bottom;
	bottom->next = top;
	tmp->prev = NULL;
	stack->top = tmp;
	stack->bottom = top;
	write(1, str, 3);
}

void	reverse_rotate_stack(t_stack *stack, char *str)
{
	t_node	*top;
	t_node	*bottom;
	t_node	*tmp;

	if (stack->size < 2)
		return ;
	top = stack->top;
	bottom = stack->bottom;
	tmp = bottom->prev;
	bottom->next = top;
	bottom->prev = NULL;
	top->prev = bottom;
	tmp->next = NULL;
	stack->top = bottom;
	stack->bottom = tmp;
	write(1, str, 4);
}
