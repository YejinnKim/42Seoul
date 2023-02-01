/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap_utils.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yejinkim <yejinkim@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/16 16:23:50 by yejinkim          #+#    #+#             */
/*   Updated: 2023/01/30 20:20:03 by yejinkim         ###   ########seoul.kr  */
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
	print_cmd(str);
}

void	push_stack(t_stack *s1, t_stack *s2, char *str)
{
	int		tmp;
	t_node	*node;

	if (s1->size < 1)
		return ;
	tmp = s1->top->value;
	node = create_node(tmp);
	if (!node)
		free_stack(s1, s2);
	append_node(s2, node);
	remove_node(s1);
	print_cmd(str);
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
	print_cmd(str);
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
	print_cmd(str);
}

void	print_cmd(char *str)
{
	static char	*prev;

	if (!prev)
	{
		prev = malloc(sizeof(char) * 5);
		prev[0] = '\0';
	}
	if (!prev[0])
		ft_strcpy(prev, str);
	else
		cmd_check(prev, str);
	if (!ft_strcmp(prev, "end"))
		free(prev);
}
