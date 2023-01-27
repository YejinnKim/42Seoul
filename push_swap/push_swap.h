/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yejinkim <yejinkim@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/09 21:23:25 by yejinkim          #+#    #+#             */
/*   Updated: 2023/01/27 21:58:22 by yejinkim         ###   ########seoul.kr  */
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
}	t_stack;

t_stack *init_stack(void);
t_node	*create_node(int value);
void	append_node(t_stack* stack, t_node* new_node) ;
void	remove_node(t_stack *stack);
void	swap_stack(t_stack *stack, char *str);
void	push_stack(t_stack *s1, t_stack *s2, char *str);
void	rotate_stack(t_stack *stack, char *str);
void	reverse_rotate_stack(t_stack *stack, char *str);
void	a_to_b(t_stack *a, t_stack *b, int chunk);
void	b_to_a(t_stack *a, t_stack *b);
void	index_arr(t_stack *stack);
char	**ft_split(char *s);
int		count_word(const char *str, char c);
void	print_error(void);
void	check_duplicate(t_stack *stack);
void	check_sort(t_stack *stack, int *arr);
void	sort_stack(t_stack *a, t_stack *b);

#endif