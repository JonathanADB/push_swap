/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stack_ops_utils.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jonadomi <jonadomi@student.42urduliz.com>  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/02 18:45:46 by jonadomi          #+#    #+#             */
/*   Updated: 2026/02/02 18:46:29 by jonadomi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

t_node	*pop_top(t_node **stack)
{
	t_node	*top;

	if (!stack || !*stack)
		return (NULL);
	top = *stack;
	*stack = (*stack)->next;
	top->next = NULL;
	return (top);
}

void	push_top(t_node **stack, t_node *node)
{
	if (!node)
		return ;
	node->next = *stack;
	*stack = node;
}
