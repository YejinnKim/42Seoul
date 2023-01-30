/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_stack.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yejinkim <yejinkim@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/26 14:44:49 by yejinkim          #+#    #+#             */
/*   Updated: 2023/01/30 22:38:07 by yejinkim         ###   ########seoul.kr  */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"
#include <stdio.h>

void	top_push(t_stack *b, t_node *node, int max, int i)
{
	if (node->value == max)
	{
		if ((int)(b->size / 2) < i)
		{
			while (i < b->size)
			{
				reverse_rotate_stack(b, "rrb\n");
				i++;
			}
			return ;
		}
		else
		{
			while (i > 0)
			{
				rotate_stack(b, "rb\n");
				i--;
			}
			return ;
		}
	}
}

void	max_top(t_stack *b)
{
	int		i;
	int		max;
	t_node	*node;

	i = 0;
	max = b->size - 1;
	node = b->top;
	while (node != NULL)
	{
		top_push(b, node, max, i);
		node = node->next;
		i++;
	}
}

void	push_a(t_stack *a, t_stack *b)
{
	while (b->size != 0)
	{
		max_top(b);
		push_stack(b, a, "pa\n");
	}
}

void	push_b(t_stack *a, t_stack *b, int chunk)
{
	int	i;

	i = 0;
	while (a->size != 0)
	{
		if (a->top->value <= i)
		{
			push_stack(a, b, "pb\n");
			i++;
		}
		else if (a->top->value > i && a->top->value <= i + chunk)
		{
			push_stack(a, b, "pb\n");
			rotate_stack(b, "rb\n");
			i++;
		}
		else if (a->top->value > i + chunk)
		{
			if (a->size / 2 < i)
				rotate_stack(a, "ra\n");
			else
				reverse_rotate_stack(a, "rra\n");
		}
	}
}

void	sort_stack(t_stack *a, t_stack *b)
{
	int	chunk;
	int	size;

	size = a->size;
	if (size == 2)
		swap_stack(a, "sa\n");
	else if (size < 6)
	{
		push_b_min(a, b, size);
		sort_three(a, size);
		push_a_min(a, b);
	}
	else
	{
		if (size < 500)
			chunk = 15;
		else
			chunk = 30;
		push_b(a, b, chunk);
		push_a(a, b);
	}
	free_stack(a, b);
}
