/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_five.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yejinkim <yejinkim@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/30 17:12:17 by yejinkim          #+#    #+#             */
/*   Updated: 2023/01/30 17:26:49 by yejinkim         ###   ########seoul.kr  */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	sort_three(t_stack *a, int size)
{
	int	top;
	int	bottom;

	top = a->top->value - (size - 3);
	bottom = a->bottom->value - (size - 3);
	if (top == 0 && bottom == 1)
	{
		swap_stack(a, "sa\n");
		rotate_stack(a, "ra\n");
	}
	else if (top == 1 && bottom == 2)
		swap_stack(a, "sa\n");
	else if (top == 1 && bottom == 0)
		reverse_rotate_stack(a, "rra\n");
	else if (top == 2 && bottom == 1)
		rotate_stack(a, "ra\n");
	else if (top == 2 && bottom == 0)
	{
		rotate_stack(a, "ra\n");
		swap_stack(a, "sa\n");
	}
}

int	count_index(t_stack *a)
{
	int		i;
	t_node	*tmp;

	i = 0;
	tmp = a->top;
	while (tmp)
	{
		if (tmp->value == 0 || tmp->value == 1)
			break ;
		i++;
		tmp = tmp->next;
	}
	return (i);
}

void	push_b_min(t_stack *a, t_stack *b, int size)
{
	while (a->size > 3)
	{
		if (a->top->value == 0)
			push_stack(a, b, "pb\n");
		else if (a->top->value == 1 && size == 5)
			push_stack(a, b, "pb\n");
		else
		{
			if (count_index(a) > size / 2)
				reverse_rotate_stack(a, "rra\n");
			else
				rotate_stack(a, "ra\n");
		}
	}
}

void	push_a_min(t_stack *a, t_stack *b)
{
	if (b->size == 2 && b->top->value == 0)
		swap_stack(b, "sb\n");
	if (b->size == 2)
		push_stack(b, a, "pa\n");
	push_stack(b, a, "pa\n");
}
