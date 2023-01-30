/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yejinkim <yejinkim@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/11 20:56:43 by yejinkim          #+#    #+#             */
/*   Updated: 2023/01/30 21:27:05 by yejinkim         ###   ########seoul.kr  */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

size_t	ft_strlcpy(char *dst, const char *src, size_t dstsize)
{
	size_t	i;
	size_t	len;

	i = 0;
	len = 0;
	while (src[len])
		len++;
	if (!dstsize || (dst == src))
		return (len);
	while (src[i] && i + 1 < dstsize)
	{
		dst[i] = src[i];
		i++;
	}
	dst[i] = '\0';
	return (len);
}

int	count_word(const char *str)
{
	int	i;
	int	cnt;

	i = 0;
	cnt = 0;
	while (str[i])
	{
		if (str[i] != ' ' && (str[i + 1] == ' ' || str[i + 1] == '\0'))
			cnt++;
		i++;
	}
	return (cnt);
}

int	check_arr(char **arr, int idx)
{
	int	i;

	i = 0;
	if (!arr[idx])
	{
		while (arr[i])
		{
			free(arr[i]);
			i++;
		}
		free(arr);
		return (1);
	}
	else
		return (0);
}

void	malloc_word(char **arr, char const *str)
{
	int	idx;
	int	i;
	int	j;

	idx = 0;
	i = 0;
	while (str[i])
	{
		if (str[i] == ' ')
			i++;
		else
		{
			j = 1;
			while (str[i + j] != ' ' && str[i + j])
				j++;
			arr[idx] = (char *)malloc(sizeof(char) * (j + 1));
			if (check_arr(arr, idx))
				return ;
			ft_strlcpy(arr[idx], &str[i], j + 1);
			idx++;
			i += j;
		}
	}
	arr[idx] = 0;
}

char	**ft_split(char *s)
{
	char	**arr;

	if (!s)
		return (0);
	arr = (char **)malloc(sizeof(char *) * (count_word(s) + 1));
	if (!arr)
		exit(0);
	malloc_word(arr, s);
	return (arr);
}
