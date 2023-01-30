/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_arg.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yejinkim <yejinkim@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/30 17:09:38 by yejinkim          #+#    #+#             */
/*   Updated: 2023/01/30 21:26:57 by yejinkim         ###   ########seoul.kr  */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

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
			print_error(NULL, NULL);
	}
	return ((int)result * (int)sign);
}

void	swap_arr(int *arr, int i, int j)
{
	int	tmp;

	tmp = arr[i];
	arr[i] = arr[j];
	arr[j] = tmp;
}

void	quick_sort(int *arr, int start, int end)
{
	int	pivot;
	int	i;
	int	j;

	if (start >= end)
		return ;
	pivot = start;
	i = pivot + 1;
	j = end;
	while (i <= j)
	{
		while (i <= end && arr[i] <= arr[pivot])
			++i;
		while (j > start && arr[j] >= arr[pivot])
			--j;
		if (i >= j)
			break ;
		swap_arr(arr, i, j);
	}
	swap_arr(arr, j, pivot);
	quick_sort(arr, start, j - 1);
	quick_sort(arr, j + 1, end);
}

int	*split_arg(char *argv, int cnt)
{
	int		*result;
	char	**tmp;
	int		i;

	i = 0;
	tmp = ft_split(argv);
	result = malloc(sizeof(int *) * cnt);
	if (!result)
		exit(0);
	cnt--;
	while (cnt >= 0)
	{
		result[cnt] = ft_atoi(tmp[i]);
		i++;
		cnt--;
	}
	i = 0;
	while (tmp[i])
		free(tmp[i++]);
	free(tmp);
	return (result);
}

void	parse_arg(t_stack *stack, int argc, char **argv)
{
	int		i;
	int		*tmp;
	int		cnt;
	t_node	*node;

	while (argc > 0)
	{
		check_num(argv[argc]);
		cnt = count_word(argv[argc]);
		tmp = split_arg(argv[argc], cnt);
		i = 0;
		while (i < cnt)
		{
			node = create_node(tmp[i]);
			if (!node)
				free_stack(stack, NULL);
			append_node(stack, node);
			i++;
		}
		free(tmp);
		argc--;
	}
	check_duplicate(stack);
}
