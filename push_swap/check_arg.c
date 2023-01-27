/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_arg.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yejinkim <yejinkim@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/26 15:30:02 by yejinkim          #+#    #+#             */
/*   Updated: 2023/01/27 20:22:00 by yejinkim         ###   ########seoul.kr  */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	swap_arr(int *arr, int i, int j)
{
	int	tmp;

	tmp = arr[i];
	arr[i] = arr[j];
	arr[j] = tmp;
}

void quick_sort(int *arr, int start, int end)
{
	int	pivot;
	int	i;
	int	j;

	if(start >= end) //분할된 원소가 0개이거나 1개 일때까지 함수 호출 
		return;
	pivot = start; //피봇은 첫 번째 원소 
	i = pivot + 1; //i는 피봇 다음원소 
	j = end; //j는 마지막 원소 
	while(i<=j)
	{
		while(i<=end && arr[i]<=arr[pivot]) //피봇 보다 큰 값 만날 때 까지
			++i;
		while(j>start && arr[j]>=arr[pivot]) //피봇 보다 작은 값 만날 때 까지
			--j;
		if(i>=j) //위에서 계산된 i와 j가 만나거나 엇갈리면 종료
			break;
		swap_arr(arr, i, j); //두 원소 교환 
	}
	swap_arr(arr, j, pivot); //피봇 정렬 완료 
	quick_sort(arr, start, j-1); //피봇 중심으로 왼쪽부분 분할
	quick_sort(arr, j+1, end); //피봇 중심으로 오른쪽부분 분할
}

void	index_arr(t_stack *stack)
{
	int	i;
	int	j;
	int	*arr;
	t_node *node;

	i = 0;
	arr = malloc(sizeof(int) * stack->size);
	if (!arr)
		return ;
	node = stack->top;
	while (node)
	{
		arr[i] = node->value;
		node = node->next;
		i++;
	}
	quick_sort(arr, 0, stack->size - 1);
	check_sort(stack, arr);
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
				break;
			}
			j++;
		}
		node = node->next;
		i++;
	}
	free(arr);
}

void	check_sort(t_stack *stack, int *arr)
{
	t_node	*node;
	int	i;
	int chk;

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
		exit(0);
}

void	check_duplicate(t_stack *stack)
{
	t_node	*node;
	t_node	*tmp;
	int	chk;

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
			print_error();
		node = node->next;
	}
}