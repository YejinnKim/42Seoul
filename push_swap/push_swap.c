/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yejinkim <yejinkim@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/09 21:01:41 by yejinkim          #+#    #+#             */
/*   Updated: 2023/01/27 23:38:38 by yejinkim         ###   ########seoul.kr  */
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

void	print_error(void)
{
	printf("Error\n");
	exit(0);
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
		if (check_overflow(result, sign) < 1)
			print_error();
	}
	return ((int)result * (int)sign);
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
			print_error();
		i++;
	}
}

int	*parse_arg(char *argv, int cnt)
{
	int	*result;
	char **tmp;
	int i;

	i = 0;
	check_num(argv);
	tmp = ft_split(argv);
	result = malloc(sizeof(int *) * cnt);
	cnt--;
	while (cnt >= 0)
	{
		result[cnt] = ft_atoi(tmp[i]);
		i++;
		cnt--;
	}
	return (result);
}

int	main(int argc, char **argv)
{
	t_stack	*a;
	t_stack	*b;
    t_node	*node;
	int		i;
	int		j;
	int		*tmp;
	int		cnt;

	a = init_stack();
	b = init_stack();
	node = NULL;
	i = argc - 1;
	while (i > 0)
	{
		cnt = count_word(argv[i], ' ');
		tmp = parse_arg(argv[i], cnt);
		j = 0;
		while (j < cnt)
		{
			node = create_node(tmp[j]);
			append_node(a, node);
			j++;
		}
		i--;
	}
	sort_stack(a, b);

	//print(a, b);

	return (0);
}
