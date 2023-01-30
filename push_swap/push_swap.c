/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yejinkim <yejinkim@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/09 21:01:41 by yejinkim          #+#    #+#             */
/*   Updated: 2023/01/30 22:39:07 by yejinkim         ###   ########seoul.kr  */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	print_error(t_stack *a, t_stack *b)
{	
	write(1, "Error\n", 6);
	free_stack(a, b);
}

void	free_stack(t_stack *a, t_stack *b)
{
	if (a)
	{
		while (a->top)
			remove_node(a);
		free(a);
	}
	if (b)
	{
		while (b->top)
			remove_node(b);
		free(b);
	}
	exit(0);
}

void	index_arr(t_stack *stack, int *arr)
{
	int		i;
	int		j;
	t_node	*node;

	i = 0;
	node = stack->top;
	while (i < stack->size)
	{
		j = 0;
		while (j < stack->size)
		{
			if (arr[j] == node->value)
			{
				node->value = j;
				break ;
			}
			j++;
		}
		node = node->next;
		i++;
	}
	free(arr);
}

int	*copy_stack(t_stack *stack)
{
	int		i;
	int		*arr;
	t_node	*node;

	i = 0;
	arr = malloc(sizeof(int) * stack->size);
	if (!arr)
		free_stack(stack, NULL);
	node = stack->top;
	while (node)
	{
		arr[i] = node->value;
		node = node->next;
		i++;
	}
	return (arr);
}

int	main(int argc, char **argv)
{
	t_stack	*a;
	t_stack	*b;
	int		*arr;

	a = init_stack();
	b = init_stack();
	if (!a || !b)
		exit(0);
	parse_arg(a, argc - 1, argv);
	arr = copy_stack(a);
	quick_sort(arr, 0, a->size - 1);
	check_sort(a, arr);
	index_arr(a, arr);
	sort_stack(a, b);
	return (0);
}
