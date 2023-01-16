/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap_utils.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yejinkim <yejinkim@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/16 16:23:50 by yejinkim          #+#    #+#             */
/*   Updated: 2023/01/16 22:48:00 by yejinkim         ###   ########seoul.kr  */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	swap_stack(t_stack *stack)
{
	t_node	*top;
	t_node	*tmp;

	if (stack->size < 2)
		return ;
	top = stack->top;
	tmp = stack->top->prev;
	top->prev = tmp->prev;
	top->next = tmp;
	tmp->prev = top;
	tmp->next = NULL;
	tmp->prev->next = top;
	stack->top = tmp;
}

void	push_stack(t_stack *s1, t_stack *s2)
{
	int		tmp;
	t_node	*node;

	if (s1->size < 1)
		return ;
	tmp = s1->top->value;
	node = create_node(tmp);
	append_node(s2, node);
	remove_node(s1);
}

void	rotate_stack(t_stack *stack)
{
	t_node	*top;
	t_node	*bottom;
	t_node	*tmp;

	if (stack->size < 2)
		return ;
	top = stack->top;
	bottom = stack->bottom;
	tmp = top->prev;
	top->prev = NULL;
	top->next = bottom;
	bottom->prev = top;
	tmp->next = NULL;
	stack->top = tmp;
	stack->bottom = top;
}

void	revers_rotate_stack(t_stack *stack)
{
	t_node	*top;
	t_node	*bottom;
	t_node	*tmp;

	if (stack->size < 2)
		return ;
	top = stack->top;
	bottom = stack->bottom;
	tmp = bottom->next;
	bottom->prev = top;
	bottom->next = NULL;
	top->next = bottom;
	tmp->prev = NULL;
	stack->top = bottom;
	stack->bottom = tmp;
}
