/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_arg.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yejinkim <yejinkim@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/26 15:30:02 by yejinkim          #+#    #+#             */
/*   Updated: 2023/01/30 20:00:19 by yejinkim         ###   ########seoul.kr  */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	check_overflow(long result, long sign)
{
	if (result * sign < (long)-2147483648)
		return (0);
	else if (result * sign > (long)2147483647)
		return (-1);
	return (1);
}

void	check_num(char *str)
{
	int	i;

	i = 0;
	while (str[i])
	{
		if (!((str[i] >= '0' && str[i] <= '9') || \
			(str[i] == '+' || str[i] == '-') || \
			((str[i] >= 9 && str[i] <= 13) || str[i] == ' ')))
			print_error(NULL, NULL);
		i++;
	}
}

void	check_sort(t_stack *stack, int *arr)
{
	t_node	*node;
	int		i;
	int		chk;

	i = 0;
	chk = 0;
	node = stack->top;
	while (i < stack->size)
	{
		if (arr[i] == node->value)
			chk++;
		i++;
		node = node->next;
	}
	if (chk == stack->size)
		free_stack(stack, NULL);
}

void	check_duplicate(t_stack *stack)
{
	t_node	*node;
	t_node	*tmp;
	int		chk;

	node = stack->top;
	while (node)
	{
		chk = 0;
		tmp = stack->top;
		while (tmp)
		{
			if (node->value == tmp->value)
				chk++;
			tmp = tmp->next;
		}
		if (chk > 1)
			print_error(stack, NULL);
		node = node->next;
	}
}
