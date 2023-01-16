/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yejinkim <yejinkim@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/09 21:01:41 by yejinkim          #+#    #+#             */
/*   Updated: 2023/01/16 22:48:23 by yejinkim         ###   ########seoul.kr  */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"
#include <stdio.h>

void PrintList(t_node* node) {
    if(node == NULL) printf("빈 리스트\n");
    else {
        while(node != NULL) {
            printf("%d\n", node->value);
            node = node->prev;
        }
    }
}

int	main(int argc, char **argv)
{
	t_stack	*a;
	t_stack	*b;
    t_node	*node;
	
	a = init_stack();
	b = init_stack();
	node = NULL;
	for(int i=1; i<argc; i++)
	{
		node = create_node(atoi(argv[i]));
		append_node(a, node);
	}

	PrintList(a->top);
	printf("-----\n");
	revers_rotate_stack(a);
	PrintList(a->top);

	return (0);
}
