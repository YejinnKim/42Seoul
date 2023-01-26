/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yejinkim <yejinkim@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/09 21:01:41 by yejinkim          #+#    #+#             */
/*   Updated: 2023/01/26 23:30:16 by yejinkim         ###   ########seoul.kr  */
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

int	check_overflow(long result, long sign)
{
	if (result * sign < (long)-2147483648)
		return (0);
	else if (result * sign > (long)2147483647)
		return (-1);
	return (1);
}

int	ft_atoi(const char *str)
{
	long	i;
	long	sign;
	long	result;

	i = 0;
	sign = 1;
	result = 0;
	while ((str[i] >= 9 && str[i] <= 13) || str[i] == ' ')
		i++;
	if (str[i] == '+' || str[i] == '-')
	{
		if (str[i] == '-')
			sign *= -1;
		i++;
	}
	while (str[i] >= '0' && str[i] <= '9')
	{
		result = result * 10 + (str[i] - '0');
		i++;
	}
	return ((int)result * (int)sign);
}

int	main(int argc, char **argv)
{
	t_stack	*a;
	t_stack	*b;
    t_node	*node;
	int		i;

	a = init_stack();
	b = init_stack();
	node = NULL;
	i = argc - 1;
	
	while (i > 0)
	{
		node = create_node(atoi(argv[i]));
		append_node(a, node);
		i--;
	}
	
	index_arr(a);
	// print(a, b);
	a_to_b(a, b);
	b_to_a(a, b);

	return (0);
}
