/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yejinkim <yejinkim@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/09 21:01:41 by yejinkim          #+#    #+#             */
/*   Updated: 2023/01/21 22:34:08 by yejinkim         ###   ########seoul.kr  */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"
#include <stdio.h>

void print(t_stack *a_stack, t_stack *b_stack)
{
	t_node *a = a_stack->top;
	t_node *b = b_stack->top;
	printf("A B\n");
	if (a_stack->size > b_stack->size)
	{
		while (a != NULL)
		{
			if (b != NULL)
			{
				printf("%d %d\n", a->value, b->value);
				a = a->next;
				b = b->next;
			}
			else
			{
				printf("%d\n", a->value);
				a = a->next;
			}
		}
	}
	else
	{
		while (b != NULL)
		{
			if (a != NULL)
			{
				printf("%d %d\n", a->value, b->value);
				a = a->next;
				b = b->next;
			}
			else
			{
				printf("  %d\n", b->value);
				b = b->next;
			}
		}
	}
}

int	main(int argc, char **argv)
{
	t_stack	*a;
	t_stack	*b;
    t_node	*node;
	
	a = init_stack();
	b = init_stack();
	node = NULL;
	for(int i=argc-1; i>0; i--)
	{
		node = create_node(atoi(argv[i]));
		append_node(a, node);
	}

	print(a, b);
	push_stack(a, b);
	reverse_rotate_stack(a);
	reverse_rotate_stack(a);

	print(a, b);

	return (0);
}
