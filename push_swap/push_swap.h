/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yejinkim <yejinkim@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/09 21:23:25 by yejinkim          #+#    #+#             */
/*   Updated: 2023/01/30 22:39:17 by yejinkim         ###   ########seoul.kr  */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include <stdlib.h>
# include <unistd.h>

typedef struct s_node
{
	int				value;
	struct s_node	*prev;
	struct s_node	*next;
}	t_node;

typedef struct s_stack
{
	t_node	*top;
	t_node	*bottom;
	int		size;
	char	name;
}	t_stack;

t_stack	*init_stack(char name);
t_node	*create_node(int value);
void	append_node(t_stack *stack, t_node *new_node);
void	remove_node(t_stack *stack);
void	swap_stack(t_stack *stack, char *str);
void	push_stack(t_stack *s1, t_stack *s2, char *str);
void	rotate_stack(t_stack *stack, char *str);
void	reverse_rotate_stack(t_stack *stack, char *str);
int		*copy_stack(t_stack *stack);
void	index_arr(t_stack *stack, int *arr);
void	free_stack(t_stack *a, t_stack *b);
void	print_error(t_stack *a, t_stack *b);
void	parse_arg(t_stack *stack, int argc, char **argv);
int		*split_arg(char *argv, int cnt);
void	quick_sort(int *arr, int start, int end);
void	swap_arr(int *arr, int i, int j);
int		ft_atoi(const char *str);
char	**ft_split(char *s);
size_t	ft_strlcpy(char *dst, const char *src, size_t dstsize);
size_t	ft_strlen(const char *s);
int		ft_strcmp(const char *s1, const char *s2);
size_t	ft_strcpy(char *dst, const char *src);
int		count_word(const char *str);
void	check_duplicate(t_stack *stack);
void	check_sort(t_stack *stack, int *arr);
void	check_num(char *str);
int		check_overflow(long result, long sign);
void	sort_stack(t_stack *a, t_stack *b);
void	push_b(t_stack *a, t_stack *b, int chunk);
void	push_a(t_stack *a, t_stack *b);
void	target_top(t_stack *stack, int target, int max);
void	move_top(t_stack *stack, int i);
void	push_a_min(t_stack *a, t_stack *b);
void	push_b_min(t_stack *a, t_stack *b, int size);
void	sort_three(t_stack *a, int size);
int		count_index(t_stack *a);
void	print_cmd(char *str);
void	cmd_check(char *prev, char *str);

#endif