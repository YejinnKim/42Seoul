/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_stack.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yejinkim <yejinkim@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/26 14:44:49 by yejinkim          #+#    #+#             */
/*   Updated: 2023/01/27 23:38:27 by yejinkim         ###   ########seoul.kr  */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"
#include <stdio.h>

void	a_to_b(t_stack *a, t_stack *b, int chunk)
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
		if(node->value == max)
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
		node = node->next;
		i++;
	}
}

void	b_to_a(t_stack *a, t_stack *b)
{
	while (b->size != 0)
	{
		max_top(b);
		push_stack(b, a, "pa\n");
	}
}

void	sort_three(t_stack *a, int size)
{
	int top;
	int bottom;

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

void	push_b(t_stack *a, t_stack *b, int size)
{
	while (a->size > 3)
	{
		if (a->top->value == 0)
			push_stack(a, b, "pb\n");
		else if (a->top->value == 1 && size == 5)
			push_stack(a, b, "pb\n");
		else
			rotate_stack(a, "ra\n");
	}
}

void	push_a(t_stack *a, t_stack *b)
{
	if (b->size == 2 && b->top->value == 0)
	{
		swap_stack(b, "sb\n");
		push_stack(b, a, "pa\n");
	}	
	else if (b->size == 2 && b->top->value == 1)
		push_stack(b, a, "pa\n");
	push_stack(b, a, "pa\n");
}

void	sort_stack(t_stack *a, t_stack *b)
{
	int chunk;
	int size;

	check_duplicate(a);
	index_arr(a);
	size = a->size;
	if (size == 2)
		swap_stack(a, "sa\n");
	else if (size < 6)
	{
		push_b(a, b, size);
		sort_three(a, size);
		push_a(a, b);
	}
	else
	{
		if (size < 500)
			chunk = 15;
		else
			chunk = 30;
		a_to_b(a, b, chunk);
		b_to_a(a, b);
	}	
}
