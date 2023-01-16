/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stack_utils.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yejinkim <yejinkim@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/10 16:48:29 by yejinkim          #+#    #+#             */
/*   Updated: 2023/01/16 22:26:53 by yejinkim         ###   ########seoul.kr  */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

t_stack *init_stack(void)
{
	t_stack	*stack;
	stack = (t_stack *)malloc(sizeof(t_stack));
	stack->top = NULL;
	stack->bottom = NULL;
	stack->size = 0;
	return (stack);
}

t_node *create_node(int value)
{
	t_node *node;

	node = (t_node *)malloc(sizeof(t_node));
	node->value = value;
	node->prev = NULL;
	node->next = NULL;
	return (node);
}

void append_node(t_stack* stack, t_node* new_node) 
{
    t_node* tmp;

    if(stack->top == NULL)
	{
        stack->top = new_node;
		stack->bottom = new_node;
	}
    else 
	{
        tmp = stack->top;
        tmp->next = new_node;
        new_node->prev = tmp;
        stack->top = new_node;
    }
    stack->size++;
}

void remove_node(t_stack *stack) 
{
    t_node* top;
    t_node* tmp;

	top = stack->top;
	tmp = stack->top->prev;
    if(top == NULL) return;
	else if (!tmp)
		stack->top = NULL;
    else
	{
		tmp->next = NULL;
        stack->top = tmp;
    }
    stack->size--;
    free(top);
}
