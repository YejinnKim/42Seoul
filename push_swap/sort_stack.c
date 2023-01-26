/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_stack.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yejinkim <yejinkim@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/26 14:44:49 by yejinkim          #+#    #+#             */
/*   Updated: 2023/01/26 23:06:46 by yejinkim         ###   ########seoul.kr  */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"
#include <stdio.h>

void	a_to_b(t_stack *a, t_stack *b)
{
	int	i;
	int	chunk;

	chunk = 15;
	i = 0;
	while (a->size != 0)
	{
		if (a->top->value <= i)
		{
			push_stack(a, b);
			printf("pb\n");
			i++;
		}
		else if (a->top->value > i && a->top->value <= i + chunk)
		{
			push_stack(a, b);
			printf("pb\n");
			rotate_stack(b);
			printf("rb\n");
			i++;
		}
		else if (a->top->value > i + chunk)
		{
			if (a->size / 2 < i)
			{
				rotate_stack(a);
				printf("ra\n");
			}
			else
			{
				reverse_rotate_stack(a);
				printf("rra\n");\
			}
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
					reverse_rotate_stack(b);
					printf("rrb\n");
					i++;
				}
				return ;
			}
			else
			{
				while (i > 0)
				{
					rotate_stack(b);
					printf("rb\n");
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
		push_stack(b, a);
		printf("pa\n");
	}
}
