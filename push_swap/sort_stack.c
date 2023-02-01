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

void	move_top(t_stack *stack, int i)
{
	if (stack->size / 2 < i)
	{
		while (++i <= stack->size)
		{
			if (stack->name == 'a')
				reverse_rotate_stack(stack, "rra\n");				
			else if (stack->name == 'b')
				reverse_rotate_stack(stack, "rrb\n");				
		}
	}
	else
	{
		while (--i >= 0)
		{
			if (stack->name == 'a')
				rotate_stack(stack, "ra\n");
			else if (stack->name == 'b')
				rotate_stack(stack, "rb\n");
		}
	}
}

void	target_top(t_stack *stack, int target, int max)
{
	int		i;
	t_node	*node;

	i = 0;
	node = stack->top;
	while (node != NULL)
	{
		if ((max && (node->value == target)) || (!max && (node->value <= target)))
		{
			move_top(stack, i);
			return ;
		}
		node = node->next;
		i++;
	}
}

void	push_a(t_stack *a, t_stack *b)
{
	while (b->size != 0)
	{
		target_top(b, b->size - 1, 1);
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
			target_top(a, i+chunk, 0);
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
	print_cmd("end");
	free_stack(a, b);
}
